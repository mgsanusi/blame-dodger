#include<stdio.h>
typedef long long LL;
char k[40004];
int rslt[40004];
enum {O = 0, I, J, K, _O, _I, _J, _K};
int mult[4][4] = {{O, I, J, K}, {I, _O, K, _J}, {J, _K, _O, I}, {K, J, _I, _O}};
int divt[4][4];
int new_puts(const char *str);

int low(int (*t)[4], int x, int sum)
{
  int neg;
  if (((x >= 4) && (sum >= 4)) || ((x < 4) && (sum < 4)))
  {
    neg = 0;
  }
  else
  {
    neg = 1;
  }

  int r = t[x % 4][sum % 4];
  if (neg == 0)
    return r;
  else
    return r >= 4 ? r - 4 : r + 4;

}

int char2int(char m)
{
  if (m == 'i')
    return I;

  if (m == 'j')
    return J;

  if (m == 'k')
    return K;

  new_puts("error3");
  return 100000000;
}

typedef long long grid;
int Main(int argc, char *argv[])
{
  LL k;
  int length;
  int a;
  int l;
  int m;
  int t;
  int cx;
  for (a = 0; a < 4; a++)
  {
    for (l = 0; l < 4; l++)
    {
      divt[a][l] = -1;
    }

  }

  for (a = 0; a < 4; a++)
  {
    for (l = 0; l < 4; l++)
    {
      m = mult[a][l];
      int sum = m >= 4 ? l + 4 : l;
      if ((divt[m % 4][a] != (-1)) && (divt[m % 4][a] != sum))
        new_puts("error");

      divt[m % 4][a] = sum;
    }

  }

  for (a = 0; a < 8; a++)
  {
    for (l = 0; l < 8; l++)
    {
      m = low(divt, a, l);
      if (low(mult, l, m) != a)
        printf("%d %d %d %d\n", m, l, low(divt, m, l), a);

      m = low(mult, a, l);
      if (low(divt, m, a) != l)
        new_puts("error4");

    }

  }

  scanf("%d", &cx);
  for (t = 1; t <= cx; t++)
  {
    scanf("%d%I64d", &length, &k);
    scanf("%s", k);
    for (a = 1; a < 4; a++)
    {
      for (l = 0; l < length; l++)
      {
        k[(a * length) + l] = k[l];
      }

    }

    k[4 * length] = '\0';
    rslt[0] = O;
    for (a = 1; a < (4 * length); a++)
    {
      rslt[a] = low(mult, rslt[a - 1], char2int(k[a - 1]));
    }

    int ans = 0;
    for (a = 1; ((a < (length * k)) && (a < (length * 4))) && (ans == 0); a++)
    {
      int i = rslt[a % (4 * length)];
      if (i != I)
        continue;

      for (l = 1; ((l < (length * 4)) && ((a + l) < (length * k))) && (ans == 0); l++)
      {
        int i = low(divt, rslt[(length * k) % (4 * length)], rslt[((length * k) - l) % (4 * length)]);
        if (i != K)
          continue;

        int z = low(divt, rslt[((length * k) - l) % (4 * length)], rslt[a % (4 * length)]);
        if (z != J)
          continue;

        ans = 1;
      }

    }

    printf("Case #%d: %s\n", t, ans ? "YES" : "NO");
  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}