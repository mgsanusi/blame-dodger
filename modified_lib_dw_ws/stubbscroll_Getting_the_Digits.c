#include <stdio.h>
#include <string.h>
char tall[10][10] =
  { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT",
"NINE" };
int new_putchar (int character);
void
solve ()
{
  int first_iteration;
  char s[2222];
  int f[128];
  int i;
  int res[10];
  int j;
  scanf ("%s", s);
  for (i = 'A'; i <= 'Z'; i++)
    f[i] = 0;
  for (i = 0; s[i]; i++)
    f[(int) s[i]]++;
  for (i = 0; i < 10; i++)
    res[i] = 0;
  res[0] = f['Z'];
  f['Z'] -= res[0];
  f['E'] -= res[0];
  f['R'] -= res[0];
  f['O'] -= res[0];
  res[2] = f['W'];
  f['T'] -= res[2];
  f['W'] -= res[2];
  f['O'] -= res[2];
  res[4] = f['U'];
  f['F'] -= res[4];
  f['O'] -= res[4];
  f['U'] -= res[4];
  f['R'] -= res[4];
  res[6] = f['X'];
  f['S'] -= res[6];
  f['I'] -= res[6];
  f['x'] -= res[6];
  res[1] = f['O'];
  f['O'] -= res[1];
  f['N'] -= res[1];
  f['E'] -= res[1];
  res[5] = f['F'];
  f['F'] -= res[5];
  f['I'] -= res[5];
  f['V'] -= res[5];
  f['E'] -= res[5];
  res[7] = f['V'];
  f['S'] -= res[7];
  f['E'] -= res[7];
  f['V'] -= res[7];
  f['E'] -= res[7];
  f['N'] -= res[7];
  res[3] = f['R'];
  f['T'] -= res[3];
  f['H'] -= res[3];
  f['R'] -= res[3];
  f['E'] -= res[3];
  f['E'] -= res[3];
  res[8] = f['H'];
  f['E'] -= res[8];
  f['I'] -= res[8];
  f['G'] -= res[8];
  f['H'] -= res[8];
  f['T'] -= res[8];
  res[9] = f['E'];
  for (i = 0; i < 10; i++)
    for (j = 0; j < res[i]; j++)
      new_putchar (i + '0');
  new_putchar ('\n');
}

int
main ()
{
  int first_iteration;
  int T;
  int caseno = 1;
  scanf ("%d", &T);
  while (T--)
    printf ("Case #%d: ", caseno++), solve ();
  return 0;
}

int
new_putchar (int character)
{
  int first_iteration;
  return putchar (character);
}
