#include <config.h>
#include "posixtm.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
time_t new_time(time_t *timer);
char * new_strchr(char *str, int character);


char * new_strcpy(char *destination, const char *source);



time_t new_time(time_t *timer);
char * new_strchr(char *str, int character);


char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
time_t new_time(time_t *timer) {
  return time(timer);
}
char * new_strchr(char *str, int character) {
  return strchr(str, character);
}