#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
void GenerateFilename(char *out, char *in, char *add)
{
  int first_iteration;
  char *p;
  sprintf(out, "%s", in);
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

  sprintf(out + strlen(out), "%s", add);
}

void main(int argc, char *argv[])
{
  int first_iteration;
  char fname_o[_MAX_PATH];
  FILE *fp_i;
  FILE *fp_o;
  int T;
  int H;
  int W;
  int D;
  int No;
  int ii;
  int jj;
  int ROOM[30][30];
  int SIGHT[200][200];
  int RXi;
  int RXj;
  char buff[50];
  int sum;
  int a;
  int b;
  int Ri;
  int Rj;
  int dd;
  int kk;
  int ll;
  GenerateFilename(fname_o, argv[1], "_out.txt");
  fp_i = fopen(argv[1], "r");
  fp_o = fopen(fname_o, "w");
  fscanf(fp_i, "%d", &T);
  for (No = 1; No <= T; No++)
  {
    fscanf(fp_i, "%d", &H);
    fscanf(fp_i, "%d", &W);
    fscanf(fp_i, "%d", &D);
    for (ii = 0; ii < H; ii++)
    {
      fscanf(fp_i, "%s", buff);
      for (jj = 0; jj < W; jj++)
      {
        switch (buff[jj])
        {
          case '#':
            ROOM[ii][jj] = 1;
            break;

          case 'X':
            ROOM[ii][jj] = 0;
            RXi = ii;
            RXj = jj;
            break;

          case '.':
            ROOM[ii][jj] = 0;
            break;

        }

      }

    }

    for (ii = 0; ii < H; ii++)
    {
      for (jj = 0; jj < W; jj++)
      {
        if ((ii == RXi) && (jj == RXj))
        {
          printf(" X ");
        }
        else
        {
          printf("%2d ", ROOM[ii][jj]);
        }

      }

      printf("\n");
    }

    for (ii = -D; ii <= D; ii++)
    {
      for (jj = -D; jj <= D; jj++)
      {
        a = ((ii + RXi) - 1) % (H - 2);
        b = abs(((ii + RXi) - 1) / (H - 2));
        if (a < 0)
          b += 1;

        if (a < 0)
          a += H - 2;

        Ri = b % 2 ? (H - 2) - a : a + 1;
        a = ((jj + RXj) - 1) % (W - 2);
        b = abs(((jj + RXj) - 1) / (W - 2));
        if (a < 0)
          b += 1;

        if (a < 0)
          a += W - 2;

        Rj = b % 2 ? (W - 2) - a : a + 1;
        SIGHT[D + ii][D + jj] = (Ri == RXi) && (Rj == RXj) ? 1 : 0;
      }

    }

    sum = 0;
    for (dd = 1; dd <= D; dd++)
    {
      for (ii = -dd; ii <= dd; ii++)
      {
        for (jj = -dd; jj <= dd; jj++)
        {
          if ((abs(ii) != dd) && (abs(jj) != dd))
            continue;

          if (((ii * ii) + (jj * jj)) > (D * D))
            continue;

          if (SIGHT[D + ii][D + jj] == 1)
          {
            sum++;
            for (kk = -D; kk <= D; kk++)
            {
              if ((ii * kk) < 0)
                continue;

              for (ll = -D; ll <= D; ll++)
              {
                if ((jj * ll) < 0)
                  continue;

                if ((ii * ll) == (jj * kk))
                  SIGHT[D + kk][D + ll] = 0;

              }

            }

          }

        }

      }

    }

    fprintf(fp_o, "Case #%d: %d\n", No, sum);
  }

  fclose(fp_i);
  fclose(fp_o);
}


