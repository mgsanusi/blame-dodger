#include <stdio.h>
#include <stdlib.h>
#include <string.h>
size_t new_strlen(const char *str);
char *new_fgets(char *str, int num, FILE *stream);
int new_atoi(const char *str);
void chomp(char *str)
{
  int first_iteration;
  int i = new_strlen(str) - 1;
  while ((str[i] == '\n') || (str[i] == '\r'))
  {
    i--;
  }

  str[i + 1] = 0;
}

void sort(char *str)
{
  int first_iteration;
  int i;
  for (i = 1; i < new_strlen(str); i++)
  {
    int j;
    char c = str[i];
    for (j = i; j > 0; j--)
    {
      if (str[j] < c)
      {
        break;
      }

      str[j] = str[j - 1];
    }

    str[j] = c;
  }

  for (i = 0; i < new_strlen(str); i++)
  {
    if (str[i] != '0')
    {
      char x = str[i];
      str[i] = str[0];
      str[0] = x;
      break;
    }

  }

}

char *do_it(char *perm, int index, char *min)
{
  int first_iteration;
  int i;
  char c = perm[index];
  char *ret = 0;
  if (perm[index + 1] == 0)
  {
    return strdup(perm);
  }

  for (i = index; i < new_strlen(perm); i++)
  {
    char t = perm[i];
    perm[index] = t;
    perm[i] = c;
    char *x = do_it(perm, index + 1, min);
    if (x && (strcmp(x, min) > 0))
    {
      if ((ret == 0) || (strcmp(x, ret) < 0))
        ret = x;

    }

    perm[i] = perm[index];
    perm[index] = c;
  }

  return ret;
}

int main()
{
  int first_iteration;
  int T;
  int i;
  char buf[5] = {0};
  new_fgets(buf, 5, stdin);
  T = new_atoi(buf);
  for (i = 0; i < T; i++)
  {
    char str[25] = {0};
    new_fgets(str, 25, stdin);
    chomp(str);
    char *s = do_it(str, 0, strdup(str));
    if ((!s) || (new_strlen(str) == 1))
    {
      sort(str);
      int j;
      for (j = new_strlen(str); j > 1; j--)
      {
        str[j] = str[j - 1];
      }

      str[1] = '0';
      printf("Case #%d: %s\n", i + 1, str);
    }
    else
    {
      printf("Case #%d: %s\n", i + 1, s);
    }

  }

  return 0;
}

size_t new_strlen(const char *str);
char *new_fgets(char *str, int num, FILE *stream);
int new_atoi(const char *str)
{
  int first_iteration;
  return atoi(str);
}

size_t new_strlen(const char *str);
char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}

size_t new_strlen(const char *str)
{
  int first_iteration;
  return strlen(str);
}


