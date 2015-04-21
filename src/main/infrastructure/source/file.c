#include "infrastructure/include/file.h"
#include "infrastructure/include/error_code.h"
#include <errno.h>

#define MAX_CACHE_OPEN_FILE_HANDLE 20

typedef struct T_FileHandlePool
{
    unsigned long dwOpenFileNum;                       /* 所有打开文件数 */
    FILE *fileHandle[MAX_CACHE_OPEN_FILE_HANDLE]; /* 文件较少时，不申请内存，减少异常 */
}T_FileHandlePool;

T_FileHandlePool fileHandlePool = {0};

unsigned long openFile(const char* filename, const char* mode, FILE** handle){
    unsigned long loop = 0;
	if(NULL != (*handle = fopen(filename, mode))){
	    for(loop = 0; loop < MAX_CACHE_OPEN_FILE_HANDLE; loop++){
	        if(NULL == fileHandlePool.fileHandle[loop]){
	            fileHandlePool.fileHandle[loop] = *handle;
	            return 0;
	        }
	    }
	}
	return errno;
}

unsigned long fileSize(FILE* handle){
	unsigned long fileSize = 0;
	unsigned long currentPos = ftell(handle);
	fseek(handle, 0, SEEK_END);
	fileSize = ftell(handle);
	fseek(handle, currentPos, SEEK_SET);
	return fileSize;
}

unsigned long readFile(FILE* handle, const unsigned long length, void* outbuf){
	if(NULL == handle || NULL == outbuf){
		printf("readFile: param is NULL!\n");
		return -1;
	}
	if( 0!= fread(outbuf, sizeof(char), length, handle)){
		return ferror(handle);
	}
	return 0;
}

unsigned long writeBuffToFile(const void* buffer, const unsigned long size, FILE* handle){
	return fwrite(buffer, sizeof(char), size, handle);
}

unsigned long writeFileToFile(FILE* srcHandle, const unsigned long beginPos, const unsigned long copyLength, FILE* outFile){
	const unsigned int READ_WRITE_SEG = 1;
	unsigned char temp = 0;
	unsigned long loop = 0;
	if(0 != fseek(srcHandle, beginPos, SEEK_SET)){
		return ERR_FILE_SEEK_FAILED;
	}
	for(loop = 0; loop < copyLength; loop++){
		if(READ_WRITE_SEG != fread(&temp, sizeof(char), READ_WRITE_SEG, srcHandle)){
			return ERR_READ_FILE_FAILED;
		}
		if(READ_WRITE_SEG != fwrite(&temp, sizeof(char), READ_WRITE_SEG, outFile)){
			return ERR_WRITE_FILE_FAILED;
		}
	}
	return 0;
}

unsigned long closeAllFile(void){
    unsigned long loop = 0;
    for(loop = 0; loop < MAX_CACHE_OPEN_FILE_HANDLE; loop++){
        if(fileHandlePool.fileHandle[loop]){
            fclose(fileHandlePool.fileHandle[loop]);
            fileHandlePool.fileHandle[loop] = NULL;
        }
    }
    memset(&fileHandlePool, 0, sizeof(fileHandlePool));
    return 0;
}

unsigned long seekFromBegin(FILE* handle, unsigned long seekPos){
    fseek(handle, seekPos, SEEK_SET);
    return 0;
}

