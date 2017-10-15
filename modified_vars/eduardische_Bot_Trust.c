#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int Main()
{
  int count;
  int file;
  scanf("%d", &count);
  static int cl_ops[105];
  static int n[105];
  static char data[105];
  int r1;
  int data_footer_html;
  for (file = 0; file < count; file++)
  {
    int n;
    scanf("%d", &n);
    int turns;
    int j;
    char c;
    r1 = 0;
    data_footer_html = 0;
    for (turns = 0; turns < n; turns++)
    {
      scanf(" %c %d", &c, &j);
      j--;
      if (c == 'O')
        data[turns] = 'a';
      else
        data[turns] = 'b';

      if (c == 'O')
      {
        cl_ops[r1] = j;
        r1++;
      }
      else
      {
        n[data_footer_html] = j;
        data_footer_html++;
      }

    }

    if (r1)
      cl_ops[r1] = cl_ops[r1 - 1];
    else
      cl_ops[r1] = 0;

    if (data_footer_html)
      n[data_footer_html] = n[data_footer_html - 1];
    else
      n[data_footer_html] = 0;

    r1 = 0;
    data_footer_html = 0;
    int rslt = 0;
    int posa = 0;
    int posb = 0;
    int k;
    int t2;
    for (turns = 0; turns < n; turns++)
    {
      if (data[turns] == 'a')
      {
        k = abs(cl_ops[r1] - posa) + 1;
        posa = cl_ops[r1];
        r1++;
        rslt += k;
        t2 = abs(n[data_footer_html] - posb);
        if (t2 > k)
          t2 = k;

        if (posb <= n[data_footer_html])
          posb += t2;
        else
          posb -= t2;

      }
      else
      {
        k = abs(n[data_footer_html] - posb) + 1;
        posb = n[data_footer_html];
        data_footer_html++;
        rslt += k;
        t2 = abs(cl_ops[r1] - posa);
        if (t2 > k)
          t2 = k;

        if (posa <= cl_ops[r1])
          posa += t2;
        else
          posa -= t2;

      }

    }

    printf("Case #%d: %d\n", file + 1, rslt);
  }

  return 0;
}


