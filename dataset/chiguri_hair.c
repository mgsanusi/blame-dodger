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
int B;
int M[1000];



int main(void) {
    int dataset_num, case_num;
    int i, j, k;
    int t;
    int md;
    int acc;

    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d", &B, &N);
        for(i = 0; i < B; ++i) {
            scanf("%d", M+i);
        }

        md = 1;
        for(i = 0; i < B; ++i) {
            md *= M[i];
        }
        acc = 0;
        for(i = 0; i < B; ++i) {
            acc += md / M[i];
        }
        //printf("md %d \t acc %d\n", md, acc);
        if(N > acc)
            N = ((N - 1) % acc) + 1;

        t = 0;
        i = 0;
        while(N) {
            for(i = 0; i < B; ++i) {
                if(t % M[i] == 0) {
                    if(--N == 0) break;
                }
            }
            ++t;
        }

        printf("Case #%d: %d\n", case_num, i+1);
    }

    return 0;
}
