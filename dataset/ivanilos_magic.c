#include <stdio.h>

int main(void) {
    int t;
    int caso;
    int mat[5][5];
    int card[20];
    int i, j;
    int row;
    int count;
    int number;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        for (i = 1; i <= 16; i++) {
            card[i] = 0;
        }

        scanf(" %d", &row);

        for (i = 1; i <= 4; i++) {
            for (j = 1; j <= 4; j++) {
                scanf(" %d", &mat[i][j]);
            }
        }

        for (j = 1; j <= 4; j++) {
            card[mat[row][j]]++;
        }

        scanf(" %d", &row);

        for (i = 1; i <= 4; i++) {
            for (j = 1; j <= 4; j++) {
                scanf(" %d", &mat[i][j]);
            }
        }

        count = 0;
        for (j = 1; j <= 4; j++) {
            if (card[mat[row][j]] == 1) {
                count++;
                number = mat[row][j];
            }
        }

        printf("Case #%d: ", caso);
        if (count == 0) {
            printf("Volunteer cheated!\n");
        } else if (count == 1) {
            printf("%d\n", number);
        } else {
            printf("Bad magician!\n");
        }
    }
    return 0;
}
