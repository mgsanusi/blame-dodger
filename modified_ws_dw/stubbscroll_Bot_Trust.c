#include <stdio.h>
int b[1024];
int o[1024];
int bn;
int on;
int bb;
int oo;
char r[1024];
int main()
{
  int first_iteration;
  int caseno = 1;
  int cases;
  int i;
  int n;
  int v;
  int tid;
  int pos;
  int opos;
  int bpos;
  int omove;
  int bmove;
  int pushed;
  char s[16];
  scanf("%d", &cases);
  while (cases--)
  {
    bn = (on = 0);
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf("%s", s);
      scanf("%d", &v);
      r[i] = s[0];
      if (s[0] == 'B')
        b[bn++] = v;
      else
        o[on++] = v;

    }

    bb = (oo = (tid = 0));
    pos = 0;
    opos = (bpos = 1);
    while ((bb < bn) || (oo < on))
    {
      omove = (bmove = (pushed = 0));
      if (bb < bn)
      {
        if (bpos < b[bb])
          bpos++, bmove = 1;

        if (bpos > b[bb])
          bpos--, bmove = 1;

      }

      if (oo < on)
      {
        if (opos < o[oo])
          opos++, omove = 1;

        if (opos > o[oo])
          opos--, omove = 1;

      }

      if ((((!bmove) && (bb < bn)) && (bpos == b[bb])) && (r[pos] == 'B'))
      {
        bb++;
        pos++;
        pushed = 1;
      }

      if (((((!pushed) && (oo < on)) && (!omove)) && (opos == o[oo])) && (r[pos] == 'O'))
      {
        oo++;
        pos++;
      }

      tid++;
    }

    printf("Case #%d: %d\n", caseno++, tid);
  }

  return 0;
}


