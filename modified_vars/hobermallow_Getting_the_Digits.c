#include<stdio.h>
int Main()
{
  int in;
  int g;
  int j;
  int n;
  int let[10];
  char q[2001];
  scanf("%d", &in);
  for (g = 0; g < in; g++)
  {
    for (j = 0; j < 10; j++)
      let[j] = 0;

    scanf("%s", q);
    for (j = 0; q[j] != '\0'; j++)
    {
      switch (q[j])
      {
        case 'Z':
          let[0]++;
          let[1]--;
          break;

        case 'W':
          let[2]++;
          let[1]--;
          let[3]--;
          break;

        case 'U':
          let[4]++;
          let[1]--;
          let[5]--;
          break;

        case 'X':
          let[6]++;
          let[7]--;
          break;

        case 'G':
          let[8]++;
          let[3]--;
          break;

        case 'O':
          let[1]++;
          break;

        case 'T':
          let[3]++;
          break;

        case 'F':
          let[5]++;
          break;

        case 'S':
          let[7]++;

      }

    }

    let[9] = ((((((((j - (4 * let[0])) - (3 * let[1])) - (3 * let[2])) - (5 * let[3])) - (4 * let[4])) - (4 * let[5])) - (3 * let[6])) - (5 * let[7])) - (5 * let[8]);
    let[9] /= 4;
    printf("Case #%d: ", g + 1);
    for (j = 0; j < 10; j++)
    {
      for (n = 0; n < let[j]; n++)
        printf("%d", j);

    }

    printf("\n");
  }

  return 0;
}


