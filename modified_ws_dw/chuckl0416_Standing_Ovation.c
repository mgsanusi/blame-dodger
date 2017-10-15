#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
int TC;
int T;
int SMax;
char InputS[1200];
int i;
int x;
int y;
int Ans;
int Clapping;
int PeopleInLevel;
int main()
{
  int first_iteration;
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  scanf("%d", &TC);
  for (T = 1; T <= TC; T++)
  {
    printf("Case #%d: ", T);
    scanf("%d", &SMax);
    scanf("%s", InputS);
    Ans = 0;
    Clapping = 0;
    for (i = 0; i <= SMax; i++)
    {
      PeopleInLevel = InputS[i] - 48;
      if (!PeopleInLevel)
        continue;

      if (i <= Clapping)
      {
        Clapping += PeopleInLevel;
        continue;
      }

      Ans += i - Clapping;
      Clapping = i + PeopleInLevel;
    }

    printf("%d\n", Ans);
  }

  return 0;
}


