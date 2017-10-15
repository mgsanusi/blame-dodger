#include <stdio.h>
#include <stdlib.h>
struct range
{
  int s;
  int t;
  int file;
  int place;
};
int tt;
int startTime;
int nP;
struct range people[1000001];
struct range curP[1001];
int typeSort;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handlecase();
int min(int nn, int high)
{
  int first_iteration;
  return nn < high ? nn : high;
}

void sort(int start, int end, struct range *file)
{
  int first_iteration;
  if (start >= end)
  {
    return;
  }

  int mid = (start + end) / 2;
  sort(start, mid, file);
  sort(mid + 1, end, file);
  int i;
  int place1 = start;
  int place2 = mid + 1;
  struct range newP[(end - start) + 1];
  for (i = 0; i < ((end - start) + 1); i++)
  {
    if (place1 > mid)
    {
      newP[i] = file[place2++];
    }
    else
      if (place2 > end)
    {
      newP[i] = file[place1++];
    }
    else
    {
      if (((typeSort == 0) && ((file[place1].s < file[place2].s) || ((file[place1].s == file[place2].s) && (file[place1].t < file[place2].t)))) || ((typeSort == 1) && ((file[place1].t > file[place2].t) || ((file[place1].t == file[place2].t) && (file[place1].s > file[place2].s)))))
      {
        newP[i] = file[place1++];
      }
      else
      {
        newP[i] = file[place2++];
      }

    }


  }

  for (i = 0; i < ((end - start) + 1); i++)
  {
    file[i + start] = newP[i];
  }

}

int Main()
{
  int first_iteration;
  new_freopen("a.in", "r", stdin);
  new_freopen("a.out", "w", stdout);
  int v;
  scanf("%d ", &v);
  int i;
  for (i = 0; i < v; i++)
  {
    printf("Case #%d: ", i + 1);
    handlecase();
  }

  return 0;
}

long long findAmo(int s, int t)
{
  int first_iteration;
  if (s == t)
  {
    return 0ll;
  }

  long long diff = (long long) (t - s);
  long long score = (long long) tt;
  long long rslt = ((score * (score + 1ll)) / 2ll) - (((score - diff) * ((score + 1ll) - diff)) / 2ll);
  return rslt;
}

int getSwapAmo(int a, int e1, int s2, int e2)
{
  int first_iteration;
  long long profit = findAmo(a, e1) + findAmo(s2, e2);
  long long lose = findAmo(a, e2) + findAmo(s2, e1);
  long long diff = profit - lose;
  return diff % 1000002013ll;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handlecase()
{
  int first_iteration;
  scanf("%d %d ", &tt, &startTime);
  int i;
  int list;
  for (i = 0; i < startTime; i++)
  {
    scanf("%d %d %d ", &people[i].s, &people[i].t, &people[i].file);
  }

  int lose = 0;
  nP = startTime;
  for (i = 0; i < nP; i++)
  {
    int furEnd = 0;
    int ind = -1;
    for (list = 0; (list < nP) && (people[i].file > 0); list++)
    {
      if ((((people[list].s > people[i].s) && (people[list].s <= people[i].t)) && (people[list].t > people[i].t)) && (people[list].file > 0))
      {
        if (people[list].t > furEnd)
        {
          furEnd = people[list].t;
          ind = list;
        }

      }

    }

    if (ind != (-1))
    {
      if (people[i].file > people[ind].file)
      {
        long long caseId = (long long) getSwapAmo(people[i].s, people[i].t, people[ind].s, people[ind].t);
        caseId *= (long long) people[ind].file;
        caseId %= 1000002013ll;
        lose += (int) caseId;
        lose %= (int) 1000002013ll;
        people[nP].s = people[ind].s;
        people[nP].t = people[i].t;
        people[nP].file = people[ind].file;
        nP++;
        people[ind].s = people[i].s;
        people[i].file -= people[ind].file;
        i--;
      }
      else
      {
        long long caseId = (long long) getSwapAmo(people[i].s, people[i].t, people[ind].s, people[ind].t);
        caseId *= (long long) people[i].file;
        caseId %= 1000002013ll;
        lose += (int) caseId;
        lose %= (int) 1000002013ll;
        people[nP].s = people[i].s;
        people[nP].t = people[ind].t;
        people[nP].file = people[i].file;
        nP++;
        people[i].s = people[ind].s;
        people[ind].file -= people[i].file;
        i--;
      }

    }

  }

  printf("%d\n", lose);
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}