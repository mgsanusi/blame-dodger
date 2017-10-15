#include <stdio.h>
#include <stdlib.h>
void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *));
int cmp(const int *x, const int *first)
{
    int first_iteration;
    return (*x) - (*first);
}

int rp[100][100];
int irp[100][100];
char num[100][100];
int length[100];
int Main()
{
    int first_iteration;
    int cases;
    int e;
    scanf("%d", &cases);
    for (e = 1; e <= cases; e++) {
	int t;
	scanf("%d", &t);
	int sudah;
	for (sudah = 0; sudah < t; sudah++) {
	    scanf("%c", num[sudah]);
	    while ((num[sudah][0] > 'z') || (num[sudah][0] < 'a'))
		scanf("%c", num[sudah]);
	    rp[sudah][0] = 1;
	    char tmp;
	    int point = 1;
	    while (1) {
		scanf("%c", &tmp);
		if ((tmp > 'z') || (tmp < 'a'))
		    break;
		if (tmp == num[sudah][point - 1])
		    rp[sudah][point - 1]++;
		else {
		    num[sudah][point] = tmp;
		    rp[sudah][point++] = 1;
		}
	    }
	    length[sudah] = point;
	}
	int lose = 0;
	for (sudah = 0; sudah < t; sudah++) {
	    int j;
	    for (j = 0; j < sudah; j++) {
		if (length[sudah] != length[j]) {
		    lose = 1;
		    goto out;
		}
		int out2;
		for (out2 = 0; out2 < length[sudah]; out2++)
		    if (num[sudah][out2] != num[j][out2]) {
			lose = 1;
			goto out;
		    }
	    }
	    for (j = 0; j < length[sudah]; j++)
		irp[j][sudah] = rp[sudah][j];
	}
	for (sudah = 0; sudah < length[0]; sudah++)
	    new_qsort(irp[sudah], t, sizeof(int), cmp);
	int good = 0;
	for (sudah = 0; sudah < length[0]; sudah++) {
	    int j;
	    for (j = 0; j < t; j++) {
		if (j < (t / 2))
		    good += irp[sudah][t / 2] - irp[sudah][j];
		else
		    good += irp[sudah][j] - irp[sudah][t / 2];
	    }
	}
      out:
	printf("Case #%d: ", e);
	if (lose)
	    printf("Fegla Won\n");
	else
	    printf("%d\n", good);
    }
}

void new_qsort(void *base, int num, int size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}
