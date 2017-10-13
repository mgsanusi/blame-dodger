#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

char table[256] = {0};
char buffer1[10240];
char buffer2[10240];
int main(int argc, char *argv[])
{
    FILE *pin = fopen("a.p", "r");
    FILE *ein = fopen("a.e", "r");

    for (int i = 0; i<256; i++){
        table[i] = '@';
    }

    while (fgets(buffer1, sizeof(buffer1), pin) != NULL){
        fgets(buffer2, sizeof(buffer2), ein);
        int len = strlen(buffer1);
        for (int i = 0; i<len - 1; i++){
            table[buffer1[i]] = buffer2[i];
        }
    }
    fclose(pin);
    fclose(ein);

    table['q'] = 'z';
    table['z'] = 'q';

    int cas = 1;
    int num = 0;
    scanf("%d", &num);
    gets(buffer2);
    while (fgets(buffer1, sizeof(buffer1), stdin) != NULL){
        int len = strlen(buffer1);
        for (int i = len-1; i>=0; i--){
            if (buffer1[i] == '\r' || buffer1[i] == '\n'){
                buffer1[i] = 0;
                len--;
            }
        }

        printf("Case #%d: ", cas++);
        for (int i = 0; i<len; i++){
            printf("%c", table[buffer1[i]]);
        }
        printf("\n");
    }
    return 0;
}
