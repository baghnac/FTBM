#include "ebmp.h"
#include "gtest/gtest.h"

const static char EBMP_FLAG[]={'E','B','M',0};
const static char NH_FILE_NAME[] = RESOURCE_PATH"nh.bmp";
FILE* bmpFile;

#if 0
TEST(EBmp, reserved_in_Bmp_header_should_eq_to_EBM){	
	openFile(NH_FILE_NAME, &bmpFile);
	BmpGetBmpHeader(&
	ebmpInit.setEBmpFlag();
	unsigned char ebmpFlag[4] = {0};
	ebmpInit.getEBmpFlag(ebmpFlag);
	for(int loop = 0; loop < 4; loop++){
		EXPECT_EQ(EBMP_FLAG[loop], ebmpFlag[loop]);
	}
}

TEST(EBmp, should_save_as_nh_ebmp){
	char outfile[] = RESOURCE_PATH"nh.ebmp.bmp";
	ebmpInit.saveAs(outfile);
}
#endif
