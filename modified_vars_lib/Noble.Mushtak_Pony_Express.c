#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_people;
typedef long num_groups;
typedef long num_pieces;
typedef long modulo;
inline 
void new_exit(int status);
static long long min(long long length1, long long length2)
{
  return length1 < length2 ? length1 : length2;
}

inline static long long max(long long length1, long long length2)
{
  return length1 > length2 ? length1 : length2;
}

typedef long test_case;
typedef long no_people;
typedef long num_pieces;
typedef long modulo;
num_pieces carry_size;
num_groups no_group;
num_groups partition_length[4];
num_groups answer;
num_people group[100];
int Main()
{
  num_groups xpos;
  test_cases num_test_case;
  test_cases k;
  modulo store_modulo;
  scanf("%li", &num_test_case);
  for (k = 0; k < num_test_case; k++)
  {
    scanf("%li %li", &no_group, &carry_size);
    memset(partition_length, 0, sizeof(partition_length));
    for (xpos = 0; xpos < no_group; xpos++)
    {
      scanf("%li", group + xpos);
      store_modulo = group[xpos] % carry_size;
      partition_length[store_modulo]++;
    }

    for (answer = 0; no_group > 0; answer++)
    {
      if (partition_length[0] > 0)
      {
        partition_length[0]--;
        no_group--;
      }
      else
        if ((partition_length[1] > 0) && (partition_length[carry_size - 1] > 0))
      {
        partition_length[1]--;
        partition_length[carry_size - 1]--;
        no_group -= 2;
      }
      else
        if (partition_length[1] > 0)
      {
        no_group -= min(partition_length[1], carry_size);
        partition_length[1] -= min(partition_length[1], carry_size);
      }
      else
        if (partition_length[carry_size - 1] > 0)
      {
        no_group -= min(partition_length[carry_size - 1], carry_size);
        partition_length[carry_size - 1] -= min(partition_length[carry_size - 1], carry_size);
      }




    }

    printf("Case #%li: %li\n", k + 1, answer);
  }

  new_exit(0);
}



void new_exit(int status) {
  return exit(status);
}