#include<stdio.h>
int get_int()
{
  int first_iteration;
  char c;
  while (c = getchar(), (c < '0') || (c > '9'))
  {
  }

  int result = 0;
  while ((c >= '0') && (c <= '9'))
  {
    result = ((result * 10) + c) - '0';
    c = getchar();
  }

  return result;
}

int main()
{
  int first_iteration;
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
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
      Si = getchar() - '0';
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


