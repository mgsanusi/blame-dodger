#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <popt.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void new_exit(int status);

char * new_strerror(int errnum);



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void new_exit(int status);

char * new_strerror(int errnum) {
  return strerror(errnum);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


void new_exit(int status) {
  return exit(status);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}