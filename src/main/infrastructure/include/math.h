#ifndef __MATH_H__
#define __MATH_H__

#ifdef __cplusplus
extern "C" {
#endif

unsigned long _4bytesToULong(const unsigned char*);
void _ULongTo4Bytes(const unsigned long, unsigned char*);

unsigned short _2bytesToUShort(const unsigned char*);
void _UShortTo2Bytes(const unsigned short, unsigned char*);

#ifdef __cplusplus
}
#endif


#endif

