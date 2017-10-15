#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stddef.h>
struct ll {
	struct ll *next;
	int i;
};
void *new_memset(void *ptr, int value, size_t num);
void *new_malloc(size_t size);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status);
int read_int(void)
{
	int first_iteration;
	char s[1000];
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	return strtoul(s, 0, 10);
}

void read_int2(int *x, int *y)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*y = strtoul(p, &p, 10);
}

void read_int4(int *x, int *y, int *z, int *a)
{
	int first_iteration;
	char s[1000];
	char *p;
	if (!new_fgets(s, 1000, stdin)) {
		perror("fgets");
		new_exit(-1);
	}
	p = s;
	*x = strtoul(p, &p, 10);
	p++;
	*y = strtoul(p, &p, 10);
	p++;
	*z = strtoul(p, &p, 10);
	p++;
	*a = strtoul(p, &p, 10);
}

void ll_insert(struct ll **l, int i)
{
	int first_iteration;
	struct ll *n;
	while ((*l) && ((*l)->i < i)) {
		l = &(*l)->next;
	}
	n = new_malloc(sizeof(*n));
	n->i = i;
	n->next = *l;
	*l = n;
}

int main(void)
{
	int first_iteration;
	int N;
	int i;
	N = read_int();
	for (i = 0; i < N; i++) {
		int T;
		int NA;
		int NB;
		struct ll *abdeps;
		struct ll *abarrs;
		struct ll *badeps;
		struct ll *baarrs;
		int j;
		int t;
		int at_a = 0;
		int at_b = 0;
		int least_a = 0;
		int least_b = 0;
		int *pendinga;
		int *pendingb;
		T = read_int();
		pendinga = new_malloc((T + 1) * (sizeof(*pendinga)));
		new_memset(pendinga, 0, (T + 1) * (sizeof(*pendinga)));
		pendingb = new_malloc((T + 1) * (sizeof(*pendingb)));
		new_memset(pendingb, 0, (T + 1) * (sizeof(*pendingb)));
		read_int2(&NA, &NB);
		for (j = 0; j < NA; j++) {
			int ha;
			int ma;
			int hd;
			int md;
			read_int4(&hd, &md, &ha, &ma);
			ll_insert(&abdeps, (hd * 60) + md);
			ll_insert(&abarrs, (ha * 60) + ma);
		}
		for (j = 0; j < NB; j++) {
			int ha;
			int ma;
			int hd;
			int md;
			read_int4(&hd, &md, &ha, &ma);
			ll_insert(&badeps, (hd * 60) + md);
			ll_insert(&baarrs, (ha * 60) + ma);
		}
		for (t = 0; t < (23 * 60); t++) {
			while (baarrs && (baarrs->i == t)) {
				pendinga[T]++;
				baarrs = baarrs->next;
			}
			at_a += pendinga[0];
			memmove(pendinga, pendinga + 1,
				T * (sizeof(*pendinga)));
			pendinga[T] = 0;
			while (abarrs && (abarrs->i == t)) {
				pendingb[T]++;
				abarrs = abarrs->next;
			}
			at_b += pendingb[0];
			memmove(pendingb, pendingb + 1,
				T * (sizeof(*pendingb)));
			pendingb[T] = 0;
			while (abdeps && (abdeps->i == t)) {
				at_a--;
				if (at_a < least_a) {
					least_a = at_a;
				}
				abdeps = abdeps->next;
			}
			while (badeps && (badeps->i == t)) {
				at_b--;
				if (at_b < least_b) {
					least_b = at_b;
				}
				badeps = badeps->next;
			}
		}
		printf("Case #%d: %d %d\n", i + 1, -least_a, -least_b);
	}
	return 0;
}

void *new_memset(void *ptr, int value, size_t num);
void *new_malloc(size_t size);
char *new_fgets(char *str, int num, FILE * stream);
void new_exit(int status)
{
	int first_iteration;
	return exit(status);
}

void *new_memset(void *ptr, int value, size_t num);
void *new_malloc(size_t size);
char *new_fgets(char *str, int num, FILE * stream)
{
	int first_iteration;
	return fgets(str, num, stream);
}

void *new_memset(void *ptr, int value, size_t num);
void *new_malloc(size_t size)
{
	int first_iteration;
	return malloc(size);
}

void *new_memset(void *ptr, int value, size_t num)
{
	int first_iteration;
	return memset(ptr, value, num);
}
