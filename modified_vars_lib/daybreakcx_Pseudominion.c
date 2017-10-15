#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cc;
int best;
int a[10000][28];
int b[30];
int x1;
int starti;
int i;
int r;
int k;
int ans;
int rsc;
char word[10000][12];
char str[30];
void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));

int cmp(const void *line, const void *t)
{
  int *x = (int *) line;
  int *name = (int *) t;
  int i;
  if (x[27] != name[27])
    return x[27] < name[27] ? -1 : 1;

  for (i = 0; i < 26; ++i)
    if (x[str[i] - 'a'] != name[str[i] - 'a'])
    break;


  if (i == 26)
    return x[26] < name[26] ? -1 : 1;
  else
    return x[str[i] - 'a'] < name[str[i] - 'a'] ? -1 : 1;

}

void match(int s10, int t, int cur, int c_str)
{
  int i;
  if ((cur == 26) || (s10 == t))
  {
    if (((ans == (-1)) || (c_str > rsc)) || ((c_str == rsc) && (a[s10][26] < ans)))
    {
      ans = a[s10][26];
      rsc = c_str;
    }

    return;
  }

  for (i = s10; i <= t; ++i)
    if (a[i][str[cur] - 'a'])
    break;


  if (i == (t + 1))
  {
    match(s10, t, cur + 1, c_str);
    return;
  }

  if (i > s10)
    match(s10, i - 1, cur + 1, c_str + 1);

  for (s10 = i; s10 <= t; s10 = i)
  {
    for (i = s10; (i <= t) && (a[i][str[cur] - 'a'] == a[s10][str[cur] - 'a']); ++i)
      ;

    match(s10, i - 1, cur + 1, c_str);
  }

}

int Main()
{
  scanf("%d", &best);
  for (cc = 1; cc <= best; ++cc)
  {
    printf("Case #%d:", cc);
    scanf("%d%d", &x1, &starti);
    memset(a, 0, sizeof(a));
    for (i = 0; i < x1; ++i)
    {
      scanf("%s", word[i]);
      a[i][26] = i;
      for (a[i][27] = 0; word[i][a[i][27]]; ++a[i][27])
        a[i][word[i][a[i][27]] - 'a'] |= 1 << a[i][27];

    }

    for (i = 0; i < starti; ++i)
    {
      scanf("%s", str);
      for (r = 0; str[r]; ++r)
        b[str[r] - 'a'] = r;

      new_qsort(a, x1, sizeof(a[0]), cmp);
      ans = -1;
      for (r = 0; r < x1; r = k)
      {
        for (k = r; (k < x1) && (a[k][27] == a[r][27]); ++k)
          ;

        match(r, k - 1, 0, 0);
      }

      printf(" %s", word[ans]);
    }

    printf("\n");
  }

  return 0;
}



void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}