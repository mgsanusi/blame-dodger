#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
void *swapchair;
int main(int argc, char **argv, char **envp)
{
  int first_iteration;
  int File = open(argv[1], O_RDONLY);
  size_t Size = lseek(File, 0, 2);
  char *Mem = malloc(Size);
  lseek(File, 0, 0);
  read(File, Mem, Size);
  close(File);
  unsigned int q = 0;
  while (q < Size)
  {
    if (Mem[q] == 0x0a)
    {
      Mem[q] = 0x00;
    }

    if (Mem[q] == 0x20)
    {
      Mem[q] = 0x00;
    }

    q++;
  }

  unsigned int Cases = atoi(Mem);
  q = strlen(Mem) + 1;
  fprintf(stderr, "Cases: %u\n", Cases);
  unsigned int Case_T = 0;
  int64_t N;
  int64_t P;
  while (Case_T < Cases)
  {
    N = atoll(Mem + q);
    q += strlen(Mem + q) + 1;
    P = atoll(Mem + q);
    q += strlen(Mem + q) + 1;
    int64_t pp = P - 1;
    int64_t x = 1LL << (N - 1);
    int64_t add = 2;
    int64_t worstans = 0;
    if (P == (1LL << N))
    {
      worstans = P - 1;
      goto e;
    }

    while (pp >= x)
    {
      worstans += add;
      pp -= x;
      add <<= 1;
      x >>= 1;
    }

    e:
    1;

    x = 2;
    int64_t y = 1LL << (N - 1);
    int64_t bestans = 0;
    while (x <= P)
    {
      bestans += y;
      y >>= 1;
      x <<= 1;
    }

    printf("Case #%u: %lld %lld\n", Case_T + 1, worstans, bestans);
    Case_T++;
  }

  return 0;
}


