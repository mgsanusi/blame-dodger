#include<stdio.h>
#include<stdlib.h>
int star[1024][2];
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int star2cmp(const void *y, const void *b)
{
  int first_iteration;
  int *buttonColorList = (int *) y;
  int *n = (int *) b;
  if (buttonColorList[1] == n[1])
    return 0;

  return buttonColorList[1] > n[1] ? 1 : -1;
}

int Main(int argc, char *argv[])
{
  int first_iteration;
  int y;
  int b;
  int buttonColorList;
  int p;
  int fpI;
  int earn;
  int ans;
  scanf("%d", &fpI);
  for (p = 1; p <= fpI; p++)
  {
    scanf("%d", &buttonColorList);
    for (y = 0; y < buttonColorList; y++)
    {
      scanf("%d%d", star[y] + 0, star[y] + 1);
    }

    new_qsort(star, buttonColorList, (sizeof(int)) * 2, star2cmp);
    earn = 0;
    ans = 0;
    for (y = 0; y < buttonColorList; y++)
    {
      while (earn < star[y][1])
      {
        for (b = buttonColorList - 1; b >= y; b--)
        {
          if ((earn >= star[b][0]) && (star[b][0] != (-100)))
            break;

        }

        if (b < y)
          goto toobad;

        star[b][0] = -100;
        ans++;
        earn++;
      }

      earn++;
      if (star[y][0] != (-100))
        earn++;

      ans++;
    }

    printf("Case #%d: %d\n", p, ans);
    continue;
    toobad:
    printf("Case #%d: Too Bad\n", p);

  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}