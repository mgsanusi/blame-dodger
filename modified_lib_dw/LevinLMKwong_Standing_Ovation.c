#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_getchar();
int get_int()
{
  int first_iteration;
  char c;
  while (c = new_getchar(), (c < '0') || (c > '9'))
  {
  }

  int result = 0;
  while ((c >= '0') && (c <= '9'))
  {
    result = ((result * 10) + c) - '0';
    c = new_getchar();
  }

  return result;
}

int main()
{
  int first_iteration;
  new_freopen("A.in", "r", stdin);
  new_freopen("A.out", "w", stdout);
  int i;
  int t;
  int T;
  int S;
  int ans;
  int Si;
  int aud_count;
  T = get_int();
  for (t = 1; t <= T; t++)
  {
    S = get_int();
    ans = 0;
    aud_count = 0;
    for (i = 0; i <= S; i++)
    {
      Si = new_getchar() - '0';
      if (aud_count < i)
      {
        ans += i - aud_count;
        aud_count += i - aud_count;
      }

      aud_count += Si;
    }

    printf("Case #%d: %d\n", t, ans);
  }

}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int new_getchar()
{
  int first_iteration;
  return getchar();
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


