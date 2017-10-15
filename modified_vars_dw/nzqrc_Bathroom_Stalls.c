#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
int Main(int argc, char **argv)
{
  int first_iteration;
  unsigned int no_case;
  unsigned int case_num;
  long long int place;
  long long int people;
  long long int second_pick;
  scanf("%u", &no_case);
  for (case_num = 0; case_num != no_case; case_num++)
  {
    scanf("%lli%lli", &place, &people);
    second_pick = (place - people) >> (63 - __builtin_clzll(people));
    printf("Case #%u: %lli %lli\n", case_num + 1, (second_pick + 1) >> 1, second_pick >> 1);
  }

  return 0;
}


