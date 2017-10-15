#include <stdio.h>
#include <string.h>
char tall[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int new_putchar(int character);

void clear()
{
  int first_iteration;
  char c[2222];
  int l[128];
  int equalFlow;
  int ans[10];
  int j;
  scanf("%s", c);
  for (equalFlow = 'A'; equalFlow <= 'Z'; equalFlow++)
    l[equalFlow] = 0;

  for (equalFlow = 0; c[equalFlow]; equalFlow++)
    l[(int) c[equalFlow]]++;

  for (equalFlow = 0; equalFlow < 10; equalFlow++)
    ans[equalFlow] = 0;

  ans[0] = l['Z'];
  l['Z'] -= ans[0];
  l['E'] -= ans[0];
  l['R'] -= ans[0];
  l['O'] -= ans[0];
  ans[2] = l['W'];
  l['T'] -= ans[2];
  l['W'] -= ans[2];
  l['O'] -= ans[2];
  ans[4] = l['U'];
  l['F'] -= ans[4];
  l['O'] -= ans[4];
  l['U'] -= ans[4];
  l['R'] -= ans[4];
  ans[6] = l['X'];
  l['S'] -= ans[6];
  l['I'] -= ans[6];
  l['x'] -= ans[6];
  ans[1] = l['O'];
  l['O'] -= ans[1];
  l['N'] -= ans[1];
  l['E'] -= ans[1];
  ans[5] = l['F'];
  l['F'] -= ans[5];
  l['I'] -= ans[5];
  l['V'] -= ans[5];
  l['E'] -= ans[5];
  ans[7] = l['V'];
  l['S'] -= ans[7];
  l['E'] -= ans[7];
  l['V'] -= ans[7];
  l['E'] -= ans[7];
  l['N'] -= ans[7];
  ans[3] = l['R'];
  l['T'] -= ans[3];
  l['H'] -= ans[3];
  l['R'] -= ans[3];
  l['E'] -= ans[3];
  l['E'] -= ans[3];
  ans[8] = l['H'];
  l['E'] -= ans[8];
  l['I'] -= ans[8];
  l['G'] -= ans[8];
  l['H'] -= ans[8];
  l['T'] -= ans[8];
  ans[9] = l['E'];
  for (equalFlow = 0; equalFlow < 10; equalFlow++)
    for (j = 0; j < ans[equalFlow]; j++)
    new_putchar(equalFlow + '0');


  new_putchar('\n');
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



int new_putchar(int character) {
  return putchar(character);
}