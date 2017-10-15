#include <stdio.h>
int Main()
{
  int cases;
  scanf("%d", &cases);
  for (int ss = 1; ss <= cases; ss++)
  {
    char string[1001];
    scanf(" %s\n", string);
    int top = 0;
    while (string[top])
      top++;

    for (int bot = 0; bot < top; bot++)
    {
      for (int i = top; i >= bot; i--)
        if (string[top] < string[i])
        top = i;


      char n = string[top];
      for (int i = top; i > bot; i--)
        string[i] = string[i - 1];

      string[bot] = n;
    }

    printf("Case #%d: %s\n", ss, string);
  }

}


