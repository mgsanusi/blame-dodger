#include <stdio.h>
#include <stdlib.h>

int ischaracter(char c) {
	if ((c < 'A') || (c > 'Z')) {
		return 0;
	}
	return 1;
}

void dec(int * c_array, int c, int i) {
	if (c == 0) {
		c_array['Z'] -= i;
		c_array['E'] -= i;
		c_array['R'] -= i;
		c_array['O'] -= i;
	}
	if (c == 1) {
		c_array['O'] -= i;
		c_array['N'] -= i;
		c_array['E'] -= i;
	}
	if (c == 2) {
		c_array['T'] -= i;
		c_array['W'] -= i;
		c_array['O'] -= i;
	}
	if (c == 3) {
		c_array['T'] -= i;
		c_array['H'] -= i;
		c_array['R'] -= i;
		c_array['E'] -= i;
		c_array['E'] -= i;
	}
	if (c == 4) {
		c_array['F'] -= i;
		c_array['O'] -= i;
		c_array['U'] -= i;
		c_array['R'] -= i;
	}
	if (c == 5) {
		c_array['F'] -= i;
		c_array['I'] -= i;
		c_array['V'] -= i;
		c_array['E'] -= i;
	}
	if (c == 6) {
		c_array['S'] -= i;
		c_array['I'] -= i;
		c_array['X'] -= i;
	}
	if (c == 7) {
		c_array['S'] -= i;
		c_array['E'] -= i;
		c_array['V'] -= i;
		c_array['E'] -= i;
		c_array['N'] -= i;
	}
	if (c == 8) {
		c_array['E'] -= i;
		c_array['I'] -= i;
		c_array['G'] -= i;
		c_array['H'] -= i;
		c_array['T'] -= i;
	}
	if (c == 9) {
		c_array['N'] -= i;
		c_array['I'] -= i;
		c_array['N'] -= i;
		c_array['E'] -= i;
	}
}

void inc(int * c_array, int * i_array, int c, int i) {
		int i_temp = c_array[c];
		i_array[i] = i_array[i] + i_temp;
		dec(c_array, i, i_temp);
		// printf("%d:%d ", i, i_temp);
}

int main() {
	int n_max;
	int n_count;
	char c_temp;
	int c_bool;
	int i_temp;
	int cycle;

	scanf("%d", &n_max);
	scanf("%c", &c_temp);
	int * c_array = (int *)malloc(256 * sizeof(int));
	int * i_array = (int *)malloc(10 * sizeof(int));

	n_count = 0;



	while (n_count < n_max) {
		n_count ++;
		printf("Case #%d: ", n_count);

		cycle = 'A';
		while (cycle <= 'Z') {
			c_array[cycle] = 0;
			cycle ++;		
		}

		cycle = 0;
		while (cycle < 10) {
			i_array[cycle] = 0;
			cycle ++;
		}	

		c_bool = 1;
		while (c_bool) {
			scanf("%c", &c_temp);
			if (ischaracter(c_temp)) {
				c_array[c_temp] ++;
				// printf("scaned %c\n", c_temp);
			}
			else {
				c_bool = 0;
			}
		}
		
		inc(c_array, i_array, 'Z', 0);
		inc(c_array, i_array, 'U', 4);
		inc(c_array, i_array, 'F', 5);
		inc(c_array, i_array, 'R', 3);
		inc(c_array, i_array, 'W', 2);
		inc(c_array, i_array, 'X', 6);
		inc(c_array, i_array, 'V', 7);
		inc(c_array, i_array, 'T', 8);
		inc(c_array, i_array, 'I', 9);
		inc(c_array, i_array, 'O', 1);

		cycle = 0;
		while (cycle < 10) {
			while (i_array[cycle] > 0) {
				printf("%d", cycle);
				i_array[cycle] --;
			}
			cycle ++;
		}
		
		printf("\n");
	}
	
}
