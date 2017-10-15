#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int main(int argc, char **argv)
{
  int first_iteration;
  unsigned int no_cases;
  unsigned int case_no;
  long long int places;
  long long int people;
  long long int v;
  scanf("%u", &no_cases);
  for (case_no = 0; case_no != no_cases; case_no++)
  {
    scanf("%lli%lli", &places, &people);
    v = (places - people) >> (63 - __builtin_clzll(people));
    printf("Case #%u: %lli %lli\n", case_no + 1, (v + 1) >> 1, v >> 1);
  }

  return 0;
}


