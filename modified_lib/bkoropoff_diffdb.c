/*
** A utility for printing the differences between two SQLite database files.
*/
#include <stdio.h>
#include <ctype.h>

#include <stddef.h>

#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#define PAGESIZE 1024
static int db1 = -1;
static int db2 = -1;
ssize_t new_read(int fd, void *buf, size_t count);
int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);



int main(int argc, char **argv){
  int iPg;
  unsigned char a1[PAGESIZE], a2[PAGESIZE];
  if( argc!=3 ){
    fprintf(stderr,"Usage: %s FILENAME FILENAME\n", argv[0]);
    new_exit(1);
  }
  db1 = open(argv[1], O_RDONLY);
  if( db1<0 ){
    fprintf(stderr,"%s: can't open %s\n", argv[0], argv[1]);
    new_exit(1);
  }
  db2 = open(argv[2], O_RDONLY);
  if( db2<0 ){
    fprintf(stderr,"%s: can't open %s\n", argv[0], argv[2]);
    new_exit(1);
  }
  iPg = 1;
  while( new_read(db1, a1, PAGESIZE)==PAGESIZE && new_read(db2,a2,PAGESIZE)==PAGESIZE ){
    if( new_memcmp(a1,a2,PAGESIZE) ){
      printf("Page %d\n", iPg);
    }
    iPg++;
  }
  printf("%d pages checked\n", iPg-1);
  close(db1);
  close(db2);
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
int new_fprintf(FILE *stream, const char *format, ...);

void new_exit(int status) {
  return exit(status);
}