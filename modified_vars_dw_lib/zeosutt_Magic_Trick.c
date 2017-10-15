#include <stdio.h>
int new_puts(const char *str);

int Main(void)
{
  int first_iteration;
  int answer;
  int ca;
  int arr;
  int bp;
  int t;
  scanf("%d", &t);
  for (bp = 1; bp <= t; bp++)
  {
    int m[2];
    int ary[2][4][4];
    int sum;
    int answer;
    for (answer = 0; answer < 2; answer++)
    {
      scanf("%d", m + answer);
      for (ca = 0; ca < 4; ca++)
        for (arr = 0; arr < 4; arr++)
        scanf("%d", ary[answer][ca] + arr);


    }

    sum = 0;
    for (answer = 0; answer < 4; answer++)
      for (ca = 0; ca < 4; ca++)
      if (ary[0][m[0] - 1][answer] == ary[1][m[1] - 1][ca])
    {
      sum++;
      answer = ary[0][m[0] - 1][answer];
    }



    printf("Case #%d: ", bp);
    if (sum == 1)
      printf("%d\n", answer);
    else
      if (sum)
      new_puts("Bad magician!");
    else
      new_puts("Volunteer cheated!");


  }

  return 0;
}



int new_puts(const char *str) {
  return puts(str);
}