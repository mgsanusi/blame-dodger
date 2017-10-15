#include<stdio.h>
const char map[] = {121, 104, 101, 115, 111, 99, 118, 120, 100, 117, 105, 103, 108, 98, 107, 114, 122, 116, 110, 119, 106, 112, 102, 109, 97, 113};
char *new_fgets(char *str, int num, FILE *stream);
int main(void)
{
  int first_iteration;
  int col;
  char input[102];
  int i;
  int j;
  new_fgets(input, 10, stdin);
  sscanf(input, "%d", &col);
  for (i = 1; i <= col; ++i)
  {
    gets(input);
    for (j = 0; (input[j] != '\n') && (input[j] != '\0'); ++j)
    {
      if (input[j] == ' ')
        continue;

      input[j] = map[input[j] - 'a'];
    }

    input[j] = '\0';
    printf("Case #%d: %s\n", i, input);
  }

  return 0;
}

char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}


