#include "application/include/encryption.h"
#include "domain/include/bmp.h"
#include "domain/include/ebmp.h"
#include "infrastructure/include/file.h"
#include "infrastructure/include/hash.h"
#include "infrastructure/include/strings.h"
#include "application/include/common.h"


static FILE* srcFile, *maskFile, *dstFile;
static unsigned long srcSize, maskSize, dstSize;
static BitmapFileHeader bmpHeader;

static void OpenAllFile(const char*, const char*, const char*);
static void SetEBmpFlagToBmpHeader(void);
static void WriteMaskFileToDst(void);
static void WriteEBmpHeader(void);
static void WriteSrcFileToDst(const char*);
static unsigned long JundgeResult(void);

unsigned long encryption(char* src, char* mask, char* password, char* dst){
    char* hashPwd = HashPassword(password);
	OpenAllFile(src, mask, dst);
	SetEBmpFlagToBmpHeader();
	WriteMaskFileToDst();
	WriteEBmpHeader();
	WriteSrcFileToDst(hashPwd);
	return JundgeResult();
}

static void OpenAllFile(const char* src, const char* mask, const char* dst){
	openFile(src, FMODE_READ_ONLY, &srcFile);
	openFile(mask, FMODE_READ_ONLY, &maskFile);
	openFile(dst, FMODE_WRITE_ONLY, &dstFile);
}

static void SetEBmpFlagToBmpHeader(void){
	readFile(maskFile, sizeof(bmpHeader), &bmpHeader);
	SetEBmpFlag(&bmpHeader);
}

static void WriteMaskFileToDst(void){
	maskSize = fileSize(maskFile);
	writeBuffToFile((void*)&bmpHeader, sizeof(bmpHeader), dstFile);
	writeFileToFile(maskFile, sizeof(bmpHeader), maskSize - sizeof(bmpHeader), dstFile);
}

static void WriteEBmpHeader(void){
    unsigned char ebmpHeader[4] = {4, 0, 0, 0};
    _ULongTo4Bytes(4, ebmpHeader);
    writeBuffToFile(ebmpHeader, 4, dstFile);
}


static void WriteSrcFileToDst(const char* hashPwd){
    unsigned char temp = 0;
    unsigned long loop = 0;
	srcSize = fileSize(srcFile);
    for(loop = 0; loop < srcSize; loop++){
        readFile(srcFile, 1,&temp);
        if(NULL != hashPwd){
            temp += hashPwd[loop % HASH_PWD_LEN];
        }
        writeBuffToFile(&temp, 1, dstFile);
    }
}

static unsigned long JundgeResult(void){
	dstSize = fileSize(dstFile);
	closeAllFile();
	if(dstSize == (srcSize + maskSize + 4)){
		return 0;
	}
	return dstSize;
}
