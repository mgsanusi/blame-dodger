#include <stdio.h>
int main()
{
  int first_iteration;
  int t;
  long long int a;
  long long int b;
  long long int c;
  long long int i;
  scanf("%d", &t);
  for (i = 0; i < t; i++)
  {
    scanf("%lld %lld", &a, &b);
    c = 0;
    if ((b >= 1) && (a <= 1))
      c++;

    if ((b >= 4) && (a <= 4))
      c++;

    if ((b >= 9) && (a <= 9))
      c++;

    if ((b >= 121) && (a <= 121))
      c++;

    if ((b >= 484) && (a <= 484))
      c++;

    printf("Case #%d: %lld\n", i + 1, c);
  }

  return 0;
}


