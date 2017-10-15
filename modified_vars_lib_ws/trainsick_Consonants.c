#include <stdio.h>
int new_abs(int x);
int new_abs(int out2)
{
	return out2 > 0 ? out2 : -out2;
}

void pogo(void)
{
	int m;
	int xPutbytes;
	int j;
	int j;
	int i;
	scanf("%d %d", &m, &xPutbytes);
	j = new_abs(m);
	j = new_abs(xPutbytes);
	for (i = 0; i < j; i++) {
		if (m > 0)
			printf("WE");
		else
			printf("EW");
	}
	for (i = 0; i < j; i++) {
		if (xPutbytes > 0)
			printf("SN");
		else
			printf("NS");
	}
	printf("\n");
}

int Main(int argc, char **argv)
{
	int i;
	int p;
	scanf("%d", &p);
	for (i = 1; i <= p; i++) {
		printf("Case #%d: ", i);
		pogo();
	}
	return 0;
}

int new_abs(int x)
{
	return abs(x);
}
