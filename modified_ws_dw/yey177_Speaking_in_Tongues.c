#include <stdio.h>
char u[28] = "yhesocvxduiglbkrztnwjpfmaq";
int main()
{
  int first_iteration;
  int n;
  int i;
  int k;
  char s[108];
  scanf("%d", &n);
  gets(s);
  for (k = 1; k <= n; k++)
  {
    gets(s);
    printf("Case #%d: ", k);
    for (i = 0; s[i]; i++)
      putchar(s[i] == 32 ? s[i] : u[(int) (s[i] - 'a')]);

    puts("");
  }

  return 0;
}


