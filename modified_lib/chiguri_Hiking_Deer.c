#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int C, D, V;
int din[100];
int target;

int purchasable(int i, int sum) {
    if(i >= D) return 0;
    if(sum+din[i] > target) return 0;
    if(sum+din[i] == target) return 1;
    return (purchasable(i+1, sum) || purchasable(i+1, sum+din[i]));
}

void insert(int t) {
    int i;
    int x;
    //printf("%d is added\n", t);
    for(i = 0; i < D; ++i) {
        if(t < din[i]) break;
    }
    if(i == D) {
        din[i] = t;
    }
    else {
        for(x = D ; i < x; --x) {
            din[x] = din[x-1];
        }
        din[i] = t;
    }
    ++D;
    return;
}


int solve(void) {
    int c = 0;
    int x;
    int i;
    int t;
    for(target = 1; target <= V; ++target) {
        if(!purchasable(0, 0)) {
            insert(target);
            ++c;
        }
    }

    return c;
}

int main(void) {
    int dataset_num, case_num;
    int i, j, k;


    scanf("%d", &dataset_num);
    for(case_num = 1; case_num <= dataset_num; ++case_num) {
        scanf("%d %d %d", &C, &D, &V);
        for(i = 0; i < D; ++i) {
            scanf("%d", din+i);
        }


        printf("Case #%d: %d\n", case_num, solve());
    }

    return 0;
}
