#include <config.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <stddef.h>
char * new_strchr(char *str, int character);

int new_strncmp(const char *str1, const char *str2, size_t num);



char * new_strchr(char *str, int character);

int new_strncmp(const char *str1, const char *str2, size_t num) {
  return strncmp(str1, str2, num);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}