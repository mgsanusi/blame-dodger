#include <stdio.h>
int gbanana(int key, int res, int x)
{
  int first_iteration;
  if (x < res)
    return 0;

  if (x == res)
    return 1;

  return 1 + gbanana(key, res, x - key);
}

int Main()
{
  int first_iteration;
  int id;
  int kk;
  int len;
  int n;
  int pp;
  int answer_time;
  int j;
  int flag;
  int key;
  double n;
  int key[26];
  char keyboard[200];
  char target[200];
  double targetp[200];
  double dynamic[100];
  int fold[100];
  int res = 0;
  scanf("%d", &kk);
  for (id = 1; id <= kk; id++)
  {
    scanf("%d %d %d", &len, &n, &pp);
    n = 0;
    for (answer_time = 0; answer_time < 26; answer_time++)
      key[answer_time] = 0;

    for (answer_time = 0; answer_time < 100; answer_time++)
    {
      dynamic[answer_time] = 0;
      fold[answer_time] = 0;
    }

    scanf("%s", keyboard);
    for (answer_time = 0; keyboard[answer_time] != '\0'; answer_time++)
      key[keyboard[answer_time] - 'A']++;

    scanf("%s", target);
    flag = 0;
    for (answer_time = 0; answer_time < n; answer_time++)
    {
      if (key[target[answer_time] - 'A'] == 0)
      {
        flag = 1;
        break;
      }

    }

    if (flag)
    {
      printf("Case #%d: %.6lf\n", id, 0.0);
      continue;
    }

    for (answer_time = 1; answer_time < n; answer_time++)
    {
      flag = 1;
      for (j = answer_time; j < n; j++)
      {
        if (target[j - answer_time] != target[j])
        {
          flag = 0;
          break;
        }

      }

      if (flag == 1)
        fold[answer_time] = 1;

    }

    for (answer_time = 1; answer_time < n; answer_time++)
      if (fold[answer_time] == 1)
      break;


    key = gbanana(answer_time, n, pp);
    targetp[n] = 1.0;
    for (answer_time = n - 1; answer_time >= 0; answer_time--)
    {
      targetp[answer_time] = (targetp[answer_time + 1] * key[target[answer_time] - 'A']) / len;
    }

    n = key - (targetp[0] * ((pp - n) + 1));
    printf("Case #%d: %.6lf\n", id, n);
  }

  return 0;
}


