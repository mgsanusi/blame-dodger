#include<stdio.h>
void intReverse(int d[], int size)
{
  int a = 0;
  int sum = size - 1;
  int t;
  while (a < sum)
    t = d[a], d[a] = d[sum], d[sum] = t, a++, sum--;

}

int intNextPermutation(int d[], int size)
{
  int target;
  int pos;
  int k;
  for (k = size - 2; k >= 0; k--)
    if (d[k] < d[k + 1])
    break;


  if (k < 0)
  {
    intReverse(d, size);
    return 0;
  }

  for (target = size - 1;; target--)
    if (d[target] > d[k])
    break;


  pos = d[target], d[target] = d[k], d[k] = pos;
  intReverse((d + k) + 1, (size - k) - 1);
  return 1;
}

int Main()
{
  int target;
  int pos;
  int k;
  int cs;
  int m;
  int n;
  int length;
  int choose;
  int tmp;
  char pPos[2000];
  char next[2000];
  int d[100];
  int size;
  int count = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%s", &k, pPos);
    for (target = 0;; target++)
      if (pPos[target] < ' ')
      break;


    length = target;
    choose = length;
    for (target = 0; target < k; target++)
      d[target] = target;

    do
    {
      for (target = 0; target < (length / k); target++)
        for (pos = 0; pos < k; pos++)
        next[(target * k) + pos] = pPos[(target * k) + d[pos]];


      tmp = 1;
      for (target = 1; target < length; target++)
        if (next[target - 1] != next[target])
        tmp++;


      if (choose > tmp)
        choose = tmp;

    }
    while (intNextPermutation(d, k));
    printf("Case #%d: %d\n", ++count, choose);
  }

  return 0;
}


