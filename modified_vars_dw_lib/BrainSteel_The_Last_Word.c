#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#include <stddef.h>
void* new_malloc(int size);

void new_free(void *ptr);

int Main()
{
  int first_iteration;
  long no;
  long iii;
  scanf(" %ld", &no);
  for (iii = 0; iii < no; iii++)
  {
    char *s = new_malloc((sizeof(char)) * (15 + 1));
    scanf(" %[A-Z]", s);
    char *buffer = new_malloc((sizeof(char)) * ((15 * 2) + 2));
    char *ptr = buffer + 15;
    char *leftptr = ptr;
    char *rightptr = ptr;
    *ptr = *s;
    int i;
    for (i = 1; i < strlen(s); i++)
    {
      if (s[i] >= (*leftptr))
      {
        leftptr--;
        *leftptr = s[i];
      }
      else
      {
        rightptr++;
        *rightptr = s[i];
      }

    }

    rightptr++;
    *rightptr = '\0';
    printf("Case #%ld: %s\n", iii + 1, leftptr);
    new_free(s);
    new_free(buffer);
  }

  return 0;
}



void* new_malloc(int size);

void new_free(void *ptr) {
  return free(ptr);
}
void* new_malloc(int size) {
  return malloc(size);
}