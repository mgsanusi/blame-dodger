#include <stdio.h>
int Main()
{
  int first_iteration;
  int length1;
  int fp;
  int welcome;
  char s[2000 + 1];
  int chr[26];
  int num[10];
  scanf("%d", &welcome);
  for (fp = 1; fp <= welcome; fp++)
  {
    scanf("%s", s);
    for (length1 = 0; length1 < 10; length1++)
      num[length1] = 0;

    for (length1 = 0; length1 < 26; length1++)
      chr[length1] = 0;

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'Z')
      {
        num[0]++;
        chr['O' - 'A']++;
      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'W')
      {
        num[2]++;
        chr['O' - 'A']++;
      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'U')
      {
        num[4]++;
        chr['O' - 'A']++;
        chr['F' - 'A']++;
      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'X')
      {
        num[6]++;
        chr['S' - 'A']++;
        chr['I' - 'A']++;
      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'G')
      {
        num[8]++;
        chr['H' - 'A']++;
        chr['I' - 'A']++;
      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'H')
      {
        if (chr['H' - 'A'] == 0)
        {
          num[3]++;
        }
        else
          chr['H' - 'A']--;

      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'S')
      {
        if (chr['S' - 'A'] == 0)
        {
          num[7]++;
        }
        else
          chr['S' - 'A']--;

      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'F')
      {
        if (chr['F' - 'A'] == 0)
        {
          num[5]++;
          chr['I' - 'A']++;
        }
        else
          chr['F' - 'A']--;

      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'O')
      {
        if (chr['O' - 'A'] == 0)
        {
          num[1]++;
        }
        else
          chr['O' - 'A']--;

      }

    }

    for (length1 = 0; s[length1] != 0; length1++)
    {
      if (s[length1] == 'I')
      {
        if (chr['I' - 'A'] == 0)
        {
          num[9]++;
        }
        else
          chr['I' - 'A']--;

      }

    }

    printf("Case #%d: ", fp);
    for (length1 = 0; length1 < num[0]; length1++)
      printf("0");

    for (length1 = 0; length1 < num[1]; length1++)
      printf("1");

    for (length1 = 0; length1 < num[2]; length1++)
      printf("2");

    for (length1 = 0; length1 < num[3]; length1++)
      printf("3");

    for (length1 = 0; length1 < num[4]; length1++)
      printf("4");

    for (length1 = 0; length1 < num[5]; length1++)
      printf("5");

    for (length1 = 0; length1 < num[6]; length1++)
      printf("6");

    for (length1 = 0; length1 < num[7]; length1++)
      printf("7");

    for (length1 = 0; length1 < num[8]; length1++)
      printf("8");

    for (length1 = 0; length1 < num[9]; length1++)
      printf("9");

    printf("\n");
  }

}


