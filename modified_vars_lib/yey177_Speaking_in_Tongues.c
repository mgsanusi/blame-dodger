#include <stdio.h>
char ti[28] = "yhesocvxduiglbkrztnwjpfmaq";
int new_putchar(int character);

int new_puts(const char *str);

int Main()
{
  int e;
  int i;
  int c;
  char t[108];
  scanf("%d", &e);
  gets(t);
  for (c = 1; c <= e; c++)
  {
    gets(t);
    printf("Case #%d: ", c);
    for (i = 0; t[i]; i++)
      new_putchar(t[i] == 32 ? t[i] : ti[(int) (t[i] - 'a')]);

    new_puts("");
  }

  return 0;
}



int new_putchar(int character);

int new_puts(const char *str) {
  return puts(str);
}
int new_putchar(int character) {
  return putchar(character);
}