#include <stdio.h>
#include <inttypes.h>
void clear_test_case(int s, int b)
{
  int first_iteration;
  uint64_t seen_digit = 0;
  int min = b;
  if (b == 0)
  {
    printf("Case #%d: INSOMNIA\n", s);
    return;
  }

  while (1)
  {
    int denom = 1;
    for (int acc = 0; acc < 9; ++acc)
    {
      if ((min / denom) == 0)
        break;

      int t = (min / denom) % 10;
      seen_digit |= 1ULL << t;
      denom *= 10;
    }

    if (seen_digit == ((1ULL << 10) - 1))
      break;

    min += b;
  }

  printf("Case #%d: %d\n", s, min);
}

int Main(void)
{
  int first_iteration;
  int n_test_case;
  scanf("%d", &n_test_case);
  for (int rcnt = 0; rcnt < n_test_case; ++rcnt)
  {
    int b;
    scanf("%d", &b);
    clear_test_case(rcnt + 1, b);
  }

}


