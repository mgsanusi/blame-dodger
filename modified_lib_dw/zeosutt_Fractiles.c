#include <stdio.h>
#include <string.h>
#include <stddef.h>
char s[2001];
int cnt[128];
int ans[10];
void *new_memset(void *ptr, int value, size_t num);
int new_putchar(int character);
int main(void)
{
  int first_iteration;
  int i;
  int j;
  int c;
  int t;
  scanf("%d", &t);
  for (c = 1; c <= t; c++)
  {
    new_memset(cnt, 0, sizeof(cnt));
    new_memset(ans, 0, sizeof(ans));
    scanf("%s", s);
    for (i = 0; s[i]; i++)
      cnt[s[i]]++;

    ans[0] = cnt['Z'];
    ans[2] = cnt['W'];
    ans[4] = cnt['U'];
    ans[6] = cnt['X'];
    cnt['E'] -= ans[0];
    cnt['R'] -= ans[0];
    cnt['O'] -= ans[0];
    cnt['O'] -= ans[2];
    cnt['T'] -= ans[2];
    cnt['R'] -= ans[4];
    cnt['O'] -= ans[4];
    cnt['F'] -= ans[4];
    cnt['I'] -= ans[6];
    cnt['S'] -= ans[6];
    ans[3] = cnt['R'];
    ans[1] = cnt['O'];
    ans[5] = cnt['F'];
    ans[7] = cnt['S'];
    ans[8] = cnt['G'];
    ans[9] = (cnt['I'] - ans[5]) - ans[8];
    printf("Case #%d: ", c);
    for (i = 0; i < 10; i++)
      for (j = 0; j < ans[i]; j++)
      new_putchar('0' + i);


    new_putchar('\n');
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num);
int new_putchar(int character)
{
  int first_iteration;
  return putchar(character);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


