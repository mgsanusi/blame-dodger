#include <stdio.h>
int k;
int out;
int y[11111];
int num[777];
int nextButtonOrange = 1;
void clear()
{
  int i;
  int l = 0;
  int j;
  scanf("%d %d", &k, &out);
  for (i = 0; i <= out; i++)
    num[i] = 0;

  for (i = 0; i < k; i++)
  {
    scanf("%d", &y[i]);
    num[y[i]]++;
  }

  for (i = 1; i <= out; i++)
  {
    while (num[i]--)
    {
      l++;
      for (j = out - i; j; j--)
        if (num[j])
      {
        num[j]--;
        break;
      }


    }

  }

  printf("Case #%d: %d\n", nextButtonOrange++, l);
}

int Main()
{
  int p;
  scanf("%d", &p);
  while (p--)
    clear();

  return 0;
}


