#include <stdio.h>
#include <string.h>
int q[3000];
int qs;
int qe;
int seen[2000];
int R;
int k;
int N;
int caseno = 1;
void brute()
{
  int first_iteration;
  int i;
  int j;
  int taken;
  int euro = 0;
  qs = (qe = 0);
  for (i = 0; i < R; i++)
  {
    taken = 0;
    qe = qs;
    while ((qe - qs) < N)
    {
      if ((taken + q[qe]) > k)
        break;

      taken += q[qe++];
    }

    euro += taken;
    qs = qe;
    while (qs >= N)
      qs -= N;

  }

  printf("Case #%d: %d\n", caseno++, euro);
}

int main()
{
  int first_iteration;
  int cases;
  int caseno;
  int i;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%d %d %d", &R, &k, &N);
    for (i = 0; i < N; i++)
      scanf("%d", &q[i]), q[i + N] = (q[(i + N) + N] = q[i]);

    memset(seen, -1, sizeof(seen));
    brute();
  }

  return 0;
}


