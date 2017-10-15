#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u awal[33];
u tengah[33];
u akhir[33];
u semua[33];
u sudah[33];
u f[111];
int sbg[33];
int sbgi[33];
char s[111];
int Main()
{
  int first_iteration;
  u a = 0;
  u t;
  u a;
  u i;
  u now_m;
  u a;
  u b;
  for (f[i = 0] = 1; (++i) < 111;)
    f[i] = (i * ((llu) f[i - 1])) % 1000000007u;

  for (scanf("%u", &t); (a++) < t;)
  {
    for (i = 0; i < 33; sbg[i] = (sbgi[i] = -1), i++)
      awal[i] = (tengah[i] = (akhir[i] = (semua[i] = (sudah[i] = 0))));

    for (scanf("%u", &a); a--;)
    {
      scanf("%s", s);
      for (i = 0, now_m = 1; s[++i];)
        if (s[i] != s[i - 1])
        now_m = 0;


      if (now_m)
      {
        semua[s[0] - 'a']++;
        continue;
      }

      awal[s[0] - 'a']++;
      akhir[s[--i] - 'a']++;
      sbg[s[0] - 'a'] = s[i] - 'a';
      sbgi[s[i] - 'a'] = s[0] - 'a';
      while (s[i] == s[i - 1])
        --i;

      while (s[now_m] == s[now_m + 1])
        ++now_m;

      while ((++now_m) < i)
      {
        tengah[s[now_m] - 'a']++;
        while (s[now_m] == s[now_m + 1])
          ++now_m;

      }

    }

    printf("Case #%u: ", a);
    for (i = 0; i < 33; i++)
    {
      if (((((awal[i] > 1) || (akhir[i] > 1)) || (sbg[i] == i)) || (tengah[i] > 1)) || (tengah[i] && (((awal[i] + akhir[i]) + semua[i]) > 0)))
      {
        printf("0\n");
        goto fin;
      }

    }

    for (b = 1, i = 0; i < 33; i++)
      b = (b * ((llu) f[semua[i]])) % 1000000007u;

    for (a = (i = 0); i < 33; i++)
    {
      if ((((semua[i] + awal[i]) + akhir[i]) == 0) || sudah[i])
        continue;

      sudah[i] = 1;
      a++;
      for (now_m = i; sbg[now_m] != (-1); sudah[now_m] = 1)
      {
        now_m = sbg[now_m];
        if (sudah[now_m])
        {
          printf("0\n");
          goto fin;
        }

      }

      for (now_m = i; sbgi[now_m] != (-1); sudah[now_m] = 1)
        now_m = sbgi[now_m];

    }

    printf("%u\n", (b * ((llu) f[a])) % 1000000007u);
    fin:
    ;

  }

  return 0;
}


