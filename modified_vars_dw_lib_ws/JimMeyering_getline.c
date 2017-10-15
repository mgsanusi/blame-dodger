#include <config.h>
#include <stdio.h>
istream & new_getline (istream & is, string & str)
{
  return getline (is, str);
}
