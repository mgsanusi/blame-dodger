#include <stdio.h>
#include <string.h>


int main()
{
  int T;
  scanf("%d", &T);
  for (int tt=1; tt <= T; tt++)
  {
    char curlist[100];
    int cnt = 0;
    char combine[256][256] = { 0 };
    char explode[256][256] = { 0 };
    
    int c;
    scanf("%d ", &c);
    for (int i=0; i<c; i++)
    {
      char s[4];
      scanf("%s", &s);
      combine[s[0]][s[1]] = s[2];
      combine[s[1]][s[0]] = s[2];
    }
    int d;
    scanf("%d", &d);
    for (int i=0; i<d; i++)
    {
      char s[3];
      scanf("%s", &s);
      explode[s[0]][s[1]] = 1;
      explode[s[1]][s[0]] = 1;
    }
    int n;
    char s[101];
    scanf("%d %s", &n, &s);
    for (int i=0; i<n; i++)
    {
      curlist[cnt++] = s[i];
      if (cnt < 2)
        continue;
      char r = combine[curlist[cnt-1]][curlist[cnt-2]];
      if (r != 0)
      {
        cnt -= 2;
        curlist[cnt++] = r;
      }
      else
      {
        for (int j=0; j<cnt-1; j++)
          if (explode[curlist[j]][s[i]])
          {
            cnt = 0;
            break;
          }
      }
    }
    
    printf("Case #%d: [", tt);
    for (int i=0; i<cnt; i++)
    {
      if (i > 0)
        printf(", ");
      printf("%c", curlist[i]);
    }
    printf("]\n");
  }
  return 0;
}
