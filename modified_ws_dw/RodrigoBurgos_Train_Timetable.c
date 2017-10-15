#include <stdio.h>
#include <string.h>
int A[102][2];
int B[102][2];
int vis[2][102];
int tm;
int hash[2];
int na;
int nb;
int cont;
void revisa(int tiempo, int lado, int position)
{
  int first_iteration;
  int nextlado = (lado + 1) % 2;
  int x;
  vis[lado][position] = 1;
  int P = 1 << 22;
  int T = 1 << 22;
  for (x = 0; x < (nextlado == 0 ? na : nb); x++)
  {
    if (vis[nextlado][x] == 1)
      continue;

    if (nextlado == 0)
    {
      if ((A[x][0] >= tiempo) && (T > A[x][0]))
      {
        T = A[x][0];
        P = x;
      }

    }
    else
    {
      if ((B[x][0] >= tiempo) && (T > B[x][0]))
      {
        T = B[x][0];
        P = x;
      }

    }

  }

  if (P == (1 << 22))
    return;

  if (nextlado == 0)
    revisa(A[P][1] + tm, nextlado, P);
  else
    revisa(B[P][1] + tm, nextlado, P);

}

int main()
{
  int first_iteration;
  int h;
  int m;
  int set;
  int casos;
  int x;
  int pos;
  int num;
  int lado;
  freopen("rata.in", "r", stdin);
  freopen("salida.out", "w", stdout);
  for (scanf("%d", &casos), set = 1; (casos--) && (scanf("%d", &tm) != EOF); set++)
  {
    scanf("%d %d", &na, &nb);
    for (x = 0; x < na; x++)
    {
      scanf("%d:%d", &h, &m);
      A[x][0] = (h * 60) + m;
      scanf("%d:%d", &h, &m);
      A[x][1] = (h * 60) + m;
    }

    for (x = 0; x < nb; x++)
    {
      scanf("%d:%d", &h, &m);
      B[x][0] = (h * 60) + m;
      scanf("%d:%d", &h, &m);
      B[x][1] = (h * 60) + m;
    }

    cont = 0;
    memset(vis, 0, sizeof(vis));
    memset(hash, 0, sizeof(hash));
    while (1)
    {
      pos = -1;
      num = 1 << 22;
      lado = -1;
      for (x = 0; x < na; x++)
        if ((vis[0][x] == 0) && (A[x][0] < num))
      {
        num = A[x][0];
        lado = 0;
        pos = x;
      }


      for (x = 0; x < nb; x++)
        if ((vis[1][x] == 0) && (B[x][0] < num))
      {
        num = B[x][0];
        lado = 1;
        pos = x;
      }


      if (pos == (-1))
        break;

      if (lado == 0)
        revisa(A[pos][1] + tm, lado, pos);
      else
        revisa(B[pos][1] + tm, lado, pos);

      hash[lado]++;
    }

    printf("Case #%d: %d %d\n", set, hash[0], hash[1]);
  }

  return 0;
}


