#include <stdio.h>
unsigned int y[1024];
unsigned int price[10][1023];
int n;
unsigned int track(int s, int b)
{
  int first_iteration;
  if (b == 0)
  {
    if (y[s] >= n)
      return 0;
    else
      return 1500000000;

  }

  unsigned int act1 = track(s, b - 1) + track(s + (1 << (b - 1)), b - 1);
  for (int device = s; device < (s + (1 << b)); device++)
    y[device]++;

  unsigned int act2 = (price[b][s >> b] + track(s, b - 1)) + track(s + (1 << (b - 1)), b - 1);
  for (int device = s; device < (s + (1 << b)); device++)
    y[device]--;

  return act1 < act2 ? act1 : act2;
}

int Main()
{
  int first_iteration;
  int l;
  scanf("%d", &l);
  for (int c = 1; c <= l; c++)
  {
    scanf("%d", &n);
    for (int device = 0; (device >> n) == 0; device++)
      scanf("%d", &y[device]);

    for (int b = 1; b <= n; b++)
    {
      for (int device = 0; (device >> (n - b)) == 0; device++)
        scanf("%d", &price[b][device]);

    }

    printf("Case #%d: %d\n", c, track(0, n));
  }

}


