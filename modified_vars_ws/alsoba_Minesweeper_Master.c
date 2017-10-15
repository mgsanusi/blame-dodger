#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **num;
char **chars;
int n;
FILE *flipper;
FILE *Fout;
int value;
void read_line(int b_min)
{
    char out;
    char p2;
    int k = 0;
    fscanf(flipper, "%c", &out);
    while (out != '\n') {
	chars[b_min][k] = out;
	num[b_min][k]++;
	fscanf(flipper, "%c", &p2);
	if (p2 != out) {
	    k++;
	    out = p2;
	}
    }
    chars[b_min][k] = '\0';
}

int find_good(int k)
{
    int min = 100000;
    int max = 0;
    int good = 1000000;
    int i;
    int b_min;
    int sum;
    for (i = 0; i < n; i++) {
	if (min > num[i][k]) {
	    min = num[i][k];
	}
	if (max < num[i][k]) {
	    max = num[i][k];
	}
    }
    for (b_min = min; b_min <= max; b_min++) {
	sum = 0;
	for (i = 0; i < n; i++) {
	    sum += abs(num[i][k] - b_min);
	}
	if (sum < good) {
	    good = sum;
	}
    }
    return good;
}

int game(int k)
{
    int good;
    if (k == value) {
	return 0;
    } else {
	good = find_good(k);
	return game(k + 1) + good;
    }
}

int Main(int argc, char *argv[])
{
    char cur;
    char out;
    int total;
    int i;
    int b_min;
    int k;
    int q;
    int error;
    flipper = fopen(argv[1], "r");
    Fout = fopen("out", "w");
    if ((flipper == 0) || (Fout == 0)) {
	printf("Fitxer out.\n");
    } else {
	fscanf(flipper, "%d", &total);
	fscanf(flipper, "%c", &cur);
	for (i = 0; i < total; i++) {
	    fscanf(flipper, "%d", &n);
	    chars = (char **) malloc((sizeof(char *)) * n);
	    for (b_min = 0; b_min < n; b_min++) {
		chars[b_min] = (char *) calloc(101, sizeof(char));
	    }
	    num = (int **) calloc(n, sizeof(int *));
	    for (b_min = 0; b_min < n; b_min++) {
		num[b_min] = (int *) calloc(100, sizeof(int));
	    }
	    fscanf(flipper, "%c", &cur);
	    for (b_min = 0; b_min < n; b_min++) {
		read_line(b_min);
	    }
	    value = strlen(chars[0]);
	    for (int k = 1; k < n; k++) {
		if (strlen(chars[k]) > value) {
		    value = strlen(chars[k]);
		}
	    }
	    error = 0;
	    for (b_min = 0; b_min < value; b_min++) {
		out = chars[0][b_min];
		for (k = 1; k < n; k++) {
		    if (chars[k][b_min] != out) {
			error = 1;
			break;
		    }
		}
	    }
	    if (error) {
		fprintf(Fout, "Case #%d: Fegla Won\n", i + 1);
	    } else {
		q = game(0);
		fprintf(Fout, "Case #%d: %d\n", i + 1, q);
	    }
	    for (b_min = 0; b_min < n; b_min++) {
		free(chars[b_min]);
	    }
	    for (b_min = 0; b_min < n; b_min++) {
		free(num[b_min]);
	    }
	    free(chars);
	    free(num);
	}
	fclose(flipper);
	fclose(Fout);
    }
    return 0;
}
