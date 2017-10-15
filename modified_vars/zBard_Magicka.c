#include <stdio.h>
int reaction_arr[26][26];
int destruction_array[26][26];
int element_seen[26];
int Main(void)
{
  int base;
  int bx;
  int v;
  int w;
  int flag;
  int tot_screen_case;
  int no_combine;
  int num_destroy;
  int no_str;
  char combine_str[4];
  char destroy_string[3];
  char input_str[100];
  char output_string[100];
  int output_len = 0;
  int new_element;
  int former_element;
  scanf("%d", &tot_screen_case);
  for (base = 0; base < tot_screen_case; base++)
  {
    output_len = 0;
    for (bx = 0; bx < 26; bx++)
    {
      element_seen[bx] = 0;
      for (v = 0; v < 26; v++)
      {
        reaction_arr[bx][v] = -1;
        destruction_array[bx][v] = 0;
      }

    }

    scanf("%d", &no_combine);
    for (; no_combine > 0; no_combine--)
    {
      scanf(" %s", combine_str);
      reaction_arr[combine_str[0] - 'A'][combine_str[1] - 'A'] = combine_str[2] - 'A';
      reaction_arr[combine_str[1] - 'A'][combine_str[0] - 'A'] = combine_str[2] - 'A';
    }

    scanf("%d", &num_destroy);
    for (; num_destroy > 0; num_destroy--)
    {
      scanf(" %s", destroy_string);
      destruction_array[destroy_string[0] - 'A'][destroy_string[1] - 'A'] = 1;
      destruction_array[destroy_string[1] - 'A'][destroy_string[0] - 'A'] = 1;
    }

    scanf("%d", &no_str);
    scanf(" %s", input_str);
    for (bx = 0; bx < no_str; bx++)
    {
      new_element = input_str[bx] - 'A';
      do
      {
        flag = 0;
        if (output_len != 0)
        {
          former_element = output_string[output_len - 1] - 'A';
          if (reaction_arr[new_element][former_element] != (-1))
          {
            flag = 1;
            new_element = reaction_arr[new_element][former_element];
            output_len--;
            element_seen[former_element]--;
            continue;
          }

          for (v = 0; v < 26; v++)
          {
            if (destruction_array[new_element][v] && element_seen[v])
            {
              flag = 2;
              for (w = 0; w < 26; w++)
              {
                element_seen[w] = 0;
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
        output_string[output_len++] = new_element + 'A';
        element_seen[new_element]++;
      }

    }

    printf("Case #%d: [", base + 1);
    for (w = 0; w < (output_len - 1); w++)
      printf("%c, ", output_string[w]);

    if (output_len != 0)
      printf("%c", output_string[output_len - 1]);

    printf("]\n");
  }

  return 1;
}


