#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
char table[256] = {0};
char buffer1[10240];
char buffer2[10240];
int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *pin = fopen("a.p", "r");
  FILE *ein = fopen("a.e", "r");
  for (int cases = 0; cases < 256; cases++)
  {
    table[cases] = '@';
  }

  while (fgets(buffer1, sizeof(buffer1), pin) != 0)
  {
    fgets(buffer2, sizeof(buffer2), ein);
    int length = strlen(buffer1);
    for (int cases = 0; cases < (length - 1); cases++)
    {
      table[buffer1[cases]] = buffer2[cases];
    }

  }

  fclose(pin);
  fclose(ein);
  table['q'] = 'z';
  table['z'] = 'q';
  int cas = 1;
  int no = 0;
  scanf("%d", &no);
  gets(buffer2);
  while (fgets(buffer1, sizeof(buffer1), stdin) != 0)
  {
    int length = strlen(buffer1);
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


