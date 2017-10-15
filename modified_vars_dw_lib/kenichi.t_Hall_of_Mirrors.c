#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_abs(int x);

void generate_filename(char *out, char *q, char *total)
{
  int first_iteration;
  char *p;
  sprintf(out, "%s", q);
  for (p = (out + strlen(out)) - 1; p >= out; p--)
  {
    if ((*p) == '/')
      break;

    if ((*p) == '\\')
      break;

    if ((*p) == '.')
    {
      *p = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", total);
}

void Main(int argc, char *argv[])
{
  int first_iteration;
  char fname_o[_MAX_PATH];
  FILE *fp_index;
  FILE *fp_o;
  int len;
  int pg;
  int dp;
  int xx;
  int i;
  int i;
  int hi;
  int room[30][30];
  int sight[200][200];
  int rxi;
  int rxj;
  char buff[50];
  int total;
  int m;
  int y;
  int cur;
  int result;
  int played;
  int max;
  int mp;
  generate_filename(fname_o, argv[1], "_out.txt");
  fp_index = new_fopen(argv[1], "r");
  fp_o = new_fopen(fname_o, "w");
  fscanf(fp_index, "%d", &len);
  for (i = 1; i <= len; i++)
  {
    fscanf(fp_index, "%d", &pg);
    fscanf(fp_index, "%d", &dp);
    fscanf(fp_index, "%d", &xx);
    for (i = 0; i < pg; i++)
    {
      fscanf(fp_index, "%s", buff);
      for (hi = 0; hi < dp; hi++)
      {
        switch (buff[hi])
        {
          case '#':
            room[i][hi] = 1;
            break;

          case 'X':
            room[i][hi] = 0;
            rxi = i;
            rxj = hi;
            break;

          case '.':
            room[i][hi] = 0;
            break;

        }

      }

    }

    for (i = 0; i < pg; i++)
    {
      for (hi = 0; hi < dp; hi++)
      {
        if ((i == rxi) && (hi == rxj))
        {
          printf(" X ");
        }
        else
        {
          printf("%2d ", room[i][hi]);
        }

      }

      printf("\n");
    }

    for (i = -xx; i <= xx; i++)
    {
      for (hi = -xx; hi <= xx; hi++)
      {
        m = ((i + rxi) - 1) % (pg - 2);
        y = new_abs(((i + rxi) - 1) / (pg - 2));
        if (m < 0)
          y += 1;

        if (m < 0)
          m += pg - 2;

        cur = y % 2 ? (pg - 2) - m : m + 1;
        m = ((hi + rxj) - 1) % (dp - 2);
        y = new_abs(((hi + rxj) - 1) / (dp - 2));
        if (m < 0)
          y += 1;

        if (m < 0)
          m += dp - 2;

        result = y % 2 ? (dp - 2) - m : m + 1;
        sight[xx + i][xx + hi] = (cur == rxi) && (result == rxj) ? 1 : 0;
      }

    }

    total = 0;
    for (played = 1; played <= xx; played++)
    {
      for (i = -played; i <= played; i++)
      {
        for (hi = -played; hi <= played; hi++)
        {
          if ((new_abs(i) != played) && (new_abs(hi) != played))
            continue;

          if (((i * i) + (hi * hi)) > (xx * xx))
            continue;

          if (sight[xx + i][xx + hi] == 1)
          {
            total++;
            for (max = -xx; max <= xx; max++)
            {
              if ((i * max) < 0)
                continue;

              for (mp = -xx; mp <= xx; mp++)
              {
                if ((hi * mp) < 0)
                  continue;

                if ((i * mp) == (hi * max))
                  sight[xx + max][xx + mp] = 0;

              }

            }

          }

        }

      }

    }

    fprintf(fp_o, "Case #%d: %d\n", i, total);
  }

  new_fclose(fp_index);
  new_fclose(fp_o);
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_abs(int x) {
  return abs(x);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}