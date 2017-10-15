#include <config.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "macros.h"
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream);

void new_free(void *ptr);

char * new_strerror(int errnum);



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream);

void new_free(void *ptr);

char * new_strerror(int errnum) {
  return strerror(errnum);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream);

void new_free(void *ptr) {
  return free(ptr);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}