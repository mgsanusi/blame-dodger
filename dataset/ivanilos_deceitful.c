#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    double diff;
    diff = *(double *)a - *(double *)b;
    if (diff < 0) {
        return -1;
    } else {
        return 1;
    }
}

int main(void) {
    int t;
    int caso;
    int n;
    double ken[1005];
    double naomi[1005];
    int i, j;
    int war;
    int deceit;
    int count;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        war = deceit = 0;
        scanf(" %d", &n);

        for (i = 0; i < n; i++) {
            scanf(" %lf", &naomi[i]);
        }
        for (i = 0; i < n; i++) {
            scanf(" %lf", &ken[i]);
        }

        qsort(naomi, n ,sizeof(double), comp);
        qsort(ken, n, sizeof(double), comp);

        /*for (i = 0; i < n; i++) {
            printf("%lf ", naomi[i]);
        }
        printf("\n");
        for (i = 0; i < n; i++) {
            printf("%lf ", ken[i]);
        }
        printf("\n"); */

        j = 0;
        for (i = 0; i < n; i++) {
            if (naomi[i] > ken[j]) {
                deceit++;
                j++;
            }
        }

        i = j = 0;
        count = 0;
        while (i < n && j < n) {
            if (naomi[i] < ken[j]) {
                i++;
                count++;
            } else {
                j++;
                if (count > 0) {
                    war++;
                    count--;
                }
            }
        }
        for (; j < n; j++) {
            if (count > 0) {
                war++;
                count--;
            }
        }
        war = n - war;

        printf("Case #%d: %d %d\n", caso, deceit, war);
    }

    return 0;
}
