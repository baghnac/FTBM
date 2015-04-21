#include "math.h"
#include "gtest/gtest.h"

const unsigned char _4bytes[4] = {0xD2,0x3,0x45,0};
const unsigned long ulongValue = 0x4503D2;

#define EXPECT_ARRAY_EQ(expected,actual) \
			for(int i = 0; i < sizeof(expected); i++){ \
				EXPECT_EQ(expected[i],actual[i]) << "different at index " << i;}

TEST(Math, 4bytes_of_0xD2_03_45_00_should_convert_to_0x4503D2){
	EXPECT_EQ(ulongValue, _4bytesToULong(_4bytes));
}

TEST(Math, ULong_0x4503D2_should_convert_to_4bytes_0xD2_0x03_0x45_00){
	unsigned char _4bytesTmp[4] = {0};
	_ULongTo4Bytes(ulongValue, _4bytesTmp);
	EXPECT_ARRAY_EQ(_4bytes, _4bytesTmp);
}

const unsigned char _2bytes[2] = {0x12, 0xD3};
const unsigned short ushortValue = 0xD312;

TEST(Math, UShort_0xD312_should_convert_to_2bytes_0x12_0xD3){
	unsigned char _2bytesTmp[2] = {0};
	_UShortTo2Bytes(ushortValue, _2bytesTmp);
	EXPECT_ARRAY_EQ(_2bytes, _2bytesTmp);
}

TEST(Math, 2bytes_of_0x12_D3_should_convert_to_0xD312){
	EXPECT_EQ(ushortValue, _2bytesToUShort(_2bytes));
}

