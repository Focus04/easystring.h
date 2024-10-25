#include <stddef.h>
#include "mystring.c"

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memchr(const void *str, int c, size_t n);
int memcmp(const void *buf1, const void *buf2, size_t n);
void *memset(void *dest, int c, size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
char *strchr(const char *src, int c);
char *strrchr(const char *src, int c);
int strcmp(const char *ptr1, const char *ptr2);
int strncmp(const char *ptr1, const char *ptr2, size_t n);
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
size_t strlen(const char *s);
size_t strspn(const char *str1, const char *str2);
size_t strcspn(const char *str1, const char *str2);
char *strpbrk(const char *str1, const char *str2);
char *strstr(const char *str1, const char *str2);
char *strtok(char *str, const char *sep);