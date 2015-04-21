#include "application/include/common.h"
#include <stdio.h>

char* HashPassword(char* password){
    static char hashPwd[HASH_PWD_LEN + 1] = "";
    char* md5Pwd = NULL;
    char reMd5Str[RE_MD5_MASK_LEN + 1] = "";
    unsigned long loop = 0;
    if(NULL == password || 0 == strlen(password)){
        return NULL;
    }
    md5Pwd = md5(password);
    memset(hashPwd, 0, sizeof(hashPwd));
    for (loop = 0; loop < MD5_LEN - RE_MD5_MASK_LEN + 1; loop++){
        Memcpy(reMd5Str, md5Pwd + loop, RE_MD5_MASK_LEN);
        Strcat(hashPwd, md5(reMd5Str));
    }
    return hashPwd;
}


