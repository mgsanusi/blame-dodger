#include <config.h>
#include <stddef.h>
#include <string.h>
char * new_strchr(char *str, int character);



char * new_strchr(char *str, int character) {
  return strchr(str, character);
}