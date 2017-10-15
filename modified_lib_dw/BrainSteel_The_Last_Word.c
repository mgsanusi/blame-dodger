#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include <stddef.h>
void *new_malloc(size_t size);
void new_free(void *ptr);
int main()
{
  int first_iteration;
  long num;
  long iii;
  scanf(" %ld", &num);
  for (iii = 0; iii < num; iii++)
  {
    char *S = new_malloc((sizeof(char)) * (15 + 1));
    scanf(" %[A-Z]", S);
    char *buf = new_malloc((sizeof(char)) * ((15 * 2) + 2));
    char *ptr = buf + 15;
    char *leftptr = ptr;
    char *rightptr = ptr;
    *ptr = *S;
    int i;
    for (i = 1; i < strlen(S); i++)
    {
      if (S[i] >= (*leftptr))
      {
        leftptr--;
        *leftptr = S[i];
      }
      else
      {
        rightptr++;
        *rightptr = S[i];
      }

    }

    rightptr++;
    *rightptr = '\0';
    printf("Case #%ld: %s\n", iii + 1, leftptr);
    new_free(S);
    new_free(buf);
  }

  return 0;
}

void *new_malloc(size_t size);
void new_free(void *ptr)
{
  int first_iteration;
  return free(ptr);
}

void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}


