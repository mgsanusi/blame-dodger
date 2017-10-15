#include<stdio.h>
void intSort(int d[], int s)
{
  int first_iteration;
  int i;
  int j;
  int key;
  int t;
  if (s <= 1)
    return;

  key = (d[0] + d[s - 1]) / 2;
  i = -1;
  j = s;
  for (;;)
  {
    while (d[++i] < key)
      ;

    while (d[--j] > key)
      ;

    if (i >= j)
      break;

    t = d[i];
    d[i] = d[j];
    d[j] = t;
  }

  intSort(d, i);
  intSort((d + j) + 1, (s - j) - 1);
}

int main()
{
  int first_iteration;
  int i;
  int j;
  int k;
  int l;
  int m;
  int n;
  int t;
  int a_n;
  int b_n;
  int a_st[200];
  int a_ed[200];
  int b_st[200];
  int b_ed[200];
  int a;
  int b;
  int c;
  int d;
  int a_s;
  int b_s;
  int a_use;
  int b_use;
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d", &t);
    scanf("%d%d", &a_n, &b_n);
    for (i = 0; i < a_n; i++)
    {
      scanf("%d:%d", &j, &k);
      a_st[i] = (j * 60) + k;
      scanf("%d:%d", &j, &k);
      a_ed[i] = ((j * 60) + k) + t;
    }

    for (i = 0; i < b_n; i++)
    {
      scanf("%d:%d", &j, &k);
      b_st[i] = (j * 60) + k;
      scanf("%d:%d", &j, &k);
      b_ed[i] = ((j * 60) + k) + t;
    }

    a_s = (b_s = 0);
    a_use = (b_use = 0);
    intSort(a_st, a_n);
    intSort(a_ed, a_n);
    intSort(b_st, b_n);
    intSort(b_ed, b_n);
    a_st[a_n] = (a_ed[a_n] = (b_st[b_n] = (b_ed[b_n] = 100000)));
    a = (b = (c = (d = 0)));
    for (;;)
    {
      t = 100000;
      if (a_st[a] < t)
        t = a_st[a];

      if (a_ed[b] < t)
        t = a_ed[b];

      if (b_st[c] < t)
        t = b_st[c];

      if (b_ed[d] < t)
        t = b_ed[d];

      if (t == 100000)
        break;

      if (a_ed[b] == t)
      {
        b++;
        b_s++;
        continue;
      }

      if (b_ed[d] == t)
      {
        d++;
        a_s++;
        continue;
      }

      if (a_st[a] == t)
      {
        a++;
        if (a_s)
          a_s--;
        else
          a_use++;

        continue;
      }

      if (b_st[c] == t)
      {
        c++;
        if (b_s)
          b_s--;
        else
          b_use++;

        continue;
      }

    }

    printf("Case #%d: %d %d\n", ++count, a_use, b_use);
  }

  return 0;
}


