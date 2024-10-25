#include "mystring.h"
#include <stdio.h>

int main()
{
  char string[] = "a string, of, ,tokens\0,after null terminator";
  char *token;

  token = strtok(string, ",");
  while (token)
  {
    printf("token: %s\n", token);
    token = strtok(NULL, ",");
  }
}