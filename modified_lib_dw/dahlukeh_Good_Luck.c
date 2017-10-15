#include <stdio.h>
#include <stdlib.h>
struct range
{
  int s;
  int e;
  int p;
  int place;
};
int N;
int M;
int nP;
struct range people[1000001];
struct range curP[1001];
int typeSort;
FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void handlecase();
int min(int n1, int n2)
{
  int first_iteration;
  return n1 < n2 ? n1 : n2;
}

void sort(int start, int end, struct range *p)
{
  int first_iteration;
  if (start >= end)
  {
    return;
  }

  int mid = (start + end) / 2;
  sort(start, mid, p);
  sort(mid + 1, end, p);
  int i;
  int place1 = start;
  int place2 = mid + 1;
  struct range newP[(end - start) + 1];
  for (i = 0; i < ((end - start) + 1); i++)
  {
    if (place1 > mid)
    {
      newP[i] = p[place2++];
    }
    else
      if (place2 > end)
    {
      newP[i] = p[place1++];
    }
    else
    {
      if (((typeSort == 0) && ((p[place1].s < p[place2].s) || ((p[place1].s == p[place2].s) && (p[place1].e < p[place2].e)))) || ((typeSort == 1) && ((p[place1].e > p[place2].e) || ((p[place1].e == p[place2].e) && (p[place1].s > p[place2].s)))))
      {
        newP[i] = p[place1++];
      }
      else
      {
        newP[i] = p[place2++];
      }

    }


  }

  for (i = 0; i < ((end - start) + 1); i++)
  {
    p[i + start] = newP[i];
  }

}

int main()
{
  int first_iteration;
  new_freopen("a.in", "r", stdin);
  new_freopen("a.out", "w", stdout);
  int n;
  scanf("%d ", &n);
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Case #%d: ", i + 1);
    handlecase();
  }

  return 0;
}

long long findAmo(int s, int e)
{
  int first_iteration;
  if (s == e)
  {
    return 0ll;
  }

  long long diff = (long long) (e - s);
  long long lN = (long long) N;
  long long res = ((lN * (lN + 1ll)) / 2ll) - (((lN - diff) * ((lN + 1ll) - diff)) / 2ll);
  return res;
}

int getSwapAmo(int s1, int e1, int s2, int e2)
{
  int first_iteration;
  long long gain = findAmo(s1, e1) + findAmo(s2, e2);
  long long lose = findAmo(s1, e2) + findAmo(s2, e1);
  long long diff = gain - lose;
  return diff % 1000002013ll;
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream);
void handlecase()
{
  int first_iteration;
  scanf("%d %d ", &N, &M);
  int i;
  int j;
  for (i = 0; i < M; i++)
  {
    scanf("%d %d %d ", &people[i].s, &people[i].e, &people[i].p);
  }

  int lose = 0;
  nP = M;
  for (i = 0; i < nP; i++)
  {
    int furEnd = 0;
    int ind = -1;
    for (j = 0; (j < nP) && (people[i].p > 0); j++)
    {
      if ((((people[j].s > people[i].s) && (people[j].s <= people[i].e)) && (people[j].e > people[i].e)) && (people[j].p > 0))
      {
        if (people[j].e > furEnd)
        {
          furEnd = people[j].e;
          ind = j;
        }

      }

    }

    if (ind != (-1))
    {
      if (people[i].p > people[ind].p)
      {
        long long sw = (long long) getSwapAmo(people[i].s, people[i].e, people[ind].s, people[ind].e);
        sw *= (long long) people[ind].p;
        sw %= 1000002013ll;
        lose += (int) sw;
        lose %= (int) 1000002013ll;
        people[nP].s = people[ind].s;
        people[nP].e = people[i].e;
        people[nP].p = people[ind].p;
        nP++;
        people[ind].s = people[i].s;
        people[i].p -= people[ind].p;
        i--;
      }
      else
      {
        long long sw = (long long) getSwapAmo(people[i].s, people[i].e, people[ind].s, people[ind].e);
        sw *= (long long) people[i].p;
        sw %= 1000002013ll;
        lose += (int) sw;
        lose %= (int) 1000002013ll;
        people[nP].s = people[i].s;
        people[nP].e = people[ind].e;
        people[nP].p = people[i].p;
        nP++;
        people[i].s = people[ind].s;
        people[ind].p -= people[i].p;
        i--;
      }

    }

  }

  printf("%d\n", lose);
}

FILE *new_freopen(const char *filename, const char *mode, FILE *stream)
{
  int first_iteration;
  return freopen(filename, mode, stream);
}


