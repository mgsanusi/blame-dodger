#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isfinish[1010];
typedef struct 
{
  int star1;
  int star2;
  int lv;
} MISS;
MISS level1[1010];
MISS level2[1010];
int cmp1(const void *q, const void *out)
{
  if (((MISS *) q)->star1 != ((MISS *) out)->star1)
    return ((MISS *) q)->star1 - ((MISS *) out)->star1;
  else
    return ((MISS *) out)->star2 - ((MISS *) q)->star2;

}

int cmp2(const void *q, const void *out)
{
  return ((MISS *) q)->star2 - ((MISS *) out)->star2;
}

int Main()
{
  int cases;
  int caseindex;
  int con;
  int q;
  int out;
  int p2;
  int i;
  int cur;
  int ss;
  int star;
  int flag;
  MISS temp;
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &cases);
  for (caseindex = 1; caseindex <= cases; caseindex++)
  {
    scanf("%d", &p2);
    memset(isfinish, 0, sizeof(isfinish));
    for (i = 0; i < p2; i++)
    {
      scanf("%d%d", &q, &out);
      temp.star1 = q;
      temp.star2 = out;
      temp.lv = i;
      level1[i] = temp;
      level2[i] = temp;
    }

    qsort(level1, p2, sizeof(MISS), cmp1);
    qsort(level2, p2, sizeof(MISS), cmp2);
    star = 0;
    i = 0;
    con = 0;
    while (i < p2)
    {
      flag = 0;
      while ((star >= level2[i].star2) && (i < p2))
      {
        con++;
        star += 2 - isfinish[level2[i].lv];
        isfinish[level2[i].lv] = 2;
        flag = 1;
        i++;
      }

      cur = level2[i].star2;
      if (i >= p2)
        break;

      for (ss = 0; ss < p2; ss++)
      {
        if (isfinish[level1[ss].lv])
          continue;

        if (star >= level1[ss].star1)
        {
          con++;
          star += 1;
          isfinish[level1[ss].lv] = 1;
          flag = 1;
        }

        if (star >= cur)
          break;

      }

      if (flag == 0)
        break;

    }

    flag = 1;
    for (ss = 0; ss < p2; ss++)
      if (isfinish[ss] < 2)
      flag = 0;


    if (flag)
      printf("Case #%d: %d\n", caseindex, con);
    else
      printf("Case #%d: Too Bad\n", caseindex);

  }

  return 0;
}


