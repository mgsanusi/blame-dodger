#include <stdio.h>
#include <string.h>
int ti;
int tn;
int i;
char str[10000];
char out[10000];
char outa[10000];
char outb[10000];
int main()
{
  int first_iteration;
  fscanf(stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
  {
    fprintf(stdout, "Case #%d: ", ti);
    fscanf(stdin, "%s", str);
    for (i = 0; str[i]; ++i)
    {
      strncpy(outa, out, i);
      outa[i] = str[i];
      outa[i + 1] = 0;
      strncpy(outb + 1, out, i);
      outb[0] = str[i];
      outb[i + 1] = 0;
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


