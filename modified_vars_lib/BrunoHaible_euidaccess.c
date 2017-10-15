#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
void new_exit(int status);

int new_atoi(const char *str);



void new_exit(int status);

int new_atoi(const char *str) {
  return atoi(str);
}
void new_exit(int status) {
  return exit(status);
}