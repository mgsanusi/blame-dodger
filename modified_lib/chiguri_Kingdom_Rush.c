#include<stdio.h>
#include<stdlib.h>
#include<string.h>


// for qsort
/*
int compare(int *t, int *s) {
    return *t - *s;
}
*/

int d[10000];
int l[10000];
int goal;
int N;

void search(int cur, int pos, int reach) {
    int j;
    if(pos + reach >= goal) {
        goal = -1;
        return;
    }
    int temp;
    for(j = cur+1; j < N; ++j) {
        if(d[j] > pos + reach) {
            break; // ˆÈ~‚Í‚·‚×‚Ä“Í‚©‚È‚¢
        }
        temp = d[j] - pos;
        if(temp > l[j]) temp = l[j];
        search(j, d[j], temp);
        if(goal < 0) return;
    }
    return;
}



int main(void) {
    int num;
    int i, j, k;
    int reach;
    int pos;
    int cur;
    int temp_pos;
    int temp_reach;

    scanf("%d", &num);
    for(i = 1; i <= num; ++i) {
        scanf("%d", &N);
        for(j = 0; j < N; ++j) {
            scanf("%d %d", d+j, l+j);
        }
        scanf("%d", &goal);
        pos = d[0];
        reach = d[0];
        cur = 0;
        search(0, d[0], d[0]);

        printf("Case #%d: ", i);
        if(goal < 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}
