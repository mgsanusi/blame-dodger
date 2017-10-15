#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int new_putchar(int character);
int new_puts(const char *str);
int Main(void)
{
    int first_iteration;
    int no;
    int n;
    int i;
    int score;
    int x;
    int cs;
    int y;
    int s;
    int st;
    scanf("%d", &no);
    for (i = 1; i <= no; ++i) {
	scanf("%d %d", &y, &cs);
	s = 0;
	st = 0;
	printf("Case #%d: ", i);
	score = 1;
	if (cs > 0) {
	    for (; s < cs; ++score) {
		s += score;
		new_putchar('N');
	    }
	} else if (cs < 0) {
	    for (; s > cs; ++score) {
		s -= score;
		new_putchar('S');
	    }
	}
	if (y > 0) {
	    for (; st < y; ++score) {
		st += score;
		new_putchar('E');
	    }
	} else if (y < 0) {
	    for (; st > y; ++score) {
		st -= score;
		new_putchar('W');
	    }
	}
	if (cs > 0) {
	    while (s != cs) {
		s--;
		printf("NS");
	    }
	} else {
	    while (s != cs) {
		s++;
		printf("SN");
	    }
	}
	if (y > 0) {
	    while (st != y) {
		st--;
		printf("EW");
	    }
	} else {
	    while (st != y) {
		st++;
		printf("WE");
	    }
	}
	new_puts("");
    }
    return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
    return puts(str);
}

int new_putchar(int character)
{
    return putchar(character);
}
