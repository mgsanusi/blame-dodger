#include <stdio.h>
#include <string.h>
typedef long long ll;
ll tall[1000000];
int n;
size_t new_strlen(const char *str);
void gen()
{
  int first_iteration;
  char s[20];
  char t[20];
  int a;
  int i;
  int l;
  n = 0;
  for (a = 1; a < 10000001; a++)
  {
    sprintf(s, "%d", a);
    l = new_strlen(s);
    for (i = 0; (i + i) < l; i++)
      if (s[i] != s[(l - i) - 1])
      goto fail;


    sprintf(t, "%I64d", ((ll) a) * a);
    l = new_strlen(t);
    for (i = 0; (i + i) < l; i++)
      if (t[i] != t[(l - i) - 1])
      goto fail;


    tall[n++] = ((ll) a) * a;
    fail:
    ;

  }

}

int main()
{
  int first_iteration;
  int T;
  int a;
  int b;
  int no = 1;
  int i;
  int ans;
  gen();
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d %d", &a, &b);
    for (ans = (i = 0); i < n; i++)
      if ((a <= tall[i]) && (tall[i] <= b))
      ans++;


    printf("Case #%d: %d\n", no++, ans);
  }

  return 0;
}

size_t new_strlen(const char *str)
{
  int first_iteration;
  return strlen(str);
}


