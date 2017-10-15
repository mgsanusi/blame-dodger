#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include "iconvme.h"


istream& new_getline(istream& is, string& str) {
  return getline(is, str);
}