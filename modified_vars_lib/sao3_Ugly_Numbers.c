#include <stdio.h>
#include <string.h>
int p;
int l;
char str[1002];
char newstr[1002];
int y[5];
int use[5];
int ans;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void dodo()
{
  int stp;
  int t2;
  int xdrFunc;
  for (stp = 0; stp < l; stp += p)
  {
    for (t2 = 0; t2 < p; t2++)
    {
      newstr[stp + t2] = str[stp + y[t2]];
    }

  }

  xdrFunc = 1;
  for (stp = 1; stp < l; stp++)
  {
    if (newstr[stp] != newstr[stp - 1])
      xdrFunc++;

  }

  if (xdrFunc < ans)
    ans = xdrFunc;

}

void newdiam(int rqClntname)
{
  int stp;
  if (rqClntname == p)
  {
    dodo();
  }
  else
  {
    for (stp = 0; stp < p; stp++)
    {
      if (!use[stp])
      {
        use[stp] = 1;
        y[rqClntname] = stp;
        newdiam(rqClntname + 1);
        use[stp] = 0;
      }

    }

  }

}

void cases()
{
  scanf("%d%s", &p, str);
  ans = 999999;
  memset(use, 0, sizeof(use));
  l = strlen(str);
  newdiam(0);
}

int Main()
{
  int httpRedirect;
  int stp;
  new_freopen("D.in", "r", stdin);
  new_freopen("D.out", "w", stdout);
  scanf("%d", &httpRedirect);
  for (stp = 1; stp <= httpRedirect; stp++)
  {
    cases();
    printf("Case #%d: %d\n", stp, ans);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}