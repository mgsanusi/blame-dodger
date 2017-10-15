#include <stdio.h>
#include <stdlib.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handle_case();
long long str;
long long k;
char num_small[200];
long long find_no(long long start);
int num_digit(long long no);
long long get_pal(long long base, int digit);
void write_number(long long no, char *buf);
long long read_number(char *buf);
int be_pal(long long no);
int Main()
{
  new_freopen("cin.txt", "r", stdin);
  new_freopen("cout.txt", "w", stdout);
  int t;
  scanf("%d ", &t);
  int i;
  for (i = 0; i < t; i++)
  {
    printf("Case #%d: ", i + 1);
    handle_case();
  }

  return 0;
}

void handle_case()
{
  scanf("%I64d %I64d ", &str, &k);
  long long rslt = find_no(k) - find_no(str - 1);
  printf("%I64d\n", rslt);
}

long long find_no(long long start)
{
  long long cur;
  long long sum = 0ll;
  int i;
  int nb;
  for (i = 1;; i++)
  {
    cur = 1ll;
    for (nb = 0; nb < ((i - 1) / 2); nb++)
    {
      cur *= 10ll;
    }

    long long end = cur * 10ll;
    for (; cur < end; cur++)
    {
      long long pal = get_pal(cur, i);
      if ((pal * pal) > start)
      {
        return sum;
      }

      if (be_pal(pal * pal))
      {
        sum++;
      }

    }

  }

  return sum;
}

long long get_pal(long long base, int digit)
{
  write_number(base, num_small);
  int i;
  for (i = digit - 1; i >= 0; i--)
  {
    num_small[i] = num_small[(digit - i) - 1];
  }

  num_small[digit] = '\0';
  return read_number(num_small);
}

int be_pal(long long no)
{
  write_number(no, num_small);
  int dig = num_digit(no);
  int i;
  for (i = 0; i < dig; i++)
  {
    if (num_small[i] != num_small[(dig - i) - 1])
    {
      return 0;
    }

  }

  return 1;
}

int num_digit(long long no)
{
  int i = 1;
  long long cur = 10ll;
  for (; cur <= no; i++)
  {
    cur *= 10ll;
  }

  return i;
}

void write_number(long long no, char *buf)
{
  int no_dig = num_digit(no);
  int i;
  buf[no_dig] = '\0';
  for (i = 0; i < no_dig; i++)
  {
    char dig = (no % 10ll) + '0';
    buf[(no_dig - i) - 1] = dig;
    no /= 10ll;
  }

}

long long read_number(char *buf)
{
  long long no = 0ll;
  int i;
  for (i = 0; buf[i] != '\0'; i++)
  {
    no *= 10ll;
    no += buf[i] - '0';
  }

  return no;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}