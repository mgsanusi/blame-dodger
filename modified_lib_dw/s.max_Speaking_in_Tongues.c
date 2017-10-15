#include <stdio.h>
char *new_fgets(char *str, int num, FILE *stream);
int main()
{
  int first_iteration;
  char trans[50] = "yhesocvxduiglbkrztnwjpfmaq";
  char niz[1000];
  int T;
  int tt;
  new_fgets(niz, 1000, stdin);
  sscanf(niz, "%d", &T);
  for (tt = 1; tt <= T; tt++)
  {
    int i;
    new_fgets(niz, 1000, stdin);
    for (i = 0; niz[i]; i++)
      if ((niz[i] != ' ') && (niz[i] != '\n'))
      niz[i] = trans[niz[i] - 'a'];


    printf("Case #%d: %s", tt, niz);
  }

  return 0;
}

char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}


