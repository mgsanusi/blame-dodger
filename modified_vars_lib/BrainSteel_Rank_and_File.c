#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#include <stddef.h>
void* new_malloc(size_t size);

void new_free(void *ptr);

int Main()
{
  long num;
  long iii;
  scanf(" %ld", &num);
  for (iii = 0; iii < num; iii++)
  {
    char *left = new_malloc((sizeof(char)) * (10000 + 1));
    scanf(" %[A-Z]", left);
    char *buff = new_malloc((sizeof(char)) * ((10000 * 2) + 2));
    char *pointer = buff + 10000;
    char *leftptr = pointer;
    char *rightptr = pointer;
    *pointer = *left;
    int niz;
    for (niz = 1; niz < strlen(left); niz++)
    {
      if (left[niz] >= (*leftptr))
      {
        leftptr--;
        *leftptr = left[niz];
      }
      else
      {
        rightptr++;
        *rightptr = left[niz];
      }

    }

    rightptr++;
    *rightptr = '\0';
    printf("Case #%ld: %s\n", iii + 1, leftptr);
    new_free(left);
    new_free(buff);
  }

  return 0;
}



void* new_malloc(size_t size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(size_t size) {
  return malloc(size);
}