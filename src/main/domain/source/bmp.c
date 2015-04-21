#include "domain/include/bmp.h"
#include "infrastructure/include/math.h"
#include "infrastructure/include/file.h"

unsigned long BmpGetBmpHeader(FILE* bmpFile, BitmapFileHeader* bmpHeader){
	readFile(bmpFile, sizeof(BitmapFileHeader), bmpHeader);
	return 0;
}

unsigned long BmpGetFileSize(const BitmapFileHeader* bmpHeader){
	return _4bytesToULong(bmpHeader->fileSize);
}


#if 0

Bmp::Bmp(const char* bmpFile){
	openFile(bmpFile, FMODE_READ_ONLY, &(this->fileHandle_));
	readFile(this->fileHandle_, sizeof(this->bitmapHeader_), &(this->bitmapHeader_));
}

unsigned long Bmp::getFileSize(void) const{
	return fileSize(this->fileHandle_);
}

void Bmp::setFileSize(const unsigned long fileSize){
	_ULongTo4Bytes(fileSize, this->bitmapHeader_.fileSize);	
}

#endif

