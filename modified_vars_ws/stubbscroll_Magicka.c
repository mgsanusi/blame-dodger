#include <stdio.h>
#include <string.h>
char combine[128][128];
char oppose[128][128];
int a;
int num;
int n;
char rslt[16384];
int pan;
char invoke[256];
void simul()
{
    int wp;
    int opp;
    int inputs;
    char make;
    pan = 0;
    for (wp = 0; wp < n; wp++) {
	rslt[pan++] = invoke[wp];
	if (pan > 1) {
	    make = combine[(int) rslt[pan - 1]][(int) rslt[pan - 2]];
	    if (make) {
		rslt[pan - 2] = make;
		pan--;
		continue;
	    }
	}
	if (pan > 1) {
	    opp = rslt[pan - 1];
	    for (inputs = 0; inputs < (pan - 1); inputs++)
		if (oppose[(int) rslt[inputs]][opp]) {
		    pan = 0;
		    break;
		}
	}
    }
}

int Main()
{
    int cases;
    int caseno = 1;
    int wp;
    char t[16];
    scanf("%d", &cases);
    while (cases--) {
	memset(combine, 0, sizeof(combine));
	memset(oppose, 0, sizeof(oppose));
	scanf("%d", &a);
	for (wp = 0; wp < a; wp++) {
	    scanf("%s", t);
	    combine[(int) t[0]][(int) t[1]] = t[2];
	    combine[(int) t[1]][(int) t[0]] = t[2];
	}
	scanf("%d", &num);
	for (wp = 0; wp < num; wp++) {
	    scanf("%s", t);
	    oppose[(int) t[0]][(int) t[1]] = 1;
	    oppose[(int) t[1]][(int) t[0]] = 1;
	}
	scanf("%d", &n);
	scanf("%s", invoke);
	simul();
	printf("Case #%d: [", caseno++);
	for (wp = 0; wp < (pan - 1); wp++)
	    printf("%c, ", rslt[wp]);
	if (pan)
	    printf("%c]\n", rslt[wp]);
	else
	    puts("]");
    }
    return 0;
}
