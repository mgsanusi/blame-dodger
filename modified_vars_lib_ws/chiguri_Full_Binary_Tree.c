#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sol;
int next_button_blue;
char input[7000];
char *arr;
char lr[41];
struct tree
{
  struct tree *left;
  struct tree *right;
} *exit;
struct tree
{
  struct tree *left;
  struct tree *right;
} *device;
void
lend (struct tree *t)
{
  char p = *(arr++);
  if ((p != '0') && (p != '1'))
    {
    }
  else
    {
      if (p == '0')
	{
	  if (t->left)
	    {
	      lend (t->left);
	    }
	  else
	    {
	      t->left = (struct tree *) malloc (sizeof (struct tree));
	      t->left->left = (t->left->right = 0);
	      lend (t->left);
	    }
	}
      else
	{
	  if (t->right)
	    {
	      lend (t->right);
	    }
	  else
	    {
	      t->right = (struct tree *) malloc (sizeof (struct tree));
	      t->right->left = (t->right->right = 0);
	      lend (t->right);
	    }
	}
    }
}

void
init (struct tree *t)
{
  if (t->left)
    init (t->left);
  if (t->right)
    init (t->right);
  free (t);
}

int
search (struct tree *arr, struct tree *r, int total)
{
  int t;
  if (arr == 0)
    {
      if (r == 0)
	{
	  return 0;
	}
      else
	{
	  return 10000;
	}
    }
  if (r == 0)
    {
      return 10000;
    }
  if (lr[total++] == 0)
    {
      if ((t = search (arr->left, r->left, total)) > 1000)
	return 10000;
      return t + search (arr->right, r->right, total);
    }
  else
    {
      if ((t = search (arr->left, r->right, total)) > 1000)
	return 10000;
      return t + search (arr->right, r->left, total);
    }
}

int
search_res (int total)
{
  int t1;
  int kkk;
  if (total == sol)
    return search (exit, device, 0);
  lr[total] = 0;
  t1 = search_res (total + 1);
  lr[total] = 1;
  kkk = search_res (total + 1) + 1;
  return t1 < kkk ? t1 : kkk;
}

int
Main (void)
{
  int num;
  int try_num;
  int total;
  int j;
  int k;
  scanf ("%d", &num);
  for (try_num = 1; try_num <= num; ++try_num)
    {
      exit = (struct tree *) malloc (sizeof (struct tree));
      device = (struct tree *) malloc (sizeof (struct tree));
      exit->left = (exit->right = (device->left = (device->right = 0)));
      scanf ("%d %d", &next_button_blue, &sol);
      gets (input);
      gets (input);
      arr = input;
      for (total = 0; total < next_button_blue; ++total)
	{
	  lend (exit);
	}
      gets (input);
      arr = input;
      for (total = 0; total < next_button_blue; ++total)
	{
	  lend (device);
	}
      printf ("Case #%d: ", try_num);
      total = search_res (0);
      if (total > 1000)
	{
	  printf ("NOT POSSIBLE\n");
	}
      else
	{
	  printf ("%d\n", total);
	}
      init (exit);
      init (device);
    }
  return 0;
}
