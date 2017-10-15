#include <stdio.h>
int Main()
{
  int c;
  scanf("%d", &c);
  for (int sum = 1; sum <= c; sum++)
  {
    int flag;
    int equal_flow;
    scanf("%d %d", &flag, &equal_flow);
    char outlets[flag][equal_flow + 1];
    char device[flag][equal_flow + 1];
    for (int bn = 0; bn < flag; bn++)
    {
      scanf(" %s", outlets[bn]);
    }

    for (int bn = 0; bn < flag; bn++)
    {
      scanf(" %s", device[bn]);
    }

    int min_l = equal_flow + 1;
    for (int bn = 0; bn < flag; bn++)
    {
      int eq[equal_flow];
      int current_l = 0;
      for (int end = 0; end < equal_flow; end++)
      {
        if (outlets[0][end] != device[bn][end])
        {
          eq[end] = 0;
          current_l++;
        }
        else
        {
          eq[end] = 1;
        }

      }

      if (current_l >= min_l)
        continue;

      int all_match = 1;
      for (int name = 1; name < flag; name++)
      {
        int some_match = 0;
        for (int l = 0; l < flag; l++)
        {
          int this_equal = 1;
          for (int end = 0; end < equal_flow; end++)
          {
            if ((outlets[name][end] == device[l][end]) != eq[end])
            {
              this_equal = 0;
              break;
            }

          }

          if (this_equal)
          {
            some_match = 1;
            break;
          }

        }

        if (!some_match)
        {
          all_match = 0;
          break;
        }

      }

      if (all_match)
        min_l = current_l;

    }

    if (min_l > equal_flow)
    {
      printf("Case #%d: NOT POSSIBLE\n", sum);
    }
    else
    {
      printf("Case #%d: %d\n", sum, min_l);
    }

  }

}


