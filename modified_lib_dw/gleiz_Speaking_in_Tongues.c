#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
char table[256] = {0};
char buffer1[10240];
char buffer2[10240];
size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
char *new_fgets(char *str, int num, FILE *stream);
int main(int argc, char *argv[])
{
  int first_iteration;
  FILE *pin = new_fopen("a.p", "r");
  FILE *ein = new_fopen("a.e", "r");
  for (int i = 0; i < 256; i++)
  {
    table[i] = '@';
  }

  while (new_fgets(buffer1, sizeof(buffer1), pin) != 0)
  {
    new_fgets(buffer2, sizeof(buffer2), ein);
    int len = new_strlen(buffer1);
    for (int i = 0; i < (len - 1); i++)
    {
      table[buffer1[i]] = buffer2[i];
    }

  }

  new_fclose(pin);
  new_fclose(ein);
  table['q'] = 'z';
  table['z'] = 'q';
  int cas = 1;
  int num = 0;
  scanf("%d", &num);
  gets(buffer2);
  while (new_fgets(buffer1, sizeof(buffer1), stdin) != 0)
  {
    int len = new_strlen(buffer1);
    for (int i = len - 1; i >= 0; i--)
    {
      if ((buffer1[i] == '\r') || (buffer1[i] == '\n'))
      {
        buffer1[i] = 0;
        len--;
      }

    }

    printf("Case #%d: ", cas++);
    for (int i = 0; i < len; i++)
    {
      printf("%c", table[buffer1[i]]);
    }

    printf("\n");
  }

  return 0;
}

size_t new_strlen(const char *str);
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
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

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


