#include <stdio.h>
int n;
int r;
int y;
int t;
int j;
int nm;
int tmp;
char s[1010];
int new_puts(const char *str);

int btr(int match, int r, int y, int t)
{
  int first_iteration;
  if (match == n)
    return s[n - 1] != s[0];

  if (r && (s[match - 1] != 'R'))
  {
    s[match] = 'R';
    if (btr(match + 1, r - 1, y, t))
      return 1;

  }

  if (y && (s[match - 1] != 'Y'))
  {
    s[match] = 'Y';
    if (btr(match + 1, r, y - 1, t))
      return 1;

  }

  if (t && (s[match - 1] != 'B'))
  {
    s[match] = 'B';
    if (btr(match + 1, r, y, t - 1))
      return 1;

  }

  return 0;
}

void clear()
{
  int first_iteration;
  int rs;
  int accept;
  char good;
  scanf("%d %d %d %d %d %d %d", &n, &r, &j, &y, &nm, &t, &tmp);
  if (((j + nm) + tmp) > 0)
  {
    printf("sanity error\n");
    return;
  }

  s[n] = 0;
  for (rs = 0; (rs < (n - 10)) || (rs < 1); rs++)
  {
    accept = -1;
    good = ' ';
    if (((r >= accept) && r) && ((!rs) || (s[rs - 1] != 'R')))
      accept = r, good = 'R';

    if (((y >= accept) && y) && ((!rs) || (s[rs - 1] != 'Y')))
      accept = y, good = 'Y';

    if (((t >= accept) && t) && ((!rs) || (s[rs - 1] != 'B')))
      accept = t, good = 'B';

    if (good == ' ')
      goto feil;

    s[rs] = good;
    if (good == 'R')
      r--;
    else
      if (good == 'Y')
      y--;
    else
      if (good == 'B')
      t--;



  }

  if (btr(rs, r, y, t))
  {
    for (rs = 0; rs < n; rs++)
      if (s[rs] == s[(rs + 1) % n])
      printf("error");


    new_puts(s);
  }
  else
  {
    feil:
    new_puts("IMPOSSIBLE");

  }

}

int Main()
{
  int first_iteration;
  int t;
  int caseno = 1;
  scanf("%d", &t);
  while (t--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}