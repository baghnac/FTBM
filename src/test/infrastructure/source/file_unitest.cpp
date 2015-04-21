#include "file.h"
#include "gtest/gtest.h"

char testFile[] = RESOURCE_PATH"nh.bmp"; 

TEST(File, open_a_normal_exist_file_should_return_0){
	FILE* fileHandle;
	EXPECT_EQ(0, openFile(testFile,FMODE_READ_ONLY,&fileHandle));
}

TEST(File, file_size_of_nh_bmp_should_eq_to_136454){
	FILE* fileHandle;
	FILE* outFile;
	char outFileName[] = RESOURCE_PATH"nh.2.bmp";
	openFile(testFile,FMODE_READ_ONLY,&fileHandle);
	openFile(outFileName, FMODE_WRITE_ONLY, &outFile);
	writeFileToFile(fileHandle, 32, 32, outFile);
	EXPECT_EQ(136454, fileSize(fileHandle));
}

TEST(File, two_bytes_read_from_nh_bmp_should_eq_to_BM){
	FILE* fileHandle;
	unsigned char _2bytes[2] = {0};
	unsigned long result = -1;
	openFile(testFile,FMODE_READ_ONLY,&fileHandle);
	result = readFile(fileHandle, 2, _2bytes);
	EXPECT_EQ(0, result);
	EXPECT_EQ('B', _2bytes[0]);
	EXPECT_EQ('M', _2bytes[1]);
}

TEST(File, write_4bytes_to_new_file_should_success){
	unsigned char _4bytes[4] = {'A', 'B', 'C', 'D'};
	FILE* fileHandle = NULL;
	char outFile[] = RESOURCE_PATH"testWriteFile.bin";
	openFile(outFile, FMODE_WRITE_ONLY, &fileHandle);
	writeBuffToFile(_4bytes, sizeof(_4bytes), fileHandle);
	EXPECT_EQ(4, fileSize(fileHandle));
}
