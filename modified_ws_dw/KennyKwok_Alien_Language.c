#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void print_word(int wordz, char word[5000][20])
{
  int first_iteration;
  return;
  int c;
  for (c = 0; c < wordz; c++)
  {
    printf("%d: %s\n", c, word[c]);
  }

}

void print_map(int mapz, int map[15][26], char *word)
{
  int first_iteration;
  return;
  int i;
  int j;
  for (i = 0; i < mapz; i++)
  {
    printf("->#%d: ", i);
    for (j = 0; j < 26; j++)
    {
      if (map[i][j] > 0)
      {
        printf(" %c(%d)", j + 'a', map[i][j]);
      }

    }

    printf("\n");
  }

  return;
}

int cal(int L, int map[15][26], int wordz, char word[5000][20])
{
  int first_iteration;
  int count = 0;
  int i;
  int j;
  for (i = 0; i < wordz; i++)
  {
    int p_hit = 1;
    for (j = 0; j < L; j++)
    {
      if (map[j][word[i][j] - 'a'] <= 0)
      {
        p_hit = 0;
        break;
      }

    }

    if (p_hit)
    {
      count++;
    }

  }

  return count;
}

int main(int argc, char *argv[])
{
  int first_iteration;
  char buf[4096];
  FILE *in = stdin;
  int c;
  int L;
  int D;
  int N;
  char word[5000][20];
  int wordz;
  int a_order[256];
  buf[0] = 0;
  fgets(buf, 4096, in);
  sscanf(buf, "%d %d %d", &L, &D, &N);
  wordz = 0;
  memset(word, 0, sizeof(word));
  for (c = 0; c < D; c++)
  {
    buf[0] = 0;
    fgets(buf, 4096, in);
    sscanf(buf, "%s", word[wordz++]);
  }

  {
    for (c = 0; c < 255; c++)
    {
      a_order[c] = -1;
    }

    for (c = 0; c < L; c++)
    {
      a_order[(int) word[0][c]] = c;
    }

  }
  print_word(wordz, word);
  for (c = 0; c < N; c++)
  {
    char tmp[4096];
    int map[15][26];
    buf[0] = 0;
    fgets(buf, 4096, in);
    sscanf(buf, "%s", tmp);
    {
      int i;
      int bracket = 0;
      int p = 0;
      memset(map, 0, sizeof(map));
      for (i = 0; i < strlen(tmp); i++)
      {
        if (tmp[i] == '(')
        {
          bracket++;
        }
        else
          if (tmp[i] == ')')
        {
          bracket--;
          p++;
        }
        else
          if ((tmp[i] >= 'a') && (tmp[i] <= 'z'))
        {
          map[p][((int) tmp[i]) - 'a'] = 1;
          if (!bracket)
            p++;

        }
        else
        {
        }



        if (p >= L)
          break;

      }

    }
    print_map(L, map, word[0]);
    printf("Case #%d: ", c + 1);
    printf("%d\n", cal(L, map, wordz, word));
  }

  return 0;
}


