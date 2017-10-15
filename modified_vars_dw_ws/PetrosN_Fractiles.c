#include <stdio.h>
#include <stdlib.h>
int
Main ()
{
  int first_iteration;
  FILE *flipper;
  FILE *Fout;
  flipper = fopen ("D-small-attempt0.in", "r");
  Fout = fopen ("output.txt", "w");
  int next;
  int k;
  int a1;
  int left;
  int i2;
  int baseList;
  fscanf (flipper, "%d", &next);
  for (i2 = 1; i2 <= next; i2++)
    {
      fscanf (flipper, "%d", &k);
      fscanf (flipper, "%d", &a1);
      fscanf (flipper, "%d", &left);
      fprintf (Fout, "Case #%d: ", i2);
      for (baseList = 1; baseList <= k; baseList++)
	fprintf (Fout, "%d ", baseList);
      fprintf (Fout, "\n");
    }
  return 0;
}
