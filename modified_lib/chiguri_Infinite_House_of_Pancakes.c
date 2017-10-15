#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int N;
int pans[1000];

int search(int max, int minuts) {
    int i;
    int minimal = max + minuts;
    int t;
    int maximal = max - 1;
    for(i = 2; i <= max/2; ++i) {
        int quot = max / i;
        int mod = max % i;
        pans[quot] += pans[max] * (i-mod);
        pans[quot+1] += pans[max] * mod;
        while(maximal > 0 && pans[maximal] == 0) --maximal;

        t = search(maximal, minuts + pans[max]*(i-1));
        if(t < minimal) minimal = t;

        pans[quot] -= pans[max] * (i-mod);
        pans[quot+1] -= pans[max] * mod;
    }
    return minimal;
}



int main(void) {
    int dataset_num, case_num;
    int i;
    int max;
    int minuts;
    int minimal;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        max = 0;
        minuts = 0;
        for(i = 0; i < 1000; ++i) {
            pans[i] = 0;
        }
        scanf("%d", &N);
        for(i = 0; i < N; ++i) {
            int j;
            scanf("%d", &j);
            if(j > max) max = j;
            (pans[j])++;
        }
        /*        minimal = max; // if do nothing, it may take the max pancakes' minuts.
        while(max > 3) { // if maximum pancakes are le 3, there are no reasons to move pancakes
            int half = max/2;
            minuts += pans[max];
            pans[half] += pans[max];
            pans[max-half] += pans[max];
            --max;
            while(max > 0 && pans[max] == 0) --max;

            // if dividing pancakes (and do nothing) makes minuts shorter, we adopt it.
            if(minuts + max < minimal) minimal = minuts + max;
        }
        */
        printf("Case #%d: %d\n", case_num, search(max, 0));
    }

    return 0;
}
