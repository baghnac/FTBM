#ifndef __FILE_H__
#define __FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>


#define     FMODE_READ_ONLY     "rb"    /* 读写打开一个二进制文件，允许读写数据 */
#define     FMODE_READ_WRITE    "rw+"   /* 读写打开一个文本文件，允许读和写 */
#define     FMODE_WRITE_ONLY    "wb"    /* 只写打开或新建一个二进制文件；只允许写数据 */
#define     FMODE_WRITE_APPAND  "ab+"   /* 读写打开一个二进制文件，允许读或在文件末追加数据 */


unsigned long openFile(const char*, const char*, FILE**);
unsigned long fileSize(FILE*);
unsigned long readFile(FILE*, const unsigned long, void*);
unsigned long writeBuffToFile(const void*, const unsigned long, FILE*);
unsigned long writeFileToFile(FILE*, const unsigned long, const unsigned long, FILE*);
unsigned long closeAllFile(void);
unsigned long seekFromBegin(FILE*, unsigned long);



#ifdef __cplusplus
}
#endif


#endif
