#include <stdio.h>
#include <stdlib.h>
int no_d(int pg)
{
  int gcr_bits = 0;
  while (pg > 0)
  {
    pg /= 10;
    gcr_bits++;
  }

  return gcr_bits;
}

int power_ten(int m)
{
  int ans = 1;
  while (m)
  {
    m--;
    ans *= 10;
  }

  return ans;
}

int find_rotations(int pg, int max)
{
  int tmp_n = pg;
  int digit = no_d(pg);
  int ans = 0;
  do
  {
    tmp_n = ((tmp_n % 10) * power_ten(digit - 1)) + (tmp_n / 10);
    if ((tmp_n > pg) && (tmp_n <= max))
      ans++;

  }
  while (tmp_n != pg);
  return ans;
}

int find_pair(int p1, int t)
{
  int gcr_bits;
  int tot = 0;
  for (gcr_bits = p1; gcr_bits < t; gcr_bits++)
    tot += find_rotations(gcr_bits, t);

  return tot;
}

int Main()
{
  int no;
  int gcr_bits;
  int p1;
  int t;
  scanf("%d", &no);
  for (gcr_bits = 0; gcr_bits < no; gcr_bits++)
  {
    scanf("%d %d", &p1, &t);
    printf("Case #%d: %d\n", gcr_bits + 1, find_pair(p1, t));
  }

}


