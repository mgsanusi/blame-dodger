#include <stdio.h>
#include <string.h>
#include <stddef.h>
char names[101][110];
int hash[1500];
void *new_memset(void *ptr, int value, size_t num);
int new_getchar();
int calc_hash(char s[])
{
  int first_iteration;
  int sum = 0;
  int i;
  for (i = 0; s[i] != '\0'; i++)
    sum += s[i];

  return sum % 1000;
}

int main()
{
  int first_iteration;
  int n;
  int i;
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    int s;
    int q;
    int j;
    scanf("%d\n", &s);
    new_memset(hash, 0, sizeof(hash));
    new_memset(names, 0, sizeof(names));
    for (j = 1; j <= s; j++)
    {
      int k;
      int c;
      for (k = 0; (c = new_getchar()) != '\n'; k++)
        names[j][k] = c;

      int key = calc_hash(names[j]);
      while (hash[key] != 0)
        key++;

      hash[key] = j;
    }

    scanf("%d\n", &q);
    int used[101];
    int cnt_used = 0;
    int cnt_switch = 0;
    char query[110];
    new_memset(used, 0, sizeof(used));
    for (j = 0; j < q; j++)
    {
      int k;
      int c;
      for (k = 0; (c = new_getchar()) != '\n'; k++)
        query[k] = c;

      query[k] = '\0';
      int key = calc_hash(query);
      while (hash[key] && strcmp(query, names[hash[key]]))
        key++;

      if (hash[key])
      {
        cnt_used += 1 - used[hash[key]];
        used[hash[key]] = 1;
        if (cnt_used == s)
        {
          cnt_switch++;
          cnt_used = 1;
          new_memset(used, 0, sizeof(used));
          used[hash[key]] = 1;
        }

      }

    }

    printf("Case #%d: %d\n", i, cnt_switch);
  }

  return 0;
}

void *new_memset(void *ptr, int value, size_t num);
int new_getchar()
{
  int first_iteration;
  return getchar();
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


