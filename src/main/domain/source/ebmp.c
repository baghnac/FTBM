#include "domain/include/ebmp.h"
#include "infrastructure/include/file.h"

const static char EBMP_FLAG[]={'E','B','M',0};

unsigned long SetEBmpFlag(BitmapFileHeader* bmpHeader){
	unsigned long loop = 0;
	for(loop = 0; loop < 4; loop++){
		bmpHeader->reserved[loop] = EBMP_FLAG[loop];
	}
	return 0;
}

unsigned char IsEBmpFile(const BitmapFileHeader* bmpHeader){
    return ((EBMP_FLAG[0] == bmpHeader->reserved[0])
          &&(EBMP_FLAG[1] == bmpHeader->reserved[1])
          &&(EBMP_FLAG[2] == bmpHeader->reserved[2]));
}


