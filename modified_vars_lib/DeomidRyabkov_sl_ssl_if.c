#include "common/mg_mem.h"
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);



int new_isspace(int c);

char * new_fgets(char *str, int num, FILE *stream);



size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);



int new_isspace(int c);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);



int new_isspace(int c) {
  return isspace(c);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}