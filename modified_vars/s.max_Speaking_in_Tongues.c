#include <stdio.h>
int Main()
{
  char trans[50] = "yhesocvxduiglbkrztnwjpfmaq";
  char niz[1000];
  int e2;
  int rightMost;
  fgets(niz, 1000, stdin);
  sscanf(niz, "%d", &e2);
  for (rightMost = 1; rightMost <= e2; rightMost++)
  {
    int xHandy;
    fgets(niz, 1000, stdin);
    for (xHandy = 0; niz[xHandy]; xHandy++)
      if ((niz[xHandy] != ' ') && (niz[xHandy] != '\n'))
      niz[xHandy] = trans[niz[xHandy] - 'a'];


    printf("Case #%d: %s", rightMost, niz);
  }

  return 0;
}


