#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Main(void)
{
	int first_iteration;
	int num;
	int runSpeed;
	int j;
	int word;
	int passLength;
	int typeLen;
	double good;
	double temp;
	double fullCorrect;
	double *localRight;
	scanf("%d", &num);
	for (runSpeed = 1; runSpeed <= num; ++runSpeed) {
		scanf("%d %d", &typeLen, &passLength);
		good = passLength + 2;
		localRight = (double *)malloc((sizeof(double)) * (typeLen + 1));
		localRight[0] = 1.0;
		for (j = 1; j <= typeLen; ++j) {
			scanf("%lf", localRight + j);
			localRight[j] *= localRight[j - 1];
		}
		fullCorrect = localRight[typeLen];
		temp =
		    (fullCorrect * ((passLength - typeLen) + 1)) +
		    ((1.0 - fullCorrect) * (((passLength * 2) - typeLen) + 2));
		if (good > temp) {
			good = temp;
		}
		for (j = 1; j <= typeLen; ++j) {
			word =
			    ((((typeLen - j) * 2) + passLength) - typeLen) + 1;
			temp =
			    (word * localRight[j]) +
			    (((word + passLength) + 1) * (1 - localRight[j]));
			if (good > temp) {
				good = temp;
			}
		}
		printf("Case #%d: %lf\n", runSpeed, good);
		free(localRight);
	}
	return 0;
}
