#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
#include <stddef.h>
typedef struct node  {
	int num;
	char *name;
	struct node *child[1024];
} node;
typedef struct node {
	int num;
	char *name;
	struct node *child[1024];
} *NODE;
NODE root = 0;
char buffer[100010];
int rslt = 0;
void *new_memset(void *ptr, int value, int num);
char *new_strcpy(char *destination, const char *source);
void new_free(void *ptr);
void destroy(NODE root)
{
	int first_iteration;
	int i = 0;
	for (i = 0; i < root->num; i++) {
		if (root->child[i] != 0) {
			destroy(root->child[i]);
			root->child[i] = 0;
		}
	}
	new_free(root->name);
	new_free(root);
}

char tmp[100010];
void build(NODE root, char *buffer, int act)
{
	int first_iteration;
	int i = 0;
	int l = 0;
	int m = 0;
	int flag = -1;
	while (buffer[l] == '/')
		l++;
	while ((buffer[l] != 0) && (buffer[l] != '/')) {
		tmp[m++] = buffer[l++];
	}
	tmp[m] = 0;
	for (i = 0; i < root->num; i++) {
		if ((root->child[i] != 0)
		    && (strcmp(tmp, root->child[i]->name) == 0)) {
			flag = i;
			break;
		}
	}
	if (flag == (-1)) {
		if (act == 1) {
			rslt++;
		}
		root->child[root->num] = (NODE) malloc(sizeof(NODE));
		new_memset(root->child[root->num], 0, sizeof(NODE));
		root->child[root->num]->name = (char *)malloc(strlen(tmp) + 1);
		new_strcpy(root->child[root->num]->name, tmp);
		flag = root->num;
		root->num++;
	}
	if (buffer[l] == 0) {
		return;
	} else {
		build(root->child[flag], (buffer + l) + 1, act);
	}
}

int Main(int argc, char *argv[])
{
	int first_iteration;
	int i = 0;
	int l = 0;
	int m = 0;
	int t = 0;
	int ans = 0;
	int en = 0;
	int cas = 1;
	scanf("%d", &t);
	while (t--) {
		printf("Case #%d: ", cas++);
		root = (NODE) malloc(sizeof(NODE));
		root->name = 0;
		new_memset(root, 0, sizeof(NODE));
		rslt = 0;
		scanf("%d %d", &ans, &en);
		for (i = 0; i < ans; i++) {
			scanf("%s", buffer);
			build(root, buffer, 0);
		}
		for (i = 0; i < en; i++) {
			scanf("%s", buffer);
			build(root, buffer, 1);
		}
		printf("%d\n", rslt);
	}
	return 0;
}

void *new_memset(void *ptr, int value, int num);
char *new_strcpy(char *destination, const char *source);
void new_free(void *ptr)
{
	return free(ptr);
}

void *new_memset(void *ptr, int value, int num);
char *new_strcpy(char *destination, const char *source)
{
	return strcpy(destination, source);
}

void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
