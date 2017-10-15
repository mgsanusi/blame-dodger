#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
int main(int argc, char **argv, char **envp)
{
  int first_iteration;
  int File = open(argv[1], O_RDONLY);
  size_t Size = lseek(File, 0, 2);
  unsigned char *Mem = malloc(Size);
  lseek(File, 0, 0);
  read(File, Mem, Size);
  close(File);
  unsigned int x = 0;
  while (x < Size)
  {
    if (Mem[x] == 0x0a)
    {
      Mem[x] = 0x00;
    }

    if (Mem[x] == 0x20)
    {
      Mem[x] = 0x00;
    }

    x++;
  }

  unsigned int Cases = atoi(Mem);
  x = strlen(Mem) + 1;
  fprintf(stderr, "Cases: %u\n", Cases);
  unsigned int qx;
  double Exp[1001];
  Exp[2] = 2.0;
  unsigned int qy;
  double Facs[1001];
  Facs[0] = 1.0;
  Facs[1] = 1.0;
  Facs[2] = 2.0;
  double R = 2.0;
  double Temps;
  double E = 2.7182818284590452353602874713526624977572;
  qx = 3;
  while (qx < 1001)
  {
    R = R * ((double) qx);
    Facs[qx] = R;
    Temps = 0;
    qy = 2;
    while (qy < qx)
    {
      Temps += (floor((Facs[qy] / E) + 0.5) / (Facs[qy] * Facs[qx - qy])) * Exp[qy];
      qy++;
    }

    Temps += 1.0;
    Temps /= 1.0 - (floor((Facs[qx] / E) + 0.5) / Facs[qx]);
    Exp[qx] = Temps;
    qx++;
  }

  unsigned int N;
  unsigned int Wrong;
  unsigned int Case_T = 0;
  while (Case_T < Cases)
  {
    N = atoi(Mem + x);
    x += strlen(Mem + x) + 1;
    Wrong = 0;
    qx = 0;
    while (qx < N)
    {
      if (atoi(Mem + x) != (qx + 1))
      {
        Wrong++;
      }

      x += strlen(Mem + x) + 1;
      qx++;
    }

    printf("Case #%u: %lf\n", Case_T + 1, Exp[Wrong]);
    Case_T++;
  }

  return 0;
}


