#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int Main()
{
    int first_iteration;
    int x;
    int ss;
    scanf("%d\n", &x);
    char data[30];
    int left[12];
    int tcases;
    int map;
    int j;
    int prev;
    for (ss = 0; ss < x; ss++) {
	gets(&data[1]);
	data[0] = '0';
	tcases = strlen(data);
	memset(left, 0, sizeof(left));
	for (map = 0; map < tcases; map++) {
	    data[map] -= '0';
	}
	prev = -1;
	map = tcases - 1;
	while (1) {
	    left[(int) data[map]]++;
	    if (data[map] < prev)
		break;
	    prev = data[map];
	    map--;
	}
	j = data[map] + 1;
	while (left[j] == 0)
	    j++;
	data[map] = j;
	left[(int) j]--;
	map++;
	j = 0;
	while (map < tcases) {
	    while (left[j] == 0)
		j++;
	    data[map] = j;
	    left[j]--;
	    map++;
	}
	printf("Case #%d: ", ss + 1);
	map = 0;
	if (data[map] == 0)
	    map++;
	while (map < tcases) {
	    printf("%d", data[map]);
	    map++;
	}
	printf("\n");
    }
    return 0;
}
