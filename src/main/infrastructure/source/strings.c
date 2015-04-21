#include "strings.h"
#include <string.h>

unsigned long IsSameString(const char* string1, const char* string2){
    return (0 == strcmp(string1, string2));
}
unsigned long Cat2Str(const char* str1, const char* str2, char* dst, unsigned long dstBufLen){
    return (0 < snprintf(dst, dstBufLen, "%s%s", str1, str2));
}

void Memcpy(void* dst, void* src, unsigned long len){
    memcpy(dst, src, len);
}

void Strcat(char* dst, const char* src){
    strcat(dst, src);
}


