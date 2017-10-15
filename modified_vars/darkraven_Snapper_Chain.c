#include<stdio.h>
int Main()
{
  int place;
  scanf("%d", &place);
  int output_file_ptr;
  for (output_file_ptr = 1; output_file_ptr <= place; output_file_ptr++)
  {
    int n;
    int t;
    scanf("%d%d", &n, &t);
    if ((t & ((1 << n) - 1)) == ((1 << n) - 1))
      printf("Case #%d: ON\n", output_file_ptr);
    else
      printf("Case #%d: OFF\n", output_file_ptr);

  }

  return 0;
}


