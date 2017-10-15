#include <stdio.h>
#include <stdlib.h>
#include <string.h>
size_t new_strlen(const char *str);

char * new_fgets(char *str, int num, FILE *stream);

int new_atoi(const char *str);

void chomp(char *string)
{
  int len = new_strlen(string) - 1;
  while ((string[len] == '\n') || (string[len] == '\r'))
  {
    len--;
  }

  string[len + 1] = 0;
}

void sort(char *string)
{
  int len;
  for (len = 1; len < new_strlen(string); len++)
  {
    int max;
    char k = string[len];
    for (max = len; max > 0; max--)
    {
      if (string[max] < k)
      {
        break;
      }

      string[max] = string[max - 1];
    }

    string[max] = k;
  }

  for (len = 0; len < new_strlen(string); len++)
  {
    if (string[len] != '0')
    {
      char u = string[len];
      string[len] = string[0];
      string[0] = u;
      break;
    }

  }

}

char *makeIt(char *perm, int index, char *min)
{
  int len;
  char k = perm[index];
  char *ret = 0;
  if (perm[index + 1] == 0)
  {
    return strdup(perm);
  }

  for (len = index; len < new_strlen(perm); len++)
  {
    char ans = perm[len];
    perm[index] = ans;
    perm[len] = k;
    char *u = makeIt(perm, index + 1, min);
    if (u && (strcmp(u, min) > 0))
    {
      if ((ret == 0) || (strcmp(u, ret) < 0))
        ret = u;

    }

    perm[len] = perm[index];
    perm[index] = k;
  }

  return ret;
}

int Main()
{
  int e;
  int len;
  char buff[5] = {0};
  new_fgets(buff, 5, stdin);
  e = new_atoi(buff);
  for (len = 0; len < e; len++)
  {
    char string[25] = {0};
    new_fgets(string, 25, stdin);
    chomp(string);
    char *tmp = makeIt(string, 0, strdup(string));
    if ((!tmp) || (new_strlen(string) == 1))
    {
      sort(string);
      int max;
      for (max = new_strlen(string); max > 1; max--)
      {
        string[max] = string[max - 1];
      }

      string[1] = '0';
      printf("Case #%d: %s\n", len + 1, string);
    }
    else
    {
      printf("Case #%d: %s\n", len + 1, tmp);
    }

  }

  return 0;
}



size_t new_strlen(const char *str);

char * new_fgets(char *str, int num, FILE *stream);

int new_atoi(const char *str) {
  return atoi(str);
}
size_t new_strlen(const char *str);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}