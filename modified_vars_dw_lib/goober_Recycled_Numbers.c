#include <stdio.h>
int Main()
{
  int first_iteration;
  int input_file_ptr;
  scanf("%d", &input_file_ptr);
  for (int bin = 1; bin <= input_file_ptr; bin++)
  {
    int size;
    int b;
    scanf("%d %d", &size, &b);
    int result = 0;
    int digmul = 1;
    int dig = 1;
    for (int x = size; x >= 10; x++)
    {
      digmul *= 10;
      dig++;
      x /= 10;
    }

    for (int n = size; n <= b; n++)
    {
      int m = n;
      int former[dig];
      for (int y = 0; y < dig; y++)
      {
        former[y] = m;
        m = ((m % 10) * digmul) + (m / 10);
        if (((m <= n) || (m > b)) || ((m / digmul) == 0))
          continue;

        for (int k = 0; k < y; k++)
          if (former[k] == m)
          goto bad;


        result++;
        bad:
        ;

      }

    }

    printf("Case #%d: %d\n", bin, result);
  }

  return 0;
}


