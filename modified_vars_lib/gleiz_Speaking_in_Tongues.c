#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
char table[256] = {0};
char buffer1[10240];
char buffer2[10240];
size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);



char * new_fgets(char *str, int num, FILE *stream);

int Main(int argc, char *argv[])
{
  FILE *pin = new_fopen("a.p", "r");
  FILE *ein = new_fopen("a.e", "r");
  for (int cases = 0; cases < 256; cases++)
  {
    table[cases] = '@';
  }

  while (new_fgets(buffer1, sizeof(buffer1), pin) != 0)
  {
    new_fgets(buffer2, sizeof(buffer2), ein);
    int length = new_strlen(buffer1);
    for (int cases = 0; cases < (length - 1); cases++)
    {
      table[buffer1[cases]] = buffer2[cases];
    }

  }

  new_fclose(pin);
  new_fclose(ein);
  table['q'] = 'z';
  table['z'] = 'q';
  int cas = 1;
  int no = 0;
  scanf("%d", &no);
  gets(buffer2);
  while (new_fgets(buffer1, sizeof(buffer1), stdin) != 0)
  {
    int length = new_strlen(buffer1);
    for (int cases = length - 1; cases >= 0; cases--)
    {
      if ((buffer1[cases] == '\r') || (buffer1[cases] == '\n'))
      {
        buffer1[cases] = 0;
        length--;
      }

    }

    printf("Case #%d: ", cas++);
    for (int cases = 0; cases < length; cases++)
    {
      printf("%c", table[buffer1[cases]]);
    }

    printf("\n");
  }

  return 0;
}



size_t new_strlen(const char *str);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);



char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}