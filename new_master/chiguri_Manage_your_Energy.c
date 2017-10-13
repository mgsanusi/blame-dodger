#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
int compare(const void *t, const void *s) {
    return *(const int *)t - *(const int *)s;
}

int motes[100];
int N;

int search(int j, int A, int count) {
    // そのまま進めるところまで進める。
    int t1, t2;
    while(j < N && motes[j] < A) {
        A += motes[j++];
    }
    if(j >= N) return count;
    t1 = search(j, A+A-1, count+1); // 現状増やせる最大を増やした場合
    t2 = N - j + count; // 残り全部消した場合
    return t1 < t2 ? t1 : t2;
}



int main(void) {
    int num;
    int i, j;
    int A;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d", &A);
        scanf("%d", &N);
        for(j = 0; j < N; ++j) {
            scanf("%d", motes+j);
        }
        if(A == 1) {
            printf("Case #%d: %d\n", i, N); // 増やせないので消すしかない
        }
        else {
            qsort(motes, N, sizeof(int), compare);
            printf("Case #%d: %d\n", i, search(0, A, 0));
        }
    }

    return 0;
}
