#include <stdio.h>
int new_getchar();
int Main()
{
    int first_iteration;
    int caseCount;
    int caseIndex;
    int count[19];
    int outa;
    char read;
    scanf("%d", &caseCount);
    new_getchar();
    for (caseIndex = 1; caseIndex <= caseCount; caseIndex++) {
	for (outa = 0; outa < 19; outa++)
	    count[outa] = 0;
	while ((read = new_getchar()) != '\n') {
	    switch (read) {
	    case 'w':
		count[0]++;
		break;
	    case 'e':
		count[1] = (count[1] + count[1 - 1]) % 10000;
		count[6] = (count[6] + count[6 - 1]) % 10000;
		count[14] = (count[14] + count[14 - 1]) % 10000;
		break;
	    case 'l':
		count[2] = (count[2] + count[2 - 1]) % 10000;
		break;
	    case 'c':
		count[3] = (count[3] + count[3 - 1]) % 10000;
		count[11] = (count[11] + count[11 - 1]) % 10000;
		break;
	    case 'o':
		count[4] = (count[4] + count[4 - 1]) % 10000;
		count[9] = (count[9] + count[9 - 1]) % 10000;
		count[12] = (count[12] + count[12 - 1]) % 10000;
		break;
	    case 'm':
		count[5] = (count[5] + count[5 - 1]) % 10000;
		count[18] = (count[18] + count[18 - 1]) % 10000;
		break;
	    case ' ':
		count[7] = (count[7] + count[7 - 1]) % 10000;
		count[10] = (count[10] + count[10 - 1]) % 10000;
		count[15] = (count[15] + count[15 - 1]) % 10000;
		break;
	    case 't':
		count[8] = (count[8] + count[8 - 1]) % 10000;
		break;
	    case 'd':
		count[13] = (count[13] + count[13 - 1]) % 10000;
		break;
	    case 'j':
		count[16] = (count[16] + count[16 - 1]) % 10000;
		break;
	    case 'a':
		count[17] = (count[17] + count[17 - 1]) % 10000;
		break;
	    }
	}
	printf("Case #%d: %04d\n", caseIndex, count[18]);
    }
    return 0;
}

int new_getchar()
{
    return getchar();
}
