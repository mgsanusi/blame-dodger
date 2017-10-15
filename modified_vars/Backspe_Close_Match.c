#include <stdio.h>
typedef long long ll;
char y_ed[20];
char _[20];
char ansc1[20];
char ansc2[20];
ll ans1;
ll ans2;
ll diff;
int c;
void ltcheck()
{
  ll buf1 = 0;
  ll k = 0;
  int counter;
  for (counter = 0; counter < c; counter++)
  {
    buf1 *= 10;
    k *= 10;
    buf1 += y_ed[counter] == '?' ? 9 : y_ed[counter] - '0';
    k += _[counter] == '?' ? 0 : _[counter] - '0';
  }

  if (((k - buf1) < diff) || (((k - buf1) == diff) && ((buf1 < ans1) || ((buf1 == ans1) && (k < ans2)))))
  {
    diff = k - buf1;
    ans1 = buf1;
    ans2 = k;
  }

}

void gtcheck()
{
  ll buf1 = 0;
  ll k = 0;
  int counter;
  for (counter = 0; counter < c; counter++)
  {
    buf1 *= 10;
    k *= 10;
    buf1 += y_ed[counter] == '?' ? 0 : y_ed[counter] - '0';
    k += _[counter] == '?' ? 9 : _[counter] - '0';
  }

  if (((buf1 - k) < diff) || (((buf1 - k) == diff) && ((buf1 < ans1) || ((buf1 == ans1) && (k < ans2)))))
  {
    diff = buf1 - k;
    ans1 = buf1;
    ans2 = k;
  }

}

int Main()
{
  int dll;
  int m;
  int counter;
  int j;
  int flag;
  scanf("%d", &m);
  for (dll = 1; dll <= m; dll++)
  {
    ans1 = 1ll << 62;
    ans2 = 0;
    diff = 1ll << 62;
    flag = 0;
    scanf("%s %s", y_ed, _);
    for (c = 0; y_ed[c] != '\0'; c++)
      ;

    for (counter = 0; counter < c; counter++)
    {
      if ((y_ed[counter] == '?') && (_[counter] == '?'))
      {
        y_ed[counter] = '0';
        _[counter] = '1';
        ltcheck();
        y_ed[counter] = '1';
        _[counter] = '0';
        gtcheck();
        y_ed[counter] = '0';
        _[counter] = '0';
        continue;
      }
      else
        if ((y_ed[counter] == '?') && (_[counter] != '?'))
      {
        if (_[counter] != '0')
        {
          y_ed[counter] = _[counter] - 1;
          ltcheck();
        }

        if (_[counter] != '9')
        {
          y_ed[counter] = _[counter] + 1;
          gtcheck();
        }

        y_ed[counter] = _[counter];
        continue;
      }
      else
        if ((y_ed[counter] != '?') && (_[counter] == '?'))
      {
        if (y_ed[counter] != '9')
        {
          _[counter] = y_ed[counter] + 1;
          ltcheck();
        }

        if (y_ed[counter] != '0')
        {
          _[counter] = y_ed[counter] - 1;
          gtcheck();
        }

        _[counter] = y_ed[counter];
        continue;
      }
      else
        if (y_ed[counter] == _[counter])
      {
        continue;
      }
      else
        if (y_ed[counter] < _[counter])
      {
        ltcheck();
        flag = 1;
        break;
      }
      else
        if (y_ed[counter] > _[counter])
      {
        gtcheck();
        flag = 1;
        break;
      }
      else
      {
        printf("ERROR!\n");
        flag = 1;
        break;
      }






    }

    if (flag == 0)
    {
      ltcheck();
    }

    ansc1[c] = (ansc2[c] = '\0');
    for (counter = 0; counter < c; counter++)
    {
      ansc1[(c - counter) - 1] = (ans1 % 10) + '0';
      ansc2[(c - counter) - 1] = (ans2 % 10) + '0';
      ans1 /= 10;
      ans2 /= 10;
    }

    printf("Case #%d: ", dll);
    printf("%s %s", ansc1, ansc2);
    printf("\n");
  }

}


