#include "hash.h"
#include "strings.h"
#include "gtest/gtest.h"

char srcStr[] = "abc";

TEST(Hash, md5_of_abc_should_equal_to_900150983cd24fb0d6963f7d28e17f72){
	char expectMD5[] = "900150983cd24fb0d6963f7d28e17f72";
    EXPECT_TRUE(IsSameString(expectMD5, md5(srcStr)));
}

TEST(Hash,crc16_of_abc_should_equal_to_0x9dd6){
    EXPECT_EQ(0x9dd6, crc16(srcStr,3));
}

