#include <stdio.h>
#include <string.h>
#include <malloc.h>
void Main()
{
  int first_iteration;
  int subject;
  scanf("%d", &subject);
  int b = 0;
  int heapn;
  int array[26] = {0};
  int rslt[10] = {0};
  char str[2001];
  while (b < subject)
  {
    b++;
    printf("Case #%d: ", b);
    scanf("%s", str);
    for (heapn = 0; heapn < 26; heapn++)
      array[heapn] = 0;

    for (heapn = 0; heapn < 10; heapn++)
      rslt[heapn] = 0;

    for (heapn = 0; heapn < strlen(str); heapn++)
    {
      array[str[heapn] - 'A']++;
    }

    if (array['Z' - 'A'] > 0)
    {
      rslt[0] += array['Z' - 'A'];
      array['E' - 'A'] -= array['Z' - 'A'];
      array['O' - 'A'] -= array['Z' - 'A'];
      array['R' - 'A'] -= array['Z' - 'A'];
      array['Z' - 'A'] = 0;
    }

    if (array['W' - 'A'] > 0)
    {
      rslt[2] += array['W' - 'A'];
      array['T' - 'A'] -= array['W' - 'A'];
      array['O' - 'A'] -= array['W' - 'A'];
      array['W' - 'A'] = 0;
    }

    if (array['U' - 'A'] > 0)
    {
      rslt[4] += array['U' - 'A'];
      array['F' - 'A'] -= array['U' - 'A'];
      array['O' - 'A'] -= array['U' - 'A'];
      array['R' - 'A'] -= array['U' - 'A'];
      array['U' - 'A'] = 0;
    }

    if (array['X' - 'A'] > 0)
    {
      rslt[6] += array['X' - 'A'];
      array['S' - 'A'] -= array['X' - 'A'];
      array['I' - 'A'] -= array['X' - 'A'];
      array['X' - 'A'] = 0;
    }

    if (array['G' - 'A'] > 0)
    {
      rslt[8] += array['G' - 'A'];
      array['E' - 'A'] -= array['G' - 'A'];
      array['I' - 'A'] -= array['G' - 'A'];
      array['H' - 'A'] -= array['G' - 'A'];
      array['T' - 'A'] -= array['G' - 'A'];
      array['G' - 'A'] = 0;
    }

    if (array['O' - 'A'] > 0)
    {
      rslt[1] += array['O' - 'A'];
      array['E' - 'A'] -= array['O' - 'A'];
      array['N' - 'A'] -= array['O' - 'A'];
    }

    if (array['H' - 'A'] > 0)
    {
      rslt[3] += array['H' - 'A'];
    }

    if (array['F' - 'A'] > 0)
    {
      rslt[5] += array['F' - 'A'];
    }

    if (array['S' - 'A'] > 0)
    {
      rslt[7] += array['S' - 'A'];
      array['N' - 'A'] -= array['S' - 'A'];
    }

    if (array['N' - 'A'] > 0)
    {
      rslt[9] += array['N' - 'A'] / 2;
    }

    int case_num;
    for (heapn = 0; heapn < 10; heapn++)
    {
      for (case_num = 0; case_num < rslt[heapn]; case_num++)
      {
        printf("%d", heapn);
      }

    }

    printf("\n");
  }

}


