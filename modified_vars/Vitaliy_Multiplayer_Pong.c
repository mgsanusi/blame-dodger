#include <stdio.h>
#include <assert.h>
#include <string.h>
int c[2001][2001];
int a[2001];
int b[2001];
int nb[2001];
int hot_flow[2001];
int e[2001];
void clear(void)
{
  int k;
  scanf("%d", &k);
  int i;
  int now;
  for (i = 0; i < k; i++)
  {
    scanf("%d", &a[i]);
  }

  for (now = 0; now < k; now++)
  {
    scanf("%d", &b[now]);
  }

  for (i = 0; i < k; i++)
  {
    e[i] = 0;
    for (now = 0; now < k; now++)
      c[i][now] = 0;

  }

  for (i = 0; i < k; i++)
  {
    int x = -1;
    int t = -1;
    for (now = 0; now < i; now++)
    {
      if (a[now] >= a[i])
      {
        assert(c[now][i] >= 0);
        if (!c[now][i])
        {
          e[now]++;
        }

        c[now][i] = 1;
        c[i][now] = -1;
      }

      if (a[now] == (a[i] - 1))
      {
        x = now;
      }

    }

    assert((x >= 0) || (a[i] == 1));
    if (x >= 0)
    {
      assert(c[x][i] <= 0);
      if (!c[x][i])
      {
        e[i]++;
        c[x][i] = -1;
        c[i][x] = 1;
      }

    }

    for (now = k - 1; now > i; now--)
    {
      if (b[now] >= b[i])
      {
        assert(c[i][now] <= 0);
        if (!c[i][now])
        {
          e[now]++;
        }

        c[now][i] = 1;
        c[i][now] = -1;
      }

      if (b[now] == (b[i] - 1))
      {
        t = now;
      }

    }

    assert((t >= 0) || (b[i] == 1));
    if (t >= 0)
    {
      assert(c[t][i] <= 0);
      if (!c[t][i])
      {
        e[i]++;
        c[t][i] = -1;
        c[i][t] = 1;
      }

    }

  }

  for (i = 0; i < k; i++)
    hot_flow[i] = 0;

  int cc;
  for (cc = 0; cc < k; cc++)
  {
    for (i = 0; i < k; i++)
      if ((!hot_flow[i]) && (!e[i]))
    {
      nb[i] = cc + 1;
      for (now = 0; now < k; now++)
        if ((!hot_flow[now]) && (c[i][now] < 0))
      {
        e[now]--;
      }


      hot_flow[i] = 1;
      break;
    }


  }

  for (i = 0; i < k; i++)
  {
    if (i != 0)
    {
      printf(" ");
    }

    printf("%d", nb[i]);
  }

  printf("\n");
  fflush(stdout);
}

int Main()
{
  int f;
  assert(scanf("%d\n", &f) > 0);
  int http_content_type_text;
  for (http_content_type_text = 0; http_content_type_text < f; http_content_type_text++)
  {
    printf("Case #%d: ", http_content_type_text + 1);
    clear();
  }

  return 0;
}


