#include "math.h"

unsigned long _4bytesToULong(const unsigned char* _4bytes){
	return ( _4bytes[3] * 0x1000000 
			+_4bytes[2] * 0x10000 
			+_4bytes[1] * 0x100
			+_4bytes[0]);
}

void _ULongTo4Bytes(const unsigned long longValue, unsigned char* _4bytes){
	unsigned long temp = longValue;
	unsigned long loop = 0;
	for(loop = 0; loop < 4; loop++) {
		_4bytes[loop] = (char)((temp % 0x100) & 0xFF);
		temp /= 0x100;
	}
}

unsigned short _2bytesToUShort(const unsigned char* _2bytes){
	return ( _2bytes[1] * 0x100 +_2bytes[0]); 
}

void _UShortTo2Bytes(const unsigned short shortValue, unsigned char* _2bytes){
	unsigned short temp = shortValue;
	unsigned long loop = 0;
	for(loop = 0; loop < 2; loop++) {
		_2bytes[loop] = (unsigned char)(temp % 0x100);
		temp /= 0x100;
	}
}

