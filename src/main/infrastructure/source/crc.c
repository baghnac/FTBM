#include "infrastructure/include/hash.h"

unsigned short crc16(char* buffer, unsigned int bufferLen)
{
	unsigned short crc = 0;
	unsigned char ucDa;
	unsigned short acrc_ta[16]={0x0000,0x1021,0x2042,0x3063,0x4084,0x50a5,0x60c6,0x70e7,0x8108,0x9129,0xa14a,0xb16b,0xc18c,0xd1ad,0xe1ce,0xf1ef};
	while(bufferLen--!=0)
	{
		ucDa=((unsigned char)(crc/256))/16; /* \u6682\u5b58CRC \u7684\u9ad8\u56db\u4f4d */
		crc<<=4; /* CRC \u53f3\u79fb4 \u4f4d\uff0c\u76f8\u5f53\u4e8e\u53d6CRC \u7684\u4f4e12 \u4f4d\uff09*/
		crc^=acrc_ta[ucDa^(*buffer/16)]; /* CRC \u7684\u9ad84 \u4f4d\u548c\u672c\u5b57\u8282\u7684\u524d\u534a\u5b57\u8282\u76f8\u52a0\u540e\u67e5\u8868\u8ba1\u7b97CRC\uff0c\u7136\u540e\u52a0\u4e0a\u4e0a\u4e00\u6b21CRC \u7684\u4f59\u6570 */
		ucDa=((unsigned char)(crc/256))/16; /* \u6682\u5b58CRC \u7684\u9ad84 \u4f4d */
		crc<<=4; /* CRC \u53f3\u79fb4 \u4f4d\uff0c \u76f8\u5f53\u4e8eCRC \u7684\u4f4e12 \u4f4d\uff09 */
		crc^=acrc_ta[ucDa^(*buffer&0x0f)]; /* CRC \u7684\u9ad84 \u4f4d\u548c\u672c\u5b57\u8282\u7684\u540e\u534a\u5b57\u8282\u76f8\u52a0\u540e\u67e5\u8868\u8ba1\u7b97CRC\uff0c\u7136\u540e\u518d\u52a0\u4e0a\u4e0a\u4e00\u6b21CRC \u7684\u4f59\u6570 */
		buffer++;
	}
	return(crc);
}


