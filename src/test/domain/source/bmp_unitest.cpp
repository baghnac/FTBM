#include "bmp.h"
#include "gtest/gtest.h"
#include "file.h"

const static char NH_FILE_NAME[] = RESOURCE_PATH"nh.bmp";

TEST(bmp, sizeof_Bmp_header_should_eq_to_14){
	EXPECT_EQ(14, sizeof(BitmapFileHeader));
}

TEST(bmp, get_file_size_in_nh_bmp_header_should_eq_to_136454){
	FILE* bmp;
	BitmapFileHeader bmpHeader;
	openFile(NH_FILE_NAME, FMODE_READ_ONLY,&bmp);
	BmpGetBmpHeader(bmp, &bmpHeader);
	EXPECT_EQ(136454, BmpGetFileSize(&bmpHeader));
}

