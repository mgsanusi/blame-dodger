#include <stdio.h>
typedef struct  {
	int i;
	int j;
	int k;
} Rec;
int Main(void)
{
	int first_iteration;
	int i;
	int j;
	int k;
	int s;
	int m;
	scanf("%d", &m);
	for (s = 1; s <= m; s++) {
		int array;
		int p;
		int b;
		int k;
		Rec choice[27];
		int rslt_no;
		int ans_choice;
		fprintf(stderr, "Case #%d\n", s);
		fflush(stderr);
		scanf("%d %d %d %d", &array, &p, &b, &k);
		for (i = 0; i < array; i++)
			for (j = 0; j < p; j++)
				for (k = 0; k < b; k++)
					choice[(((i * p) * b) + (j * b)) + k] =
					    Reci, j, k;
		rslt_no = -1;
		for (i = 0; i < (1 << ((array * p) * b)); i++) {
			int count[64] = { 0 };
			int no;
			no = 0;
			for (j = 0; j < ((array * p) * b); j++)
				if ((i >> j) & 1)
					if ((((count
					       [((choice[j].i * 16) +
						 (choice[j].j * 4)) +
						choice[j].k] == 0)
					      &&
					      (count
					       [((choice[j].i * 16) +
						 (choice[j].j * 4)) + 3] < k))
					     &&
					     (count
					      [(48 + (choice[j].j * 4)) +
					       choice[j].k] < k))
					    &&
					    (count
					     [((choice[j].i * 16) + 12) +
					      choice[j].k] < k)) {
						no++;
						count[((choice[j].i * 16) +
						       (choice[j].j * 4)) +
						      choice[j].k]++;
						count[((choice[j].i * 16) +
						       (choice[j].j * 4)) +
						      3]++;
						count[(48 + (choice[j].j * 4)) +
						      choice[j].k]++;
						count[((choice[j].i * 16) +
						       12) + choice[j].k]++;
					} else
						break;
			if (j == ((array * p) * b))
				if (no > rslt_no) {
					rslt_no = no;
					ans_choice = i;
				}
		}
		printf("Case #%d: %d\n", s, rslt_no);
		for (i = 0; i < ((array * p) * b); i++)
			if ((ans_choice >> i) & 1)
				printf("%d %d %d\n", choice[i].i + 1,
				       choice[i].j + 1, choice[i].k + 1);
	}
	return 0;
}
