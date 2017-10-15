#include <stdio.h>
#include <string.h>
#include <stddef.h>
 char combine[128][128];
char oppose[128][128];
int c, d, n;
char res[16384];
int rn;
char invoke[256];
void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str);
 void simul()
{
    int i, opp, j;
    char make;
    rn = 0;
    for (i = 0; i < n; i++) {
	res[rn++] = invoke[i];
	
	    /*  check for combine */ 
	    if (rn > 1) {
	    make = combine[(int) res[rn - 1]][(int) res[rn - 2]];
	    if (make) {
		res[rn - 2] = make;
		rn--;
		continue;
	    }
	}
	
	    /*  check for oppose */ 
	    if (rn > 1) {
	    opp = res[rn - 1];
	    for (j = 0; j < rn - 1; j++)
		if (oppose[(int) res[j]][opp]) {
		    rn = 0;
		    break;
		}
	}
    }
}

 int main()
{
    int cases, caseno = 1, i;
    char s[16];
    scanf("%d", &cases);
    while (cases--) {
	new_memset(combine, 0, sizeof(combine));
	new_memset(oppose, 0, sizeof(oppose));
	scanf("%d", &c);
	for (i = 0; i < c; i++) {
	    scanf("%s", s);
	    combine[(int) s[0]][(int) s[1]] = s[2];
	    combine[(int) s[1]][(int) s[0]] = s[2];
	} scanf("%d", &d);
	for (i = 0; i < d; i++) {
	    scanf("%s", s);
	    oppose[(int) s[0]][(int) s[1]] = 1;
	    oppose[(int) s[1]][(int) s[0]] = 1;
	} scanf("%d", &n);
	scanf("%s", invoke);
	simul();
	printf("Case #%d: [", caseno++);
	for (i = 0; i < rn - 1; i++)
	    printf("%c, ", res[i]);
	if (rn)
	    printf("%c]\n", res[i]);
	
	else
	    new_puts("]");
    }
    return 0;
}

void *new_memset(void *ptr, int value, size_t num);
int new_puts(const char *str)
{
    return puts(str);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
