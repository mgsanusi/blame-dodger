#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int node[1000][1000];
int cas;
int search(int in)
{
  int i;
  int max;
  int ans = 1;
  int s;
  for (i = 0; i < cas; ++i)
  {
    if (!node[in][i])
      continue;

    for (max = i + 1; max < cas; ++max)
    {
      if (node[in][max])
      {
        node[in][i] = (node[i][in] = (node[in][max] = (node[max][in] = 0)));
        s = (search(i) + search(max)) + 1;
        node[in][i] = (node[i][in] = (node[in][max] = (node[max][in] = 1)));
        if (s > ans)
          ans = s;

      }

    }

  }

  return ans;
}

int clear(void)
{
  int i = 0;
  int ret = 0;
  int s;
  for (i = 0; i < cas; ++i)
  {
    s = search(i);
    if (s > ret)
      ret = s;

  }

  return cas - ret;
}

int Main(void)
{
  int no;
  int tryNo;
  int i;
  int max;
  int p;
  scanf("%d", &no);
  for (tryNo = 1; tryNo <= no; ++tryNo)
  {
    scanf("%d", &cas);
    memset(node, 0, sizeof(node));
    for (i = 1; i < cas; ++i)
    {
      scanf("%d %d", &max, &p);
      node[max - 1][p - 1] = (node[p - 1][max - 1] = 1);
    }

    printf("Case #%d: %d\n", tryNo, clear());
  }

  return 0;
}


