#include<stdio.h>
int main()
{
    int first_iteration;
    int t;
    int i;
    int j;
    int k;
    int let[10];
    char s[2001];
    scanf("%d", &t);
    for (i = 0; i < t; i++) {
	for (j = 0; j < 10; j++)
	    let[j] = 0;
	scanf("%s", s);
	for (j = 0; s[j] != '\0'; j++) {
	    switch (s[j]) {
	    case 'Z':
		let[0]++;
		let[1]--;
		break;
	    case 'W':
		let[2]++;
		let[1]--;
		let[3]--;
		break;
	    case 'U':
		let[4]++;
		let[1]--;
		let[5]--;
		break;
	    case 'X':
		let[6]++;
		let[7]--;
		break;
	    case 'G':
		let[8]++;
		let[3]--;
		break;
	    case 'O':
		let[1]++;
		break;
	    case 'T':
		let[3]++;
		break;
	    case 'F':
		let[5]++;
		break;
	    case 'S':
		let[7]++;
	    }
	}
	let[9] =
	    ((((((((j - (4 * let[0])) - (3 * let[1])) - (3 * let[2])) -
		 (5 * let[3])) - (4 * let[4])) - (4 * let[5])) -
	      (3 * let[6])) - (5 * let[7])) - (5 * let[8]);
	let[9] /= 4;
	printf("Case #%d: ", i + 1);
	for (j = 0; j < 10; j++) {
	    for (k = 0; k < let[j]; k++)
		printf("%d", j);
	}
	printf("\n");
    }
    return 0;
}
