#include<stdio.h>
#include<string.h>

#include <stddef.h>
typedef long long ll;
struct act
{
  int p;
  int mutex_buf;
  int c;
  int p;
  int l;
  int dd;
  int y;
  int cases;
} b[20];
int ans2[100000];
int ch[100000];
int mutex_buf;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, size_t num);


void sort()
{
  int cf_stat;
  int length2;
  int p2;
  struct act tmp;
  for (cf_stat = 0; cf_stat < mutex_buf; cf_stat++)
  {
    if (b[cf_stat].mutex_buf == 0)
    {
      tmp = b[mutex_buf - 1];
      b[mutex_buf - 1] = b[cf_stat];
      b[cf_stat] = tmp;
      cf_stat--;
      mutex_buf--;
    }

  }

  for (cf_stat = 0; cf_stat < mutex_buf; cf_stat++)
  {
    for (length2 = 1; length2 < mutex_buf; length2++)
    {
      if (b[length2].p < b[length2 - 1].p)
      {
        tmp = b[length2];
        b[length2] = b[length2 - 1];
        b[length2 - 1] = tmp;
      }

    }

  }

}

int Main()
{
  new_freopen("C:\\TC\\BIN\\codejam2013\\in.txt", "r", stdin);
  new_freopen("C:\\TC\\BIN\\codejam2013\\out.txt", "w", stdout);
  int c;
  int ishappy;
  int cf_stat;
  int length2;
  int p2;
  int b;
  struct act tmp;
  scanf("%d", &c);
  for (ishappy = 1; ishappy <= c; ishappy++)
  {
    printf("Case #%d: ", ishappy);
    new_memset(&ans2, 0, sizeof(ans2));
    new_memset(&ch, 0, sizeof(ch));
    scanf("%d", &mutex_buf);
    for (cf_stat = 0; cf_stat < mutex_buf; cf_stat++)
    {
      scanf("%d %d %d %d %d %d %d %d", &b[cf_stat].p, &b[cf_stat].mutex_buf, &b[cf_stat].c, &b[cf_stat].p, &b[cf_stat].l, &b[cf_stat].dd, &b[cf_stat].y, &b[cf_stat].cases);
    }

    sort();
    b = 0;
    while (1)
    {
      for (cf_stat = 0;;)
      {
        for (length2 = 2 * b[cf_stat].c; length2 <= (2 * b[cf_stat].p); length2++)
        {
          if (length2 < 0)
          {
            if (ch[-length2] < b[cf_stat].l)
            {
              b++;
              break;
            }

          }
          else
          {
            if (ans2[length2] < b[cf_stat].l)
            {
              b++;
              break;
            }

          }

        }

        if ((((cf_stat + 1) < mutex_buf) && b[cf_stat + 1].mutex_buf) && (b[cf_stat + 1].p == b[cf_stat].p))
          cf_stat++;
        else
          break;

      }

      for (length2 = 0; length2 <= cf_stat; length2++)
      {
        for (p2 = 2 * b[length2].c; p2 <= (2 * b[length2].p); p2++)
        {
          if (p2 < 0)
          {
            if (ch[-p2] < b[length2].l)
              ch[-p2] = b[length2].l;

          }
          else
          {
            if (ans2[p2] < b[length2].l)
              ans2[p2] = b[length2].l;

          }

        }

        b[length2].mutex_buf--;
        b[length2].p += b[length2].dd;
        b[length2].c += b[length2].y;
        b[length2].p += b[length2].y;
        b[length2].l += b[length2].cases;
      }

      sort();
      if (mutex_buf == 0)
        break;

    }

    printf("%d\n", b);
  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}