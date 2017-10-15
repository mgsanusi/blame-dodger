#include <stdio.h>
#include <string.h>
int ti;
int cas;
int atB;
char str[10000];
char out[10000];
char outa[10000];
char outb[10000];
int Main()
{
  fscanf(stdin, "%d", &cas);
  for (ti = 1; ti <= cas; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%s", str);
    for (atB = 0; str[atB]; ++atB)
    {
      strncpy(outa, out, atB);
      outa[atB] = str[atB];
      outa[atB + 1] = 0;
      strncpy(outb + 1, out, atB);
      outb[0] = str[atB];
      outb[atB + 1] = 0;
      if (strcmp(outa, outb) >= 0)
      {
        strcpy(out, outa);
      }
      else
      {
        strcpy(out, outb);
      }

    }

    fprintf(stdout, "%s\n", out);
  }

}


