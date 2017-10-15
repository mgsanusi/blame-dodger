#include<stdio.h>
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int Main()
{
    new_freopen("A.in", "r", stdin);
    new_freopen("A.out", "w", stdout);
    int numCases;
    int c;
    int k;
    int opposed;
    int readChar[10000];
    int eaten1;
    int eaten2;
    int rate;
    scanf("%d", &k);
    for (c = 1; c <= k; c++) {
	eaten1 = 0;
	eaten2 = 0;
	rate = 0;
	scanf("%d", &opposed);
	scanf("%d", &readChar[0]);
	for (numCases = 1; numCases < opposed; numCases++) {
	    scanf("%d", &readChar[numCases]);
	    if (readChar[numCases] < readChar[numCases - 1]) {
		eaten1 += readChar[numCases - 1] - readChar[numCases];
		if ((readChar[numCases - 1] - readChar[numCases]) > rate) {
		    rate = readChar[numCases - 1] - readChar[numCases];
		}
	    }
	}
	for (numCases = 0; numCases < (opposed - 1); numCases++) {
	    eaten2 +=
		readChar[numCases] > rate ? rate : readChar[numCases];
	}
	printf("Case #%d: %d %d\n", c, eaten1, eaten2);
    }
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
