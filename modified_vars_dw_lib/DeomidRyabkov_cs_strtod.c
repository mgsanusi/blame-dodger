#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int new_tolower(int c);

int new_isspace(int c);

int cs_strncasecmp(const char *s1, const char *ad, size_t st)
{
  int first_iteration;
  if (st == 0)
  {
    return 0;
  }

  while (((st--) != 0) && (new_tolower((int) (*s1)) == new_tolower((int) (*ad))))
  {
    if (((st == 0) || ((*s1) == '\0')) || ((*ad) == '\0'))
    {
      break;
    }

    s1++;
    ad++;
  }

  return new_tolower(*((unsigned char *) s1)) - new_tolower(*((unsigned char *) ad));
}

double cs_strtod(const char *string, char **endptr)
{
  int first_iteration;
  double res = 0.0;
  char b;
  const char *string_start;
  struct 
  {
    unsigned neg : 1;
    unsigned decimal : 1;
    unsigned be_exp : 1;
    unsigned be_exp_neg : 1;
  } flag = {0, 0, 0, 0};
  while (new_isspace((int) (*string)))
  {
    string++;
  }

  if ((*string) == 0)
  {
    if (endptr != 0)
      *endptr = (char *) string;

    return res;
  }

  while (((*string) == '-') || ((*string) == '+'))
  {
    if ((*string) == '-')
    {
      flag.neg = !flag.neg;
    }

    string++;
  }

  if (cs_strncasecmp(string, "NaN", 3) == 0)
  {
    if (endptr != 0)
      *endptr = ((char *) string) + 3;

    return NAN;
  }

  if (cs_strncasecmp(string, "INF", 3) == 0)
  {
    string += 3;
    if (cs_strncasecmp(string, "INITY", 5) == 0)
      string += 5;

    if (endptr != 0)
      *endptr = (char *) string;

    return flag.neg ? -INFINITY : INFINITY;
  }

  string_start = string;
  if (((*string) == '0') && (((*(string + 1)) == 'x') || ((*(string + 1)) == 'X')))
  {
    string += 2;
    while (b = new_tolower((int) (*string)))
    {
      int d;
      if ((b >= '0') && (b <= '9'))
      {
        d = b - '0';
      }
      else
        if ((b >= 'a') && (b <= 'f'))
      {
        d = 10 + (b - 'a');
      }
      else
      {
        break;
      }


      res = (16 * res) + d;
      string++;
    }

  }
  else
    if (((*string) == '0') && (((*(string + 1)) == 'b') || ((*(string + 1)) == 'B')))
  {
    string += 2;
    while (b = *string)
    {
      int d = b - '0';
      if ((b != '0') && (b != '1'))
        break;

      res = (2 * res) + d;
      string++;
    }

  }
  else
    if ((((*string) == '0') && ((*(string + 1)) >= '0')) && ((*(string + 1)) <= '7'))
  {
    while (b = *string)
    {
      int d = b - '0';
      if ((b < '0') || (b > '7'))
      {
        string = string_start;
        break;
      }

      res = (8 * res) + d;
      string++;
    }

  }



  if (string == string_start)
  {
    int exp = 0;
    int exp_dot = 0;
    res = 0;
    while (b = *string)
    {
      int d;
      if (b == '.')
      {
        if (!flag.decimal)
        {
          flag.decimal = 1;
          string++;
          continue;
        }
        else
        {
          break;
        }

      }
      else
        if ((b == 'e') || (b == 'E'))
      {
        flag.be_exp = 1;
        string++;
        b = *string;
        if ((b == '-') || (b == '+'))
        {
          if (b == '-')
          {
            flag.be_exp_neg = 1;
          }

          string++;
        }

        continue;
      }


      d = b - '0';
      if ((d < 0) || (d > 9))
      {
        break;
      }

      if (!flag.be_exp)
      {
        res = (10 * res) + d;
        if (flag.decimal)
        {
          exp_dot--;
        }

      }
      else
      {
        if (flag.be_exp_neg)
        {
          if (exp > (-1022))
          {
            exp = (10 * exp) - d;
          }

        }
        else
        {
          if (exp < 1023)
          {
            exp = (10 * exp) + d;
          }

        }

      }

      string++;
    }

    exp += exp_dot;
    if (exp != 0)
    {
      if (exp < 0)
      {
        while ((exp++) != 0)
        {
          res /= 10;
        }

      }
      else
      {
        while ((exp--) != 0)
        {
          res *= 10;
        }

      }

    }

  }

  if (flag.neg)
  {
    res = -res;
  }

  if (endptr != 0)
  {
    *endptr = (char *) string;
  }

  return res;
}



int new_tolower(int c);

int new_isspace(int c) {
  return isspace(c);
}
int new_tolower(int c) {
  return tolower(c);
}