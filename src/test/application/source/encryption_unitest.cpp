#include "encryption.h"
#include "gtest/gtest.h"

const static char MASK_FILE[] = RESOURCE_PATH"mask.nh.bmp";
const static char SRC_FILE[] = RESOURCE_PATH"carryFile.txt";
const static char DST_FILE[] = RESOURCE_PATH"outfile.ebmp.bmp";

TEST(encryption, encrypt_one_file_should_return_0){
	EXPECT_EQ(0, encryption(SRC_FILE, MASK_FILE, "password", DST_FILE));
}


