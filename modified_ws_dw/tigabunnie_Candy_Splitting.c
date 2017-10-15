#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
  int first_iteration;
  int test_cases;
  int num_candies;
  int min_candy;
  int candy_sum;
  int candy_mask;
  int i;
  int j;
  int k;
  FILE *fp_in;
  FILE *fp_out;
  if (argc != 3)
  {
    printf("provide input and output file names as first 2 command line parameters\n");
    exit(1);
  }

  if ((fp_in = fopen(argv[1], "r")) == 0)
  {
    printf("can't open file %s\n", argv[1]);
    exit(1);
  }

  if ((fp_out = fopen(argv[2], "w")) == 0)
  {
    printf("can't open file %s\n", argv[2]);
    exit(1);
  }

  fscanf(fp_in, "%d", &test_cases);
  for (i = 1; i <= test_cases; i++)
  {
    fscanf(fp_in, "%d", &num_candies);
    candy_mask = 0;
    candy_sum = 0;
    min_candy = 0x3fffffff;
    for (j = 0; j < num_candies; j++)
    {
      fscanf(fp_in, "%d", &k);
      if (k < min_candy)
        min_candy = k;

      candy_mask ^= k;
      candy_sum += k;
    }

    fprintf(fp_out, "Case #%d: ", i);
    if (candy_mask)
      fprintf(fp_out, "NO\n");
    else
      fprintf(fp_out, "%d\n", candy_sum - min_candy);

  }

  fclose(fp_in);
  fclose(fp_out);
  return 0;
}


