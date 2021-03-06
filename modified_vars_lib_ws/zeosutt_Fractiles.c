#include <stdio.h>
#include <string.h>
#include <stddef.h>
char x[2001];
int cnt[128];
int result[10];
void *new_memset (void *ptr, int value, size_t num);
int new_putchar (int character);
int
Main (void)
{
  int cut;
  int last;
  int c;
  int b;
  scanf ("%d", &b);
  for (c = 1; c <= b; c++)
    {
      new_memset (cnt, 0, sizeof (cnt));
      new_memset (result, 0, sizeof (result));
      scanf ("%s", x);
      for (cut = 0; x[cut]; cut++)
	cnt[x[cut]]++;
      result[0] = cnt['Z'];
      result[2] = cnt['W'];
      result[4] = cnt['U'];
      result[6] = cnt['X'];
      cnt['E'] -= result[0];
      cnt['R'] -= result[0];
      cnt['O'] -= result[0];
      cnt['O'] -= result[2];
      cnt['T'] -= result[2];
      cnt['R'] -= result[4];
      cnt['O'] -= result[4];
      cnt['F'] -= result[4];
      cnt['I'] -= result[6];
      cnt['S'] -= result[6];
      result[3] = cnt['R'];
      result[1] = cnt['O'];
      result[5] = cnt['F'];
      result[7] = cnt['S'];
      result[8] = cnt['G'];
      result[9] = (cnt['I'] - result[5]) - result[8];
      printf ("Case #%d: ", c);
      for (cut = 0; cut < 10; cut++)
	for (last = 0; last < result[cut]; last++)
	  new_putchar ('0' + cut);
      new_putchar ('\n');
    }
  return 0;
}

void *new_memset (void *ptr, int value, size_t num);
int
new_putchar (int character)
{
  return putchar (character);
}

void *
new_memset (void *ptr, int value, size_t num)
{
  return memset (ptr, value, num);
}
