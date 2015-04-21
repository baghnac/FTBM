#include "application/include/decryption.h"
#include "application/include/common.h"
#include "domain/include/ebmp.h"
#include "infrastructure/include/file.h"
#include "infrastructure/include/error_code.h"

static FILE* srcFile, *dstFile;
static unsigned long srcSize, dstSize;
static BitmapFileHeader bmpHeader;

static void OpenAllFile(const char* src, char* dst);
static unsigned long JudgeEBmpValidity(void);
static void GetDstFileSize(void);
static void SaveCarryFile(char*);

unsigned long decryption(char* src, char* password, char* dst){
    char* hashPwd;
    hashPwd = HashPassword(password);
    OpenAllFile(src, dst);
    JudgeEBmpValidity();    
    GetDstFileSize();
    SaveCarryFile(hashPwd);
    closeAllFile();
    return 0;
}

static void OpenAllFile(const char* src, char* dst){
	openFile(src, FMODE_READ_ONLY, &srcFile);
	openFile(dst, FMODE_WRITE_ONLY, &dstFile);
}

static unsigned long JudgeEBmpValidity(void){
    seekFromBegin(srcFile, 0);
    readFile(srcFile, sizeof(bmpHeader), &bmpHeader);
    if(!IsEBmpFile(&bmpHeader)){
        EXIT(ERR_NOT_A_EBMP);
    }
    return 0;
}

static void GetDstFileSize(void){
    unsigned char ebmpHeaderSize[4] = {0};
    unsigned long maskFileOffset = _4bytesToULong(bmpHeader.fileSize);
    seekFromBegin(srcFile, maskFileOffset);
    readFile(srcFile, 4, ebmpHeaderSize);
    srcSize = fileSize(srcFile);
    dstSize = srcSize - maskFileOffset - _4bytesToULong(ebmpHeaderSize);
}

static void SaveCarryFile(char* hashPwd){
    unsigned char temp = 0;
    unsigned long loop = 0;
    seekFromBegin(srcFile, (srcSize - dstSize));
    for(loop = 0; loop < dstSize; loop++){
        readFile(srcFile, 1, &temp);
        if(NULL != hashPwd){
            temp -= hashPwd[loop % HASH_PWD_LEN];
        }
        writeBuffToFile(&temp, 1, dstFile);
    }
}


