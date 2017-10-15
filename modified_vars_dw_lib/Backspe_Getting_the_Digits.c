#include <stdio.h>
typedef long long ll;
int a[26];
int cnt[10];
int Main()
{
  int first_iteration;
  int t;
  int t;
  char s[2010];
  int op;
  int term;
  scanf("%d", &t);
  for (t = 1; t <= t; t++)
  {
    for (op = 0; op < 26; op++)
      a[op] = 0;

    for (op = 0; op < 10; op++)
      cnt[op] = 0;

    scanf("%s", s);
    for (term = 0; s[term] != '\0'; term++)
    {
      a[s[term] - 'A']++;
    }

    while (a['Z' - 'A'] > 0)
    {
      a['Z' - 'A']--;
      a['E' - 'A']--;
      a['R' - 'A']--;
      a['O' - 'A']--;
      cnt[0]++;
    }

    while (a['W' - 'A'] > 0)
    {
      a['T' - 'A']--;
      a['W' - 'A']--;
      a['O' - 'A']--;
      cnt[2]++;
    }

    while (a['U' - 'A'] > 0)
    {
      a['F' - 'A']--;
      a['O' - 'A']--;
      a['U' - 'A']--;
      a['R' - 'A']--;
      cnt[4]++;
    }

    while (a['X' - 'A'] > 0)
    {
      a['S' - 'A']--;
      a['I' - 'A']--;
      a['X' - 'A']--;
      cnt[6]++;
    }

    while (a['G' - 'A'] > 0)
    {
      a['E' - 'A']--;
      a['I' - 'A']--;
      a['G' - 'A']--;
      a['H' - 'A']--;
      a['T' - 'A']--;
      cnt[8]++;
    }

    while (a['O' - 'A'] > 0)
    {
      a['O' - 'A']--;
      a['N' - 'A']--;
      a['E' - 'A']--;
      cnt[1]++;
    }

    while (a['R' - 'A'] > 0)
    {
      a['T' - 'A']--;
      a['H' - 'A']--;
      a['R' - 'A']--;
      a['E' - 'A']--;
      a['E' - 'A']--;
      cnt[3]++;
    }

    while (a['F' - 'A'] > 0)
    {
      a['F' - 'A']--;
      a['I' - 'A']--;
      a['V' - 'A']--;
      a['E' - 'A']--;
      cnt[5]++;
    }

    while (a['V' - 'A'] > 0)
    {
      a['S' - 'A']--;
      a['E' - 'A']--;
      a['V' - 'A']--;
      a['E' - 'A']--;
      a['N' - 'A']--;
      cnt[7]++;
    }

    while (a['I' - 'A'] > 0)
    {
      a['N' - 'A']--;
      a['I' - 'A']--;
      a['N' - 'A']--;
      a['E' - 'A']--;
      cnt[9]++;
    }

    printf("Case #%d: ", t);
    for (op = 0; op < 10; op++)
    {
      while ((cnt[op]--) > 0)
        printf("%d", op);

    }

    printf("\n");
  }

}


