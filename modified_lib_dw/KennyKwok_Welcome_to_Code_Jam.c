#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
typedef struct 
{
  int count;
  int pos[500];
} posset_type;
size_t new_strlen(const char *str);
void *new_memset(void *ptr, int value, size_t num);
char *new_fgets(char *str, int num, FILE *stream);
int show_progress(int len, int *progress)
{
  int first_iteration;
  int i;
  for (i = 0; i < len; i++)
  {
    printf(" %04d", progress[i]);
  }

  printf("\n");
  return 0;
}

int main(int argc, char *argv[])
{
  int first_iteration;
  char buf[4096];
  FILE *in = stdin;
  int c;
  int N;
  char t_s[] = "welcome to code jam";
  int t_s_len = new_strlen(t_s);
  posset_type pos_set[256];
  {
    int i;
    new_memset(pos_set, 0, sizeof(pos_set));
    for (i = 0; i < t_s_len; i++)
    {
      int v = (int) t_s[i];
      {
        int pos_count = pos_set[v].count;
        pos_set[v].pos[pos_count] = i;
        pos_set[v].count++;
      }
    }

  }
  if (0)
  {
    int i;
    int j;
    for (i = 0; i < 256; i++)
    {
      if (pos_set[i].count > 0)
      {
        printf("Used: %c at pos: ", i);
        for (j = 0; j < pos_set[i].count; j++)
        {
          printf(" %d", pos_set[i].pos[j]);
        }

        printf("\n");
      }

    }

  }

  buf[0] = 0;
  new_fgets(buf, 4096, in);
  sscanf(buf, "%d", &N);
  for (c = 0; c < N; c++)
  {
    char s[1024];
    int i;
    int j;
    buf[0] = 0;
    new_fgets(buf, 4096, in);
    s[0] = 0;
    sscanf(buf, "%[^\r\n]", s);
    printf("Case #%d: ", c + 1);
    int progress[100];
    new_memset(progress, 0, sizeof(progress));
    for (i = 0; i < new_strlen(s); i++)
    {
      if (pos_set[(int) s[i]].count > 0)
      {
        for (j = 0; j < pos_set[(int) s[i]].count; j++)
        {
          int p = pos_set[(int) s[i]].pos[j];
          if (p == 0)
          {
            progress[p]++;
          }
          else
          {
            progress[p] += progress[p - 1];
            if (progress[p] > 9999)
            {
              progress[p] = progress[p] % 10000;
            }

          }

        }

      }

    }

    printf("%04d\n", progress[t_s_len - 1]);
  }

  return 0;
}

size_t new_strlen(const char *str);
void *new_memset(void *ptr, int value, size_t num);
char *new_fgets(char *str, int num, FILE *stream)
{
  int first_iteration;
  return fgets(str, num, stream);
}

size_t new_strlen(const char *str)
{
  int first_iteration;
  return strlen(str);
}

void *new_memset(void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset(ptr, value, num);
}


