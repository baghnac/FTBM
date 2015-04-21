#ifndef __EBMP_H__
#define __EBMP_H__

#include "domain/include/bmp.h"

#ifdef __cplusplus
extern "C" {
#endif

unsigned long SetEBmpFlag(BitmapFileHeader*);
unsigned char IsEBmpFile(const BitmapFileHeader*);

#ifdef __cplusplus
}
#endif

#endif

