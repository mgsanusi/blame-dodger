#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int get_T(void)
{
    char buf[80];
    fgets(buf, 80, stdin);
    return atoi(buf);
}

static char pathes[100000];
struct d {
    char *name;
    struct d *next;
    struct d *child;
};
static struct d _top = {
    .name = "root",
    .next = NULL,
    .child = NULL,
};

static struct d *top = &_top;
static int checkadd(struct d *parent, char *name, struct d **ret)
{
    struct d *p;
    p = parent->child;
    while (p) {
	//fprintf(stderr, "c:%s/%s\n", p->name, name);
	if (!strcmp(p->name, name)) {
	    *ret = p;
	    return 0;
	}
	p = p->next;
    }
    //fprintf(stderr, "m:%s/%s\n", parent->name, name);
    p = malloc(sizeof(struct d));
    p->name = strdup(name);
    p->child = NULL;
    p->next = parent->child ? parent->child : NULL;
    parent->child = p;
    *ret = p;
    return 1;
}

static int checkaddpath(char *p)
{
    int y, i;
    int len;
    char *name;
    struct d *di = top;
    struct d *ret;
    y = 0;
    len = strlen(p);
    name = p;
    for (i = 1; i < len; i++) {
	if (p[i] == '/' || p[i] == '\n') {
	    p[i] = 0;
	    y += checkadd(di, name, &ret);
	    di = ret;
	    name = p + i + 1;
	}
    }
    return y;
}

static void solve(int x)
{
    char buf[256];
    int N, M, i, y;
    char *p;
    struct d *di;
    fgets(buf, 256, stdin);
    sscanf(buf, "%d %d", &N, &M);
    top->child = NULL;
    p = pathes;
    for (i = 0; i < N; i++) {
	fgets(p, 100000, stdin);
	checkaddpath(p + 1);
    }
    y = 0;
    for (i = 0; i < M; i++) {
	fgets(p, 100000, stdin);
	y += checkaddpath(p + 1);
    }
    printf("Case #%d: %d\n", x, y);
}

int main(int argc, char **argv)
{
    int i, T;
    T = get_T();
    for (i = 1; i <= T; i++)
	solve(i);
    return 0;
}