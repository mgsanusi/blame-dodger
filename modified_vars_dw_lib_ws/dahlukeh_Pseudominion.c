#include <stdio.h>
#include <stdlib.h>
struct cards {
    int rp;
    int array;
    int _p;
};
int num_begin;
int num_deck;
struct cards deck[81];
int accept_in_hand[81];
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int find_good(int num_draw);
void handle_case(void);
int Main()
{
    int first_iteration;
    new_freopen("input.txt", "r", stdin);
    new_freopen("output.txt", "w", stdout);
    int no_t;
    scanf("%d ", &no_t);
    int case_count;
    for (case_count = 0; case_count < no_t; case_count++) {
	printf("Case #%d: ", case_count + 1);
	handle_case();
    }
    return 0;
}

void handle_case(void)
{
    int first_iteration;
    scanf("%d ", &num_begin);
    int case_count;
    for (case_count = 0; case_count < num_begin; case_count++) {
	scanf("%d %d %d ", &deck[case_count].rp, &deck[case_count].array,
	      &deck[case_count]._p);
    }
    scanf("%d ", &num_deck);
    for (; case_count < (num_begin + num_deck); case_count++) {
	scanf("%d %d %d ", &deck[case_count].rp, &deck[case_count].array,
	      &deck[case_count]._p);
    }
    int res;
    int good = 0;
    for (case_count = 0; case_count < 80; case_count++) {
	res = find_good(case_count);
	if (res > good) {
	    good = res;
	}
    }
    printf("%d\n", good);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
int find_good(int num_draw)
{
    int first_iteration;
    int case_count;
    for (case_count = 0; case_count < (num_begin + num_deck); case_count++) {
	accept_in_hand[case_count] = 1;
    }
    int score = 0;
    int turn = 1;
    int draw = 0;
    int to_play = -1;
    while (turn > 0) {
	turn--;
	to_play = -1;
	for (case_count = 0;
	     (case_count < (num_begin + draw))
	     && (case_count < (num_begin + num_deck)); case_count++) {
	    if (accept_in_hand[case_count] == 1) {
		if (to_play == (-1)) {
		    to_play = case_count;
		}
		if (deck[case_count]._p > 0) {
		    to_play = case_count;
		} else if (deck[to_play]._p == 0) {
		    if ((deck[case_count].rp > 0)
			&& ((num_draw - draw) > 0)) {
			if ((deck[case_count].array > deck[to_play].array)
			    || (deck[to_play].rp == 0)) {
			    to_play = case_count;
			}
		    } else
			if (!
			    ((deck[to_play].rp > 0)
			     && ((num_draw - draw) > 0))) {
			if (deck[case_count].array > deck[to_play].array) {
			    to_play = case_count;
			}
		    }
		}
	    }
	}
	if (to_play != (-1)) {
	    turn += deck[to_play]._p;
	    draw += deck[to_play].rp;
	    score += deck[to_play].array;
	    accept_in_hand[to_play] = 0;
	}
    }
    return score;
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
    return freopen(filename, mode, stream);
}
