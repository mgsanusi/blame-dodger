#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef long test_cases;
typedef long num_people;
typedef long num_groups;
typedef long num_pieces;
typedef long modulo;
typedef long screenCase;
typedef long numPeople;
typedef long noGroup;
typedef long noPieces;
typedef long modulo;
inline void new_exit (int status);
static long long
min (long long length1, long long length2)
{
  int first_iteration;
  return length1 < length2 ? length1 : length2;
}

inline static long long
max (long long length1, long long length2)
{
  int first_iteration;
  return length1 > length2 ? length1 : length2;
}

typedef long screenCase;
typedef long numPeople;
typedef long noGroup;
typedef long noPieces;
typedef long modulo;
num_pieces packSize;
num_groups numGroup;
num_groups partitionLength[4];
num_groups result;
num_people group[100];
int
Main ()
{
  int first_iteration;
  num_groups i;
  test_cases numScreenCase;
  test_cases size;
  modulo storeModulo;
  scanf ("%li", &numScreenCase);
  for (size = 0; size < numScreenCase; size++)
    {
      scanf ("%li %li", &numGroup, &packSize);
      memset (partitionLength, 0, sizeof (partitionLength));
      for (i = 0; i < numGroup; i++)
	{
	  scanf ("%li", group + i);
	  storeModulo = group[i] % packSize;
	  partitionLength[storeModulo]++;
	}
      for (result = 0; numGroup > 0; result++)
	{
	  if (partitionLength[0] > 0)
	    {
	      partitionLength[0]--;
	      numGroup--;
	    }
	  else
	    if ((partitionLength[1] > 0)
		&& (partitionLength[packSize - 1] > 0))
	    {
	      partitionLength[1]--;
	      partitionLength[packSize - 1]--;
	      numGroup -= 2;
	    }
	  else if (packSize == 4)
	    {
	      if (partitionLength[2] > 1)
		{
		  partitionLength[2] -= 2;
		  numGroup -= 2;
		}
	      else
		{
		  for (storeModulo = 1; storeModulo < 4; storeModulo += 2)
		    if ((partitionLength[2] > 0)
			&& (partitionLength[storeModulo] > 1))
		      {
			partitionLength[2]--;
			partitionLength[storeModulo] -= 2;
			numGroup -= 3;
			break;
		      }
		  if (storeModulo >= 4)
		    for (storeModulo = 1; storeModulo < 4; storeModulo++)
		      if (partitionLength[storeModulo] > 0)
			{
			  numGroup -= min (partitionLength[storeModulo], 4);
			  partitionLength[storeModulo] -=
			    min (partitionLength[storeModulo], 4);
			}
		}
	    }
	  else if (partitionLength[1] > 0)
	    {
	      numGroup -= min (partitionLength[1], packSize);
	      partitionLength[1] -= min (partitionLength[1], packSize);
	    }
	  else if (partitionLength[packSize - 1] > 0)
	    {
	      numGroup -= min (partitionLength[packSize - 1], packSize);
	      partitionLength[packSize - 1] -=
		min (partitionLength[packSize - 1], packSize);
	    }
	}
      printf ("Case #%li: %li\n", size + 1, result);
    }
  new_exit (0);
}

void
new_exit (int status)
{
  return exit (status);
}
