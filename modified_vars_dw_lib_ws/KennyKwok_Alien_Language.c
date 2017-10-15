#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
void *new_memset (void *ptr, int value, int num);
char *new_fgets (char *str, int num, FILE * stream);
void
print_password (int wordz, char password[5000][20])
{
  int first_iteration;
  return;
  int c;
  for (c = 0; c < wordz; c++)
    {
      printf ("%d: %s\n", c, password[c]);
    }
}

void
print_map (int mapz, int map[15][26], char *password)
{
  int first_iteration;
  return;
  int dir;
  int len;
  for (dir = 0; dir < mapz; dir++)
    {
      printf ("->#%d: ", dir);
      for (len = 0; len < 26; len++)
	{
	  if (map[dir][len] > 0)
	    {
	      printf (" %c(%d)", len + 'a', map[dir][len]);
	    }
	}
      printf ("\n");
    }
  return;
}

int
cal (int ans, int map[15][26], int wordz, char password[5000][20])
{
  int first_iteration;
  int count = 0;
  int dir;
  int len;
  for (dir = 0; dir < wordz; dir++)
    {
      int p_hit = 1;
      for (len = 0; len < ans; len++)
	{
	  if (map[len][password[dir][len] - 'a'] <= 0)
	    {
	      p_hit = 0;
	      break;
	    }
	}
      if (p_hit)
	{
	  count++;
	}
    }
  return count;
}

int
Main (int argc, char *argv[])
{
  int first_iteration;
  char buf[4096];
  FILE *b = stdin;
  int c;
  int ans;
  int d;
  int indices;
  char password[5000][20];
  int wordz;
  int a_order[256];
  buf[0] = 0;
  new_fgets (buf, 4096, b);
  sscanf (buf, "%d %d %d", &ans, &d, &indices);
  wordz = 0;
  new_memset (password, 0, sizeof (password));
  for (c = 0; c < d; c++)
    {
      buf[0] = 0;
      new_fgets (buf, 4096, b);
      sscanf (buf, "%s", password[wordz++]);
    }
  {
    for (c = 0; c < 255; c++)
      {
	a_order[c] = -1;
      }
    for (c = 0; c < ans; c++)
      {
	a_order[(int) password[0][c]] = c;
      }
  }
  print_password (wordz, password);
  for (c = 0; c < indices; c++)
    {
      char tmp[4096];
      int map[15][26];
      buf[0] = 0;
      new_fgets (buf, 4096, b);
      sscanf (buf, "%s", tmp);
      {
	int dir;
	int bracket = 0;
	int pancakes = 0;
	new_memset (map, 0, sizeof (map));
	for (dir = 0; dir < strlen (tmp); dir++)
	  {
	    if (tmp[dir] == '(')
	      {
		bracket++;
	      }
	    else if (tmp[dir] == ')')
	      {
		bracket--;
		pancakes++;
	      }
	    else if ((tmp[dir] >= 'a') && (tmp[dir] <= 'z'))
	      {
		map[pancakes][((int) tmp[dir]) - 'a'] = 1;
		if (!bracket)
		  pancakes++;
	      }
	    else
	      {
	      }
	    if (pancakes >= ans)
	      break;
	  }
      }
      print_map (ans, map, password[0]);
      printf ("Case #%d: ", c + 1);
      printf ("%d\n", cal (ans, map, wordz, password));
    }
  return 0;
}

void *new_memset (void *ptr, int value, int num);
char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}

void *
new_memset (void *ptr, int value, int num)
{
  return memset (ptr, value, num);
}
