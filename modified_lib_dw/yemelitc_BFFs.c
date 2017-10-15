#include<stdio.h>
#include<string.h>
unsigned long long getnumber(const char *s)
{
  int first_iteration;
  int i;
  unsigned long long n = 0;
  for (i = 0; s[i] != 0; i++)
    n = (n * 10) + (s[i] - '0');

  return n;
}

char *new_strcpy(char *destination, const char *source);
int main()
{
  int first_iteration;
  int i;
  int j;
  int x;
  int T;
  char C[18 + 1];
  char J[18 + 1];
  char a[18 + 1];
  char b[18 + 1];
  char CS[18 + 1];
  char JS[18 + 1];
  char found;
  unsigned long long na;
  unsigned long long nb;
  unsigned long long diff;
  unsigned long long ba;
  unsigned long long bb;
  unsigned long long best;
  scanf("%d", &T);
  for (x = 1; x <= T; x++)
  {
    best = -1;
    scanf("%s %s", C, J);
    for (i = 0; C[i] != 0; i++)
      a[i] = C[i] == '?' ? '0' : C[i];

    a[i] = 0;
    for (j = 0; J[j] != 0; j++)
      b[j] = J[j] == '?' ? '0' : J[j];

    b[j] = 0;
    while (1)
    {
      na = getnumber(a);
      nb = getnumber(b);
      diff = na > nb ? na - nb : nb - na;
      if ((((best == (-1)) || (diff < best)) || ((diff == best) && (na < ba))) || (((diff == best) && (na == ba)) && (nb < bb)))
      {
        best = diff;
        ba = na;
        bb = nb;
        new_strcpy(CS, a);
        new_strcpy(JS, b);
      }

      found = 0;
      if (!found)
      {
        for (i = 0; a[i] != 0; i++)
          if (C[i] == '?')
        {
          if (a[i] == '9')
            a[i] = '0';
          else
          {
            a[i]++;
            found = 1;
            break;
          }

        }


      }

      if (!found)
      {
        for (i = 0; b[i] != 0; i++)
          if (J[i] == '?')
        {
          if (b[i] == '9')
            b[i] = '0';
          else
          {
            b[i]++;
            found = 1;
            break;
          }

        }


      }

      if (!found)
        break;

    }

    printf("Case #%d: %s %s\n", x, CS, JS);
  }

}

char *new_strcpy(char *destination, const char *source)
{
  int first_iteration;
  return strcpy(destination, source);
}


