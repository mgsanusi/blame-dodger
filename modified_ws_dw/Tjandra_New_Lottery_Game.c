#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
u awal[33];
u tengah[33];
u akhir[33];
u semua[33];
u sudah[33];
u F[111];
int sbg[33];
int sbgi[33];
char S[111];
int main()
{
  int first_iteration;
  u t = 0;
  u T;
  u q;
  u i;
  u j;
  u k;
  u r;
  for (F[i = 0] = 1; (++i) < 111;)
    F[i] = (i * ((llu) F[i - 1])) % 1000000007u;

  for (scanf("%u", &T); (t++) < T;)
  {
    for (i = 0; i < 33; sbg[i] = (sbgi[i] = -1), i++)
      awal[i] = (tengah[i] = (akhir[i] = (semua[i] = (sudah[i] = 0))));

    for (scanf("%u", &q); q--;)
    {
      scanf("%s", S);
      for (i = 0, j = 1; S[++i];)
        if (S[i] != S[i - 1])
        j = 0;


      if (j)
      {
        semua[S[0] - 'a']++;
        continue;
      }

      awal[S[0] - 'a']++;
      akhir[S[--i] - 'a']++;
      sbg[S[0] - 'a'] = S[i] - 'a';
      sbgi[S[i] - 'a'] = S[0] - 'a';
      while (S[i] == S[i - 1])
        --i;

      while (S[j] == S[j + 1])
        ++j;

      while ((++j) < i)
      {
        tengah[S[j] - 'a']++;
        while (S[j] == S[j + 1])
          ++j;

      }

    }

    printf("Case #%u: ", t);
    for (i = 0; i < 33; i++)
    {
      if (((((awal[i] > 1) || (akhir[i] > 1)) || (sbg[i] == i)) || (tengah[i] > 1)) || (tengah[i] && (((awal[i] + akhir[i]) + semua[i]) > 0)))
      {
        printf("0\n");
        goto fin;
      }

    }

    for (r = 1, i = 0; i < 33; i++)
      r = (r * ((llu) F[semua[i]])) % 1000000007u;

    for (k = (i = 0); i < 33; i++)
    {
      if ((((semua[i] + awal[i]) + akhir[i]) == 0) || sudah[i])
        continue;

      sudah[i] = 1;
      k++;
      for (j = i; sbg[j] != (-1); sudah[j] = 1)
      {
        j = sbg[j];
        if (sudah[j])
        {
          printf("0\n");
          goto fin;
        }

      }

      for (j = i; sbgi[j] != (-1); sudah[j] = 1)
        j = sbgi[j];

    }

    printf("%u\n", (r * ((llu) F[k])) % 1000000007u);
    fin:
    ;

  }

  return 0;
}


