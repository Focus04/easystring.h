#include <stddef.h>

void *memcpy(void *dest, const void *src, size_t n)
{
  char *d = (char *)dest;
  const char *s = (char *)src;
  for (size_t i = 0; i < n; i++)
    *(d + i) = *(s + i);
  return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
  char *d = (char *)dest;
  const char *s = (char *)src;
  if (dest <= src)
    for (size_t i = 0; i < n; i++)
      *(d + i) = *(s + i);
  else
    for (size_t i = n; i; i--)
      *(d + i - 1) = *(s + i - 1);
  return dest;
}

void *memchr(const void *str, int c, size_t n)
{
  const char *s = (char *)str;
  for (size_t i = 0; i < n; i++)
    if (*(s + i) == c)
      return (void *)(s + i);
  return NULL;
}

int memcmp(const void *buf1, const void *buf2, size_t n)
{
  size_t i;
  int diff, pp;
  const char *s1 = (char *)buf1;
  const char *s2 = (char *)buf2;
  for (i = 0, diff = 0, pp = 0; i < n && !pp; i++)
  {
    diff = *(s1 + i) - *(s2 + i);
    if (*(s1 + i) != *(s2 + i))
      pp = 1;
  }
  return diff;
}

void *memset(void *dest, int c, size_t n)
{
  size_t i;
  const char k = (char)c;
  char *d = (char *)dest;
  for (i = 0; i < n; i++)
    *(d + i) = k;
  return (void *)d;
}

char *strcat(char *dest, const char *src)
{
  size_t len, i;
  for (i = 0, len = 0; *(dest + i) != '\0'; i++)
    len++;
  for (i = 0; *(src + i) != '\0'; i++)
    *(dest + len + i) = *(src + i);
  *(dest + len + i) = '\0';
  return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
  size_t i, len;
  for (i = 0, len = 0; *(dest + i) != '\0'; i++)
    len++;
  for (i = 0; *(src + i) != '\0' && i < n; i++)
    *(dest + len + i) = *(src + i);
  *(dest + len + i) = '\0';
  return dest;
}

char *strchr(const char *src, int c)
{
  size_t len, i;
  char *s = (char *)src;
  const char k = (char)c;
  for (i = 0, len = 0; *(src + i) != '\0'; i++)
    len++;
  for (i = 0; i <= len; i++)
    if (*(s + i) == k)
      return s + i;
  return NULL;
}

char *strrchr(const char *src, int c)
{
  size_t len, i;
  char *s = (char *)src;
  const char k = (char)c;
  for (i = 0, len = 0; *(src + i) != '\0'; i++)
    len++;
  for (i = len; i > (size_t)-1; i++)
    if (*(s + i) == k)
      return s + i;
  return NULL;
}

int strcmp(const char *ptr1, const char *ptr2)
{
  int i, diff, pp;
  for (i = 0, diff = 0, pp = 0; !pp; i++)
  {
    diff = *(ptr1 + i) - *(ptr2 + i);
    if (*(ptr1 + i) != *(ptr2 + i))
      pp = 1;
  }
  return diff;
}

int strncmp(const char *ptr1, const char *ptr2, size_t n)
{
  size_t i;
  int diff, pp;
  for (i = 0, diff = 0, pp = 0; !pp && i < n; i++)
  {
    diff = *(ptr1 + i) - *(ptr2 + i);
    if (*(ptr1 + i) != *(ptr2 + i))
      pp = 1;
  }
  return diff;
}

char *strcpy(char *dest, const char *src)
{
  size_t i, len;
  for (i = 0, len = 0; *(src + i) != '\0'; i++)
    len++;
  for (i = 0; i <= len; i++)
    *(dest + i) = *(src + i);
  return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
  size_t i, len;
  for (i = 0, len = 0; *(src + i) != '\0'; i++)
    len++;
  for (i = 0; i < n; i++)
  {
    if (i < len)
      *(dest + i) = *(src + i);
    else
      *(dest + i) = '0';
  }
  return dest;
}

size_t strlen(const char *s)
{
  size_t len, i;
  for (i = 0, len = 0; *(s + i) != '\0'; i++)
    len++;
  return len;
}

size_t strspn(const char *str1, const char *str2)
{
  size_t i, j;
  int pp1, pp2;
  for (i = 0, pp1 = 0; *(str1 + i) != '\0' && !pp1; i++)
  {
    for (j = 0, pp2 = 0; *(str2 + j) != '\0' && !pp2; j++)
      if (*(str1 + i) == *(str2 + j))
        pp2 = 1;
    if (!pp2)
      pp1 = 1;
  }
  return i - 1;
}

size_t strcspn(const char *str1, const char *str2)
{
  size_t i, j;
  int pp1;
  for (i = 0, pp1 = 0; *(str1 + i) != '\0' && !pp1; i++)
    for (j = 0; *(str2 + j) != '\0'; j++)
      if (*(str1 + i) == *(str2 + j))
        pp1 = 1;
  return i - 1;
}

char *strpbrk(const char *str1, const char *str2)
{
  int i, j;
  int pp1;
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  for (i = 0, pp1 = 0; *(s1 + i) != '\0' && !pp1; i++)
    for (j = 0; *(s2 + j) != '\0'; j++)
      if (*(s1 + i) == *(s2 + j))
        pp1 = 1;
  if (!pp1)
    return NULL;
  return s1 + i - 1;
}

char *strstr(const char *str1, const char *str2)
{
  int i, j, k, pp1, pp2;
  char *s1 = (char *)str1;
  char *s2 = (char *)str2;
  for (i = 0, pp2 = 0; *(s1 + i) != '\0' && !pp2; i++)
  {
    for (j = 0, k = i, pp1 = 0; *(s2 + j) != '\0' && !pp1; j++, k++)
      if (*(s1 + k) != *(s2 + j))
        pp1 = 1;
    if (!pp1)
      pp2 = 1;
  }
  if (!pp2)
    return NULL;
  return s1 + i - 1;
}

char *strtok(char *str, const char *sep)
{
  int i, j, pp;
  static char *last;
  if (!str)
    str = last;
  for (i = 0, pp = 0; *(str + i) != '\0' && !pp; i++)
  {
    for (j = 0; *(sep + j) != '\0'; j++)
      if (*(str + i) == *(sep + j))
      {
        *(str + i) = '\0';
        pp = 1;
      }
    if (*(str + i + 1) == '\0')
      pp = 1;
  }
  if (pp)
  {
    last = str + i;
    return str;
  }
  return NULL;
}