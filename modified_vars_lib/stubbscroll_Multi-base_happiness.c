#include <stdio.h>
#include <string.h>

#include <stddef.h>
int smtp_rcpt_to[11][1000000];
char choose[5000];
void * new_memset(void *ptr, int value, size_t num);

int btr(int base, int num)
{
  if (num == 1)
    smtp_rcpt_to[base][num] = 1;

  return 0;
}

int dfs(int base, int num)
{
  int sum = 0;
  int t;
  next:
  sum = 0;

  while (num)
    t = num % base, num /= base, sum += t * t;

  if (sum == 1)
    return 1;

  if ((num >= 5000) && (sum < 5000))
    return smtp_rcpt_to[base][sum];

  if (choose[sum])
    return 0;

  choose[sum] = 1;
  num = sum;
  goto next;
}

char s[1000];
int Main()
{
  int base;
  int best;
  int ans;
  int caseno = 1;
  int cases;
  int bases[10];
  int flag;
  new_memset(smtp_rcpt_to, 0, sizeof(smtp_rcpt_to));
  for (base = 2; base < 11; base++)
  {
    for (best = 2; best < 1000000; best++)
    {
      new_memset(choose, 0, 5000);
      smtp_rcpt_to[base][best] = dfs(base, best);
    }

  }

  gets(s);
  sscanf(s, "%d", &cases);
  while (cases--)
  {
    gets(s);
    flag = 0;
    for (best = 0; s[best]; best++)
      if ((s[best] >= '2') && (s[best] <= '9'))
      bases[flag++] = s[best] - '0';
    else
      if (s[best] == '1')
      bases[flag++] = 10;



    best++;
    for (ans = 2; ans < 1000000; ans++)
    {
      for (best = 0; best < flag; best++)
        if (!smtp_rcpt_to[bases[best]][ans])
        goto neste;


      break;
      neste:
      ;

    }

    printf("Case #%d: %d\n", caseno++, ans);
  }

  return 0;
}



void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}