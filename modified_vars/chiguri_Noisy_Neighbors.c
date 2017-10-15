#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int posb;
int l;
int k;
char key[101];
char target[101];
double keyRatio[26];
int keyNum[26];
int calcBananas(void)
{
  int i;
  int j;
  int aa;
  for (i = 1; i < l; ++i)
  {
    for (j = 0; target[i + j] != '\0'; ++j)
    {
      if (target[j] != target[i + j])
        break;

    }

    if (target[i + j] == '\0')
      break;

  }

  for (aa = 0; ((i * aa) + l) <= k; ++aa)
    ;

  return aa;
}

double onceTypable(void)
{
  int i;
  double x = posb;
  double ratio = 1.0;
  for (i = 0; i < posb; ++i)
  {
    ++keyNum[key[i] - 'A'];
  }

  for (i = 0; i < 26; ++i)
  {
    keyRatio[i] = ((double) keyNum[i]) / x;
  }

  for (i = 0; i < l; ++i)
  {
    ratio *= keyRatio[target[i] - 'A'];
  }

  return ratio;
}

double clear(void)
{
  double bananas = (double) calcBananas();
  double ratio = onceTypable();
  if (ratio == 0.0)
    return 0.0;

  return bananas - (ratio * ((k - l) + 1));
}

int Main(void)
{
  int datasetNo;
  int caseNo;
  int i;
  scanf("%d", &datasetNo);
  for (caseNo = 1; caseNo <= datasetNo; ++caseNo)
  {
    scanf("%d %d %d", &posb, &l, &k);
    for (i = 0; i < 26; ++i)
    {
      keyRatio[i] = 0.0;
      keyNum[i] = 0;
    }

    gets(key);
    gets(key);
    gets(target);
    key[posb] = '\0';
    target[l] = '\0';
    printf("Case #%d: %.7lf\n", caseNo, clear());
  }

  return 0;
}


