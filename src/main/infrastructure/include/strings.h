#ifndef __STRINGS_H__
#define __STRINGS_H__

#ifdef __cplusplus
	extern "C" {
#endif

void Memcpy(void*, void*, unsigned long);
void Strcat(char*, const char*);
unsigned long IsSameString(const char*, const char*);
unsigned long Cat2Str(const char*, const char*, char*, unsigned long);

#ifdef __cplusplus
	}
#endif

#endif

