#ifndef __BMP_H__
#define __BMP_H__

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1)
/********************************************************************
 * This block of bytes is at the start of the file and is used to   *
 * identify the file. A typical application reads this block first  *
 * to ensure that the file is actually a BMP file and that it is    *
 * not damaged.														*
 ********************************************************************/
typedef struct BitmapFileHeader{
    unsigned char signature[2];    // 0x424D (ASCII BM - Windows 3.1x, 95, NT) 
    unsigned char fileSize[4];
    unsigned char reserved[4];
    unsigned char offsetToPixelArray[4];
}BitmapFileHeader;

#pragma pack()

unsigned long BmpGetBmpHeader(FILE*, BitmapFileHeader*);
unsigned long BmpGetFileSize(const BitmapFileHeader*);

#ifdef __cplusplus
}
#endif
#endif

