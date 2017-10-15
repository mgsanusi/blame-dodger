#include <stdio.h>
int main()
{
	int first_iteration;
	char board[4][4];
	int t;
	int i;
	int j;
	int k;
	int draw;
	int flag;
	scanf("%d", &t);
	for (k = 0; k < t; k++) {
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++)
				scanf(" %c", &board[i][j]);
		}
		draw = 1;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if (board[i][j] == '.')
					draw = 0;
			}
		}
		flag = 0;
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if ((board[i][j] == 'X')
				    || (board[i][j] == '.'))
					break;
			}
			if (j == 4)
				break;
		}
		if (i < 4) {
			printf("Case #%d: O won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if ((board[j][i] == 'X')
				    || (board[j][i] == '.'))
					break;
			}
			if (j == 4)
				break;
		}
		if ((i < 4) && (!flag)) {
			printf("Case #%d: O won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			if ((board[i][i] == 'X') || (board[i][i] == '.'))
				break;
		}
		if ((i == 4) && (!flag)) {
			printf("Case #%d: O won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			if ((board[i][3 - i] == 'X')
			    || (board[i][3 - i] == '.'))
				break;
		}
		if ((i == 4) && (!flag)) {
			printf("Case #%d: O won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if ((board[i][j] == 'O')
				    || (board[i][j] == '.'))
					break;
			}
			if (j == 4)
				break;
		}
		if ((i < 4) && (!flag)) {
			printf("Case #%d: X won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				if ((board[j][i] == 'O')
				    || (board[j][i] == '.'))
					break;
			}
			if (j == 4)
				break;
		}
		if ((i < 4) && (!flag)) {
			printf("Case #%d: X won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			if ((board[i][i] == 'O') || (board[i][i] == '.'))
				break;
		}
		if ((i == 4) && (!flag)) {
			printf("Case #%d: X won\n", k + 1);
			flag = 1;
		}
		for (i = 0; i < 4; i++) {
			if ((board[i][3 - i] == 'O')
			    || (board[i][3 - i] == '.'))
				break;
		}
		if ((i == 4) && (!flag)) {
			printf("Case #%d: X won\n", k + 1);
			flag = 1;
		}
		if (draw && (!flag))
			printf("Case #%d: Draw\n", k + 1);
		else if ((!draw) && (!flag))
			printf("Case #%d: Game has not completed\n", k + 1);
	}
	return 0;
}
