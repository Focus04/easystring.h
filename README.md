# mystring.h

The `string.h` library provides a set of functions for common string operations in C. These functions replicate similar functionality to the standard C library string functions, offering manipulation of memory blocks, string concatenation, searching, tokenizing etc.

## Installation
To use the MyString library, include the `mystring.h` header in your C program and link the `mystring.c` implementation.
```c
#include "mystring.h"
```

## Functions and Examples
### 1. `void *memcpy(void *dest, const void *src, size_t n)`
Copies `n` bytes from `src` to `dest`. Returns a pointer to `dest`.
```c
char src[] = "Hello";
char dest[6];
memcpy(dest, src, 6);
printf("%s\n", dest); // Output: Hello
```

### 2. `void *memmove(void *dest, const void *src, size_t n)`
Safely copies `n` bytes from `src` to `dest`, allowing for overlapping regions. Returns a pointer to `dest`.
```c
char str[] = "abcdef";
memmove(str + 2, str, 4);
printf("%s\n", str); // Output: ababcd
```

### 3. `void *memchr(const void *str, int c, size_t n)`
Searches for the first occurrence of `c` in the first `n` bytes of `str`. Returns a pointer to the byte or `NULL` if not found.
```c
char str[] = "hello";
char *ptr = memchr(str, 'e', 5);
printf("%c\n", *ptr); // Output: e
```

### 4. `int memcmp(const void *buf1, const void *buf2, size_t n)`
Compares `n` bytes of `buf1` and `buf2`. Returns `0` if they are equal, a positive value if `buf1` > `buf2`, or a negative value if `buf1` < `buf2`.
```c
char a[] = "abc";
char b[] = "abc";
printf("%d\n", memcmp(a, b, 3)); // Output: 0
```

### 5. `void *memset(void *dest, int c, size_t n)`
Sets the first `n` bytes of `dest` to `c`. Returns a pointer to `dest`.
```c
char buffer[10];
memset(buffer, 'A', 10);
printf("%.*s\n", 10, buffer); // Output: AAAAAAAAAA
```

### 6. `char *strcat(char *dest, const char *src)`
Concatenates `src` to the end of `dest`.
```c
char dest[20] = "Hello, ";
strcat(dest, "world!");
printf("%s\n", dest); // Output: Hello, world!
```

### 7. `char *strncat(char *dest, const char *src, size_t n)`
Appends up to `n` characters from `src` to `dest`.
```c
char dest[20] = "Hello, ";
strncat(dest, "world!!!", 5);
printf("%s\n", dest); // Output: Hello, world
```

### 8. `char *strchr(const char *src, int c)`
Finds the first occurrence of `c` in `src`. Returns a pointer to `c` or `NULL`.
```c
char str[] = "hello";
char *ptr = strchr(str, 'o');
printf("%s\n", ptr); // Output: o
```

## 9. `char *strrchr(const char *src, int c)`
Finds the last occurrence of `c` in `src`. Returns a pointer to `c` or `NULL`.
```c
char str[] = "hello";
char *ptr = strrchr(str, 'l');
printf("%s\n", ptr); // Output: lo
```

### 10. `int strcmp(const char *ptr1, const char *ptr2)`
Compares the strings `ptr1` and `ptr2`. Returns `0` if equal, a positive value if `ptr1` > `ptr2`, or a negative value if `ptr1` < `ptr2`.
```c
char a[] = "hello";
char b[] = "hello";
printf("%d\n", strcmp(a, b)); // Output: 0
```

### 11. `int strncmp(const char *ptr1, const char *ptr2, size_t n)`
Compares up to `n` characters of `ptr1` and `ptr2`. Returns `0` if equal, a positive value if `ptr1` > `ptr2`, or a negative value if `ptr1` < `ptr2`.
```c
char a[] = "hello";
char b[] = "help";
printf("%d\n", strncmp(a, b, 3)); // Output: 0
```

### 12. `char *strcpy(char *dest, const char *src)`
Copies the string `src` to `dest`.
```c
char dest[10];
strcpy(dest, "hello");
printf("%s\n", dest); // Output: hello
```

## 13. `char *strncpy(char *dest, const char *src, size_t n)`
Copies up to `n` characters from `src` to `dest`. Pads with null bytes if `src` is shorter than `n`.
```c
char dest[10];
strncpy(dest, "hello", 10);
printf("%s\n", dest); // Output: hello
```

### 14. `size_t strlen(const char *s)`
Returns the length of `s`.
```c
char str[] = "hello";
printf("%zu\n", strlen(str)); // Output: 5
```

### 15. `size_t strspn(const char *str1, const char *str2)`
Returns the length of the initial segment of `str1` that contains only characters in `str2`.
```c
char str[] = "abcde12345";
printf("%zu\n", strspn(str, "abcde")); // Output: 5
```

### 16. `size_t strcspn(const char *str1, const char *str2)`
Returns the length of the initial segment of `str1` that does not contain any characters from `str2`.
```c
char str[] = "hello, world!";
printf("%zu\n", strcspn(str, ", ")); // Output: 5
```

### 17. `char *strpbrk(const char *str1, const char *str2)`
Finds the first occurrence in `str1` of any character in `str2`. Returns a pointer to the character in `str1`, or `NULL` if none found.
```c
char str[] = "hello";
char *ptr = strpbrk(str, "aeiou");
printf("%c\n", *ptr); // Output: e
```

### 18. `char *strstr(const char *str1, const char *str2)`
Finds the first occurrence of `str2` in `str1`. Returns a pointer to the beginning of `str2` in `str1`, or `NULL` if not found.
```c
char str[] = "hello world";
char *ptr = strstr(str, "world");
printf("%s\n", ptr); // Output: world
```

### 19. `char *strtok(char *str, const char *sep)`
Tokenizes `str` using `sep` as the delimiter. Successive calls with `NULL` continue tokenization.
```c
char str[] = "Hello, world!";
char *token = strtok(str, ", ");
while (token) {
    printf("%s\n", token);
    token = strtok(NULL, ", ");
}
// Output:
// Hello
// world!
```