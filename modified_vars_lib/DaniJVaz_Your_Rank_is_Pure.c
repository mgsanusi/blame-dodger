#include <stdio.h>
#include <stdlib.h>
void make_screen_case();
void init();
int Main()
{
  int caseno;
  int m;
  scanf("%d", &m);
  init();
  for (caseno = 1; caseno <= m; caseno++)
  {
    printf("Case #%d: ", caseno);
    make_screen_case();
  }

  return 0;
}

int arr_no[500 + 1][500 + 1];
int comb_array[500 + 1][500 + 1];
int inv[100003];
void all_inverses();
int comb(int a, int c);
int num_room(int m, int s);
void make_screen_case()
{
  int m;
  scanf("%d", &m);
  int caseno;
  int s = 0;
  for (caseno = 1; caseno < m; caseno++)
  {
    s += num_room(m, caseno);
    s = s % 100003;
  }

  printf("%d\n", s);
}

void init()
{
  all_inverses();
  int caseno;
  int ans;
  for (caseno = 0; caseno <= 500; caseno++)
  {
    for (ans = 0; ans <= 500; ans++)
    {
      arr_no[caseno][ans] = -1;
      comb_array[caseno][ans] = -1;
    }

  }

}

void all_inverses()
{
  inv[0] = 0;
  int caseno = 0;
  long long int m = 2;
  long long int invn;
  for (caseno = 2; caseno < 100003; caseno++)
  {
    if (((m * caseno) % 100003) == 1)
    {
      inv[m] = caseno;
      inv[caseno] = m;
      break;
    }

  }

  invn = inv[2];
  long long int a = m;
  long long int c = invn;
  do
  {
    a = (a * m) % 100003;
    c = (c * invn) % 100003;
    inv[a] = c;
    inv[c] = a;
  }
  while (a != 1);
}

int comb(int a, int c)
{
  if (a < c)
    return 0;

  if (c == 0)
    return 1;

  if (a == c)
    return 1;

  if (comb_array[a][c] != (-1))
    return comb_array[a][c];

  long long ans;
  ans = a;
  ans *= inv[c];
  ans = ans % 100003;
  ans *= comb(a - 1, c - 1);
  ans = ans % 100003;
  comb_array[a][c] = ans;
  return (int) ans;
}

int num_room(int m, int s)
{
  if (s == 1)
    return 1;

  if (arr_no[m][s] != (-1))
    return arr_no[m][s];

  int caseno;
  long long x;
  long long ans = 0;
  for (caseno = 1; caseno < s; caseno++)
  {
    x = num_room(s, caseno);
    x *= comb((m - s) - 1, (s - caseno) - 1);
    x = x % 100003;
    ans += x;
    ans = ans % 100003;
  }

  arr_no[m][s] = ans;
  return ans;
}


