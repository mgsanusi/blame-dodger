#include <stdio.h>
int reaction_array[26][26];
int destruction_array[26][26];
int element_seen[26];
int main(void)
{
  int first_iteration;
  int i;
  int j;
  int k;
  int m;
  int flag;
  int tot_test_cases;
  int num_combine;
  int num_destroy;
  int num_string;
  char combine_str[4];
  char destroy_str[3];
  char input_str[100];
  char output_str[100];
  int output_len = 0;
  int new_element;
  int previous_element;
  scanf("%d", &tot_test_cases);
  for (i = 0; i < tot_test_cases; i++)
  {
    output_len = 0;
    for (j = 0; j < 26; j++)
    {
      element_seen[j] = 0;
      for (k = 0; k < 26; k++)
      {
        reaction_array[j][k] = -1;
        destruction_array[j][k] = 0;
      }

    }

    scanf("%d", &num_combine);
    for (; num_combine > 0; num_combine--)
    {
      scanf(" %s", combine_str);
      reaction_array[combine_str[0] - 'A'][combine_str[1] - 'A'] = combine_str[2] - 'A';
      reaction_array[combine_str[1] - 'A'][combine_str[0] - 'A'] = combine_str[2] - 'A';
    }

    scanf("%d", &num_destroy);
    for (; num_destroy > 0; num_destroy--)
    {
      scanf(" %s", destroy_str);
      destruction_array[destroy_str[0] - 'A'][destroy_str[1] - 'A'] = 1;
      destruction_array[destroy_str[1] - 'A'][destroy_str[0] - 'A'] = 1;
    }

    scanf("%d", &num_string);
    scanf(" %s", input_str);
    for (j = 0; j < num_string; j++)
    {
      new_element = input_str[j] - 'A';
      do
      {
        flag = 0;
        if (output_len != 0)
        {
          previous_element = output_str[output_len - 1] - 'A';
          if (reaction_array[new_element][previous_element] != (-1))
          {
            flag = 1;
            new_element = reaction_array[new_element][previous_element];
            output_len--;
            element_seen[previous_element]--;
            continue;
          }

          for (k = 0; k < 26; k++)
          {
            if (destruction_array[new_element][k] && element_seen[k])
            {
              flag = 2;
              for (m = 0; m < 26; m++)
              {
                element_seen[m] = 0;
                output_len = 0;
              }

              break;
            }

          }

        }

      }
      while ((flag != 0) && (flag != 2));
      if (flag != 2)
      {
        output_str[output_len++] = new_element + 'A';
        element_seen[new_element]++;
      }

    }

    printf("Case #%d: [", i + 1);
    for (m = 0; m < (output_len - 1); m++)
      printf("%c, ", output_str[m]);

    if (output_len != 0)
      printf("%c", output_str[output_len - 1]);

    printf("]\n");
  }

  return 1;
}


