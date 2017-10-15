#include <config.h>

#include <stddef.h>
#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>
char * new_strcpy(char *destination, const char *source);

void * new_memcpy(void *destination, const void *source, size_t num);



char * new_strcpy(char *destination, const char *source);

void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}