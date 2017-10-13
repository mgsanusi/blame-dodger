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
    // ���̂܂ܐi�߂�Ƃ���܂Ői�߂�B
    int t1, t2;
    while(j < N && motes[j] < A) {
        A += motes[j++];
    }
    if(j >= N) return count;
    t1 = search(j, A+A-1, count+1); // ���󑝂₹��ő�𑝂₵���ꍇ
    t2 = N - j + count; // �c��S���������ꍇ
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
            printf("Case #%d: %d\n", i, N); // ���₹�Ȃ��̂ŏ��������Ȃ�
        }
        else {
            qsort(motes, N, sizeof(int), compare);
            printf("Case #%d: %d\n", i, search(0, A, 0));
        }
    }

    return 0;
}
