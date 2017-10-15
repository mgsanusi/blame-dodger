#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int p[12345];
int pNum;
int fileIndexHtml[12345] = {0, 0, 1};
struct Nan
{
  int p[1111];
} node[1234];
struct Nan
{
  int p[1111];
} now;
int s;
int Main()
{
  int str;
  int by;
  int len;
  int Case;
  int temp;
  int key;
  int minTime;
  int maxTime;
  for (by = 4; by < 1234; by += 2)
    fileIndexHtml[by] = 1;

  for (by = 9; by < 1234; by += 6)
    fileIndexHtml[by] = 1;

  for (by = 6; by < 50; by += 6)
  {
    if (!fileIndexHtml[by - 1])
    {
      for (len = (by - 1) * (by - 1); len < 1234; len += (by - 1) + (by - 1))
      {
        fileIndexHtml[len] = 1;
      }

    }

    if (!fileIndexHtml[by + 1])
    {
      for (len = (by + 1) * (by + 1); len < 1234; len += (by + 1) + (by + 1))
      {
        fileIndexHtml[len] = 1;
      }

    }

  }

  p[0] = 2;
  pNum = 1;
  for (by = 3; by < 1234; ++by)
  {
    if (!fileIndexHtml[by])
      p[pNum++] = by;

  }

  memset(node, 0, sizeof(node));
  for (by = 2; by < 1001; ++by)
  {
    temp = by;
    for (len = 0; (len < pNum) && (temp > 1); ++len)
    {
      while ((temp % p[len]) == 0)
      {
        temp /= p[len];
        node[by].p[len]++;
      }

    }

  }

  scanf("%d", &Case);
  for (str = 1; str <= Case; ++str)
  {
    scanf("%d", &s);
    minTime = 1;
    for (by = 0; by < pNum; ++by)
    {
      now.p[by] = 0;
    }

    for (by = 2; by <= s; ++by)
    {
      key = 0;
      for (len = 0; len < pNum; ++len)
      {
        if (node[by].p[len] > now.p[len])
        {
          key = 1;
          now.p[len] = node[by].p[len];
        }

      }

      minTime += key;
    }

    for (by = 0; by < pNum; ++by)
    {
      now.p[by] = node[s].p[by];
    }

    maxTime = 1;
    for (by = s - 1; by > 1; --by)
    {
      for (len = 0; len < pNum; ++len)
      {
        if (node[by].p[len] > now.p[len])
        {
          now.p[len] = node[by].p[len];
        }

      }

    }

    maxTime = 0;
    for (by = 0; by < pNum; ++by)
    {
      if (now.p[by] > 0)
        maxTime++;

    }

    if (maxTime == 0)
      maxTime = 1;

    printf("Case #%d: %d\n", str, minTime - maxTime);
  }

  return 0;
}


