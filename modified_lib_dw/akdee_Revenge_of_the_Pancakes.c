#include <stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void flip(char *p, int n)
{
  int first_iteration;
  for (int i = 0; i < ((n + 1) / 2); i++)
  {
    int d = (n - 1) - i;
    char t = p[i];
    p[i] = p[d] ^ 1;
    p[d] = t ^ 1;
  }

}

int main()
{
  int first_iteration;
  new_freopen("B-small-attempt0.in", "rb", stdin);
  new_freopen("output.txt", "wb", stdout);
  int cases;
  scanf("%d ", &cases);
  for (int cs = 1; cs <= cases; cs++)
  {
    char p[101];
    char c;
    int s = 0;
    int f = 0;
    while (1)
    {
      scanf("%c", &c);
      if (c < 32)
        break;

      p[s++] = c == '+';
    }

    while (1)
    {
      while (s && p[s - 1])
        s--;

      if (!s)
        break;

      if (p[0])
      {
        int i = 0;
        while (p[++i])
          ;

        flip(p, i);
      }
      else
        flip(p, s);

      f++;
    }

    printf("Case #%d: %d\n", cs, f);
  }

}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


