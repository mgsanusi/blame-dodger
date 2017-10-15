#include <stdio.h>
#include <stdlib.h>
struct cards
{
  int c;
  int s;
  int t;
};
int numStart;
int numDeck;
struct cards deck[81];
int hasInHand[81];
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int findBest(int numDraw);
void handleCase(void);
int main()
{
  int first_iteration;
  new_freopen("input.txt", "r", stdin);
  new_freopen("output.txt", "w", stdout);
  int numT;
  scanf("%d ", &numT);
  int i;
  for (i = 0; i < numT; i++)
  {
    printf("Case #%d: ", i + 1);
    handleCase();
  }

  return 0;
}

void handleCase(void)
{
  int first_iteration;
  scanf("%d ", &numStart);
  int i;
  for (i = 0; i < numStart; i++)
  {
    scanf("%d %d %d ", &deck[i].c, &deck[i].s, &deck[i].t);
  }

  scanf("%d ", &numDeck);
  for (; i < (numStart + numDeck); i++)
  {
    scanf("%d %d %d ", &deck[i].c, &deck[i].s, &deck[i].t);
  }

  int result;
  int best = 0;
  for (i = 0; i < 80; i++)
  {
    result = findBest(i);
    if (result > best)
    {
      best = result;
    }

  }

  printf("%d\n", best);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
int findBest(int numDraw)
{
  int first_iteration;
  int i;
  for (i = 0; i < (numStart + numDeck); i++)
  {
    hasInHand[i] = 1;
  }

  int score = 0;
  int turns = 1;
  int draw = 0;
  int toPlay = -1;
  while (turns > 0)
  {
    turns--;
    toPlay = -1;
    for (i = 0; (i < (numStart + draw)) && (i < (numStart + numDeck)); i++)
    {
      if (hasInHand[i] == 1)
      {
        if (toPlay == (-1))
        {
          toPlay = i;
        }

        if (deck[i].t > 0)
        {
          toPlay = i;
        }
        else
          if (deck[toPlay].t == 0)
        {
          if ((deck[i].c > 0) && ((numDraw - draw) > 0))
          {
            if ((deck[i].s > deck[toPlay].s) || (deck[toPlay].c == 0))
            {
              toPlay = i;
            }

          }
          else
            if (!((deck[toPlay].c > 0) && ((numDraw - draw) > 0)))
          {
            if (deck[i].s > deck[toPlay].s)
            {
              toPlay = i;
            }

          }


        }


      }

    }

    if (toPlay != (-1))
    {
      turns += deck[toPlay].t;
      draw += deck[toPlay].c;
      score += deck[toPlay].s;
      hasInHand[toPlay] = 0;
    }

  }

  return score;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


