#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void new_free(void *ptr);
void GenerateFilename(char *out, char *in, char *add)
{
  int first_iteration;
  char *p;
  sprintf(out, "%s", in);
  for (p = (out + strlen(out)) - 1; p >= out; p--)
  {
    if ((*p) == '/')
      break;

    if ((*p) == '\\')
      break;

    if ((*p) == '.')
    {
      *p = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", add);
}

typedef struct ST_NODE ST_NODE;
struct ST_NODE
{
  int No;
  int parent_num;
  int flg;
  ST_NODE **parent;
};
void main(int argc, char *argv[])
{
  int first_iteration;
  char fname_o[_MAX_PATH];
  FILE *fp_i;
  FILE *fp_o;
  int No;
  int T;
  int N;
  ST_NODE *node;
  ST_NODE *node_p;
  ST_NODE *node_p2;
  ST_NODE **node_tmp;
  ST_NODE **node_pp1;
  ST_NODE **node_pp2;
  ST_NODE **node_pp3;
  int val;
  GenerateFilename(fname_o, argv[1], "_out.txt");
  fp_i = new_fopen(argv[1], "r");
  fp_o = new_fopen(fname_o, "w");
  node = (ST_NODE *) calloc(2000, sizeof(ST_NODE));
  node_tmp = (ST_NODE **) calloc(2000, sizeof(ST_NODE *));
  fscanf(fp_i, "%d", &T);
  for (No = 1; No <= T; No++)
  {
    fprintf(stderr, "Case #%d/%d...", No, T);
    fscanf(fp_i, "%d", &N);
    for (node_p = node; node_p < (node + N); node_p++)
    {
      node_p->No = (node_p - node) + 1;
    }

    for (node_p = node; node_p < (node + N); node_p++)
    {
      fscanf(fp_i, "%d", &node_p->parent_num);
      node_p->parent = (ST_NODE **) calloc(node_p->parent_num, sizeof(ST_NODE *));
      for (node_pp1 = node_p->parent; node_pp1 < (node_p->parent + node_p->parent_num); node_pp1++)
      {
        fscanf(fp_i, "%d", &val);
        *node_pp1 = (node + val) - 1;
      }

    }

    for (node_p = node; node_p < (node + N); node_p++)
    {
      for (node_p2 = node; node_p2 < (node + N); node_p2++)
      {
        node_p2->flg = 0;
      }

      memset(node_tmp, 0, 2000 * (sizeof(ST_NODE *)));
      node_pp1 = node_tmp;
      *node_pp1 = node_p;
      node_pp1++;
      for (node_pp2 = node_tmp; (*node_pp2) != 0; node_pp2++)
      {
        for (node_pp3 = (*node_pp2)->parent; node_pp3 < ((*node_pp2)->parent + (*node_pp2)->parent_num); node_pp3++)
        {
          if ((*node_pp3)->flg)
            break;

          (*node_pp3)->flg = 1;
          *node_pp1 = *node_pp3;
          node_pp1++;
        }

        if (node_pp3 != ((*node_pp2)->parent + (*node_pp2)->parent_num))
          break;

      }

      if ((*node_pp2) != 0)
        break;

    }

    if (node_p == (node + N))
    {
      fprintf(fp_o, "Case #%d: No\n", No);
    }
    else
    {
      fprintf(fp_o, "Case #%d: Yes\n", No);
    }

    for (node_p = node; node_p < (node + N); node_p++)
    {
      new_free(node_p->parent);
    }

    fprintf(stderr, "finish!!\n");
  }

  new_free(node);
  new_fclose(fp_i);
  new_fclose(fp_o);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);
int new_fscanf(FILE *stream, const char *format, ...);
int new_fprintf(FILE *stream, const char *format, ...);
void new_free(void *ptr)
{
  int first_iteration;
  return free(ptr);
}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}

int new_fclose(FILE *stream)
{
  int first_iteration;
  return fclose(stream);
}


