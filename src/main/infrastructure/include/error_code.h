#ifndef __ERROR_CODE_H__
#define __ERROR_CODE_H__

#define EXIT exit

/********************************************
0x001~0xfff infrastructure error code
*********************************************/
#define ERR_READ_FILE_FAILED (unsigned long)0x0001
#define ERR_WRITE_FILE_FAILED (unsigned long)0x0002
#define ERR_FILE_SEEK_FAILED (unsigned long)0x0003

/********************************************
0x1000~0xffff domain error code
*********************************************/
#define ERR_NOT_A_EBMP (unsigned long)0x1000


#endif

