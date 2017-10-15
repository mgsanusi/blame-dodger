#include <stdio.h>
#include <string.h>
 enum 
{ MAX_SIDE = 128 
};
 char nextChar;		/* Holds the next unused char */
int H, W;
short map[MAX_SIDE][MAX_SIDE];
char drain[MAX_SIDE][MAX_SIDE];
 void
input (void) 
{
  int i, j;
   
    /* Reinitialize */ 
    memset (drain, 0, sizeof drain);
  nextChar = 'a';
   
    /* Read a map */ 
    scanf ("%d %d", &H, &W);
  for (i = 0; i < H; ++i)
    
    {
      for (j = 0; j < W; ++j)
	
	{
	  scanf ("%hd", &map[i][j]);
	}
    }
}

 int
getDirection (short x, short y) 
{
  static int direction;
  static int minElevation;
   direction = 0;
  minElevation = map[x][y];
   
    /* Check possible directions in order: North, West, East, South */ 
    if (x && map[x - 1][y] < minElevation)
    
    {
      minElevation = map[x - 1][y];
      direction = 1;
    }
  if (y && map[x][y - 1] < minElevation)
    
    {
      minElevation = map[x][y - 1];
      direction = 2;
    }
  if (y < W - 1 && map[x][y + 1] < minElevation)
    
    {
      minElevation = map[x][y + 1];
      direction = 3;
    }
  if (x < H - 1 && map[x + 1][y] < minElevation)
    
    {
      minElevation = map[x + 1][y];
      direction = 4;
    }
  return direction;
}

 int
dfs (short x, short y) 
{
  if (drain[x][y])
    
    {
      return drain[x][y];
    }
   switch (getDirection (x, y))
    
    {
    case 1:
      drain[x][y] = dfs (x - 1, y);
      break;
    case 2:
      drain[x][y] = dfs (x, y - 1);
      break;
    case 3:
      drain[x][y] = dfs (x, y + 1);
      break;
    case 4:
      drain[x][y] = dfs (x + 1, y);
      break;
    default:
      drain[x][y] = nextChar++;
    }
   return drain[x][y];
}

 void
printDrain (void) 
{
  int i, j;
   for (i = 0; i < H; i++)
    
    {
      for (j = 0; j < W - 1; j++)
	
	{
	  printf ("%c ", drain[i][j]);
	}
      printf ("%c\n", drain[i][j]);
    }
}

 void
calcDrain (void) 
{
  int i, j;
  for (i = 0; i < H; i++)
    
    {
      for (j = 0; j < W; j++)
	
	{
	  dfs (i, j);
	}
    }
}

 int
main (void) 
{
  int T;
  int test;
   scanf ("%d", &T);
  for (test = 1; test <= T; ++test)
    
    {
      input ();
      calcDrain ();
      printf ("Case #%d:\n", test);
      printDrain ();
    }
   return 0;
}


