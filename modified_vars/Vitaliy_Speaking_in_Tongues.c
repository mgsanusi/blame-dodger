#include <stdio.h>
#include <assert.h>
#include <string.h>
char *s = "yhesocvxduiglbkrztnwjpfmaq";
int Main()
{
  int k;
  int proc;
  int cn;
  char auth[1000];
  scanf("%d\n", &k);
  assert(strlen(s) == 26);
  for (proc = 0; proc < k; proc++)
  {
    gets(auth);
    printf("Case #%d: ", proc + 1);
    int tmp = strlen(auth);
    for (cn = 0; cn < tmp; cn++)
    {
      if (auth[cn] == ' ')
      {
        printf(" ");
        continue;
      }

      if ((auth[cn] >= 'a') && (auth[cn] <= 'z'))
      {
        printf("%c", s[auth[cn] - 'a']);
        continue;
      }

      assert((auth[cn] == '\n') || (auth[cn] == '\r'));
    }

    printf("\n");
  }

  return 0;
}


