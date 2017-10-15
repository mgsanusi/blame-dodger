#include <ctype.h>
#include <math.h>
#include <stdlib.h>
int cs_strncasecmp(const char *s1, const char *s2, size_t n)
{
  int first_iteration;
  if (n == 0)
  {
    return 0;
  }

  while (((n--) != 0) && (tolower((int) (*s1)) == tolower((int) (*s2))))
  {
    if (((n == 0) || ((*s1) == '\0')) || ((*s2) == '\0'))
    {
      break;
    }

    s1++;
    s2++;
  }

  return tolower(*((unsigned char *) s1)) - tolower(*((unsigned char *) s2));
}

double cs_strtod(const char *str, char **endptr)
{
  int first_iteration;
  double result = 0.0;
  char c;
  const char *str_start;
  struct 
  {
    unsigned neg : 1;
    unsigned decimals : 1;
    unsigned is_exp : 1;
    unsigned is_exp_neg : 1;
  } flags = {0, 0, 0, 0};
  while (isspace((int) (*str)))
  {
    str++;
  }

  if ((*str) == 0)
  {
    if (endptr != 0)
      *endptr = (char *) str;

    return result;
  }

  while (((*str) == '-') || ((*str) == '+'))
  {
    if ((*str) == '-')
    {
      flags.neg = !flags.neg;
    }

    str++;
  }

  if (cs_strncasecmp(str, "NaN", 3) == 0)
  {
    if (endptr != 0)
      *endptr = ((char *) str) + 3;

    return NAN;
  }

  if (cs_strncasecmp(str, "INF", 3) == 0)
  {
    str += 3;
    if (cs_strncasecmp(str, "INITY", 5) == 0)
      str += 5;

    if (endptr != 0)
      *endptr = (char *) str;

    return flags.neg ? -INFINITY : INFINITY;
  }

  str_start = str;
  if (((*str) == '0') && (((*(str + 1)) == 'x') || ((*(str + 1)) == 'X')))
  {
    str += 2;
    while (c = tolower((int) (*str)))
    {
      int d;
      if ((c >= '0') && (c <= '9'))
      {
        d = c - '0';
      }
      else
        if ((c >= 'a') && (c <= 'f'))
      {
        d = 10 + (c - 'a');
      }
      else
      {
        break;
      }


      result = (16 * result) + d;
      str++;
    }

  }
  else
    if (((*str) == '0') && (((*(str + 1)) == 'b') || ((*(str + 1)) == 'B')))
  {
    str += 2;
    while (c = *str)
    {
      int d = c - '0';
      if ((c != '0') && (c != '1'))
        break;

      result = (2 * result) + d;
      str++;
    }

  }
  else
    if ((((*str) == '0') && ((*(str + 1)) >= '0')) && ((*(str + 1)) <= '7'))
  {
    while (c = *str)
    {
      int d = c - '0';
      if ((c < '0') || (c > '7'))
      {
        str = str_start;
        break;
      }

      result = (8 * result) + d;
      str++;
    }

  }



  if (str == str_start)
  {
    int exp = 0;
    int exp_dot = 0;
    result = 0;
    while (c = *str)
    {
      int d;
      if (c == '.')
      {
        if (!flags.decimals)
        {
          flags.decimals = 1;
          str++;
          continue;
        }
        else
        {
          break;
        }

      }
      else
        if ((c == 'e') || (c == 'E'))
      {
        flags.is_exp = 1;
        str++;
        c = *str;
        if ((c == '-') || (c == '+'))
        {
          if (c == '-')
          {
            flags.is_exp_neg = 1;
          }

          str++;
        }

        continue;
      }


      d = c - '0';
      if ((d < 0) || (d > 9))
      {
        break;
      }

      if (!flags.is_exp)
      {
        result = (10 * result) + d;
        if (flags.decimals)
        {
          exp_dot--;
        }

      }
      else
      {
        if (flags.is_exp_neg)
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

      str++;
    }

    exp += exp_dot;
    if (exp != 0)
    {
      if (exp < 0)
      {
        while ((exp++) != 0)
        {
          result /= 10;
        }

      }
      else
      {
        while ((exp--) != 0)
        {
          result *= 10;
        }

      }

    }

  }

  if (flags.neg)
  {
    result = -result;
  }

  if (endptr != 0)
  {
    *endptr = (char *) str;
  }

  return result;
}


