#include<stdio.h>
typedef struct  {
    int dy;
    int s;
} zapis;
int fja(const void *dy, const void *s)
{
    int data = ((zapis *) dy)->s - ((zapis *) s)->s;
    if (data < 0)
	return -1;
    if (data > 0)
	return 1;
    data = ((zapis *) dy)->dy - ((zapis *) s)->dy;
    if (data > 0)
	return -1;
    if (data < 0)
	return 1;
    return 0;
}

int Main()
{
    int y2;
    scanf("%d", &y2);
    int k;
    for (k = 1; k <= y2; k++) {
	int rez;
	int rez1;
	int rez2;
	int koliko;
	int k;
	zapis y[1000];
	int bio[1000] = { 0 };
	int i;
	int temp;
	scanf("%d", &k);
	for (i = 0; i < k; i++)
	    scanf("%d %d", &y[i].dy, &y[i].s);
	rez = 0;
	rez1 = 0;
	rez2 = 0;
	koliko = 0;
	int broj = 0;
	qsort(y, k, sizeof(zapis), fja);
	int a2 = 0;
	while (1) {
	    int i;
	    int owp;
	    int pomak = 0;
	    for (i = a2; (i < k) && (y[i].s <= rez); i++) {
		if (bio[i] == 2)
		    continue;
		if (bio[i] == 0)
		    rez += 2;
		else
		    rez++;
		broj++;
		koliko++;
		pomak = 1;
		bio[i] = 2;
	    }
	    a2 = i;
	    for (i = k - 1; i >= 0; i--) {
		if ((bio[i] == 0) && (y[i].dy <= rez)) {
		    pomak = 1;
		    broj++;
		    rez++;
		    bio[i] = 1;
		    break;
		}
	    }
	    if (!pomak)
		break;
	}
	printf("Case #%d: ", k);
	if (koliko < k)
	    printf("Too Bad\n");
	else
	    printf("%d\n", broj);
    }
    return 0;
}
