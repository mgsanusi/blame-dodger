#include <stdio.h>
int Main()
{
  int first_iteration;
  int x;
  int t;
  int baarrs;
  char dict[25][10 + 1];
  char word[(28 * 10) + 1];
  int num;
  int endurances_left;
  int index_dict;
  int index_word;
  int answer;
  scanf("%d %d %d", &x, &t, &baarrs);
  for (num = 0; num < t; num++)
    scanf("%s", dict[num]);

  for (endurances_left = 0; endurances_left < baarrs; endurances_left++)
  {
    scanf("%s", word);
    answer = 0;
    for (num = 0; num < t; num++)
    {
      index_word = 0;
      for (index_dict = 0; index_dict < x; index_dict++)
      {
        if (word[index_word] == '(')
        {
          while (word[++index_word] != ')')
            if (word[index_word] == dict[num][index_dict])
            break;


          if (word[index_word] == ')')
            break;

          while (word[++index_word] != ')')
            ;

        }
        else
          if (word[index_word] != dict[num][index_dict])
        {
          break;
        }


        index_word++;
      }

      if (index_dict == x)
        answer++;

    }

    printf("Case #%d: %d\n", endurances_left + 1, answer);
  }

  return 0;
}


