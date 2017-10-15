#include <stdio.h>
#include <stdlib.h>
int Main()
{
	int first_iteration;
	int decode[26] =
	    { 24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19,
       13, 22, 9, 15, 5, 12, 0, 16 };
	int no;
	int ok;
	int j;
	char string[256];
	scanf("%d\n", &no);
	for (ok = 0; ok < no; ok++) {
		gets(string);
		for (j = 0; string[j]; j++)
			if ((string[j] >= 'a') && (string[j] <= 'z'))
				string[j] = decode[string[j] - 'a'] + 'a';
		printf("Case #%d: %s\n", ok + 1, string);
	}
	return 0;
}
