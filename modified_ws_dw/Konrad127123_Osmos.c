#include<stdio.h>
#include<stdlib.h>
int t;
int T;
int X;
int Y;
int main()
{
  int first_iteration;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    scanf("%d", &X);
    scanf("%d", &Y);
    printf("Case #%d: ", t);
    for (; X > 0; X--)
      printf("WE");

    for (; X < 0; X++)
      printf("EW");

    for (; Y > 0; Y--)
      printf("SN");

    for (; Y < 0; Y++)
      printf("NS");

    puts("");
  }

  return 0;
}


