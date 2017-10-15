#include<stdio.h>
int t;
int o_won;
int x_won;
int uncompleted;
int T;
int a;
int b;
int c;
int d;
int tmp;
char F[4][5];
int new_puts(const char *str);
int main()
{
	int first_iteration;
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%s", &F[0][0]);
		scanf("%s", &F[1][0]);
		scanf("%s", &F[2][0]);
		scanf("%s", &F[3][0]);
		o_won = (x_won = (uncompleted = 0));
		for (a = 0; a < 4; a++) {
			if (((((F[0][a] == 'O') || (F[0][a] == 'T'))
			      && ((F[1][a] == 'O') || (F[1][a] == 'T')))
			     && ((F[2][a] == 'O') || (F[2][a] == 'T')))
			    && ((F[3][a] == 'O') || (F[3][a] == 'T')))
				o_won = 1;
			if (((((F[0][a] == 'X') || (F[0][a] == 'T'))
			      && ((F[1][a] == 'X') || (F[1][a] == 'T')))
			     && ((F[2][a] == 'X') || (F[2][a] == 'T')))
			    && ((F[3][a] == 'X') || (F[3][a] == 'T')))
				x_won = 1;
			if (((((F[a][0] == 'O') || (F[a][0] == 'T'))
			      && ((F[a][1] == 'O') || (F[a][1] == 'T')))
			     && ((F[a][2] == 'O') || (F[a][2] == 'T')))
			    && ((F[a][3] == 'O') || (F[a][3] == 'T')))
				o_won = 1;
			if (((((F[a][0] == 'X') || (F[a][0] == 'T'))
			      && ((F[a][1] == 'X') || (F[a][1] == 'T')))
			     && ((F[a][2] == 'X') || (F[a][2] == 'T')))
			    && ((F[a][3] == 'X') || (F[a][3] == 'T')))
				x_won = 1;
			for (b = 0; b < 4; b++)
				if (F[a][b] == '.')
					uncompleted = 1;
		}
		if (((((F[0][3] == 'O') || (F[0][3] == 'T'))
		      && ((F[1][2] == 'O') || (F[1][2] == 'T')))
		     && ((F[2][1] == 'O') || (F[2][1] == 'T')))
		    && ((F[3][0] == 'O') || (F[3][0] == 'T')))
			o_won = 1;
		if (((((F[0][0] == 'O') || (F[0][0] == 'T'))
		      && ((F[1][1] == 'O') || (F[1][1] == 'T')))
		     && ((F[2][2] == 'O') || (F[2][2] == 'T')))
		    && ((F[3][3] == 'O') || (F[3][3] == 'T')))
			o_won = 1;
		if (((((F[0][0] == 'X') || (F[0][3] == 'T'))
		      && ((F[1][1] == 'X') || (F[1][2] == 'T')))
		     && ((F[2][2] == 'X') || (F[2][1] == 'T')))
		    && ((F[3][3] == 'X') || (F[3][0] == 'T')))
			x_won = 1;
		if (((((F[0][0] == 'X') || (F[0][0] == 'T'))
		      && ((F[1][1] == 'X') || (F[1][1] == 'T')))
		     && ((F[2][2] == 'X') || (F[2][2] == 'T')))
		    && ((F[3][3] == 'X') || (F[3][3] == 'T')))
			x_won = 1;
		printf("Case #%d: ", t);
		if (x_won)
			new_puts("X won");
		if (o_won)
			new_puts("O won");
		if (((!x_won) && (!o_won)) && uncompleted)
			new_puts("Game has not completed");
		if (((!x_won) && (!o_won)) && (!uncompleted))
			new_puts("Draw");
	}
	return 0;
}

int new_puts(const char *str)
{
	int first_iteration;
	return puts(str);
}
