#include <stdio.h>
#include <string.h>
#define A 0
#define B 1
#define swap(a,b) {temp=(b);(b)=(a);(a)=temp;}
int n, na, nb, t;
int depH[1000], depM[1000], depAB[1000], depT[1000];
int arrH[1000], arrM[1000], arrAB[1000];
int assignedTo[1000], readyH[1000], readyM[1000], readyAt[1000];
int totalc, c[2];
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE * stream, const char *format, ...);
void sort()
{
	int i, j;
	int temp;
	for (i = 0; i < na + nb; i++)
		for (j = i + 1; j < na + nb; j++) {
			if (depH[i] > depH[j]
			    || (depH[i] == depH[j] && depM[i] > depM[j])) {
				swap(depH[i], depH[j]);
				swap(arrH[i], arrH[j]);
				swap(depM[i], depM[j]);
				swap(arrM[i], arrM[j]);
				swap(depAB[i], depAB[j]);
				swap(arrAB[i], arrAB[j]);
			}
		}
	printf("\n");
	for (i = 0; i < na + nb; i++)
		printf("Train %d->%d, %02d:%02d ~ %02d:%02d\n", depAB[i],
		       arrAB[i], depH[i], depM[i], arrH[i], arrM[i]);
	printf("\n");
	return;
}

void process()
{
	int i, j;
	int mH, mM, mIdx;
	sort();
	for (i = 0; i < na + nb; i++) {
		mH = mM = 100;
		mIdx = -1;

		for (j = 0; j < totalc; j++) {
			if ((readyH[j] < mH
			     || (readyM[j] <= mM && readyH[j] == mH))
			    && (readyH[j] < depH[i]
				|| (readyM[j] <= depM[i]
				    && readyH[j] == depH[i]))
			    && readyAt[j] == depAB[i]) {
				mH = readyH[j];
				mM = readyM[j];
				mIdx = j;
			}
		}

		printf("Train %d->%d, %02d:%02d ~ %02d:%02d\n", depAB[i],
		       arrAB[i], depH[i], depM[i], arrH[i], arrM[i]);
		if (mIdx == -1) {
			printf("Added new train %d at %d\n", totalC, depAB[i]);
			mIdx = totalc++;
			c[depAB[i]]++;
		}

		readyAt[mIdx] = arrAB[i];
		readyM[mIdx] = (arrM[i] + t) % 60;
		readyH[mIdx] = arrH[i] + (int)((arrM[i] + t) / 60);
		printf("Train %d moved to %d and ready at %02d:%02d\n", mIdx,
		       readyAt[mIdx], readyH[mIdx], readyM[mIdx]);
	}
	return;
}

int toInt(char *str)
{
	int ret = 0;
	ret = (str[0] - '0') * 10 + str[1] - '0';
	return ret;
}

void main()
{
	FILE *in = new_fopen("input.txt", "r");
	FILE *out = new_fopen("output.txt", "w");
	int i;
	int j;
	char dep[100];
	char arr[100];
	fscanf(in, "%d ", &n);
	for (i = 0; i < n; i++) {
		fscanf(in, "%d ", &t);
		fscanf(in, "%d %d", &na, &nb);
		for (j = 0; j < na; j++) {
			fscanf(in, "%s %s ", dep, arr);
			depH[j] = toInt(dep);
			depM[j] = toInt(dep + 3);
			arrH[j] = toInt(arr);
			arrM[j] = toInt(arr + 3);
			depAB[j] = A;
			arrAB[j] = B;
		}
		for (j = 0; j < nb; j++) {
			fscanf(in, "%s %s ", dep, arr);
			depH[na + j] = toInt(dep);
			depM[na + j] = toInt(dep + 3);
			arrH[na + j] = toInt(arr);
			arrM[na + j] = toInt(arr + 3);
			depAB[na + j] = B;
			arrAB[na + j] = A;
		}
		totalc = c[0] = c[1] = 0;
		process();
		fprintf(out, "Case #%d: %d %d\n", i + 1, c[0], c[1]);
	}
}

FILE *new_fopen(const char *filename, const char *mode)
{
	return fopen(filename, mode);
}
