#ifndef __HASH_H__
#define __HASH_H__

#ifdef __cplusplus
	extern "C" {
#endif


#define MD5_LEN		    32  /* MD5Î»Êý */
char* md5(char*);

unsigned short crc16(char*, unsigned int);

#ifdef __cplusplus
	}
#endif

#endif

