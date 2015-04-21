#ifndef __COMMON_H__
#define __COMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "infrastructure/include/hash.h"

#define RE_MD5_MASK_LEN 3
#define HASH_PWD_LEN (MD5_LEN * (MD5_LEN - RE_MD5_MASK_LEN + 1))

char* HashPassword(char*);

#ifdef __cplusplus
}
#endif

#endif

