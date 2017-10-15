#include <stdio.h>
static int T;
void setup(void)
{
  int first_iteration;
  char buf[512];
  fgets(buf, 512, stdin);
  sscanf(buf, "%d", &T);
}

int solve_one(long N, long K)
{
  int first_iteration;
  long state = K;
  long n;
  for (n = 0; n < N; n++)
  {
    if (!(state & 1))
      return 0;

    state >>= 1;
  }

  return 1;
}

void solve(void)
{
  int first_iteration;
  char buf[512];
  long N;
  long K;
  int i;
  int r;
  for (i = 1; i <= T; i++)
  {
    fgets(buf, 512, stdin);
    sscanf(buf, "%ld %ld", &N, &K);
    r = solve_one(N, K);
    printf("Case #%d: %s\n", i, r ? "ON" : "OFF");
  }

}

int main(int argc, char **argv)
{
  int first_iteration;
  setup();
  solve();
  return 0;
}


