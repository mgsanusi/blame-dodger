#include<stdio.h>
int l;
int map[4][4] =
    { {1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1} };
int p[10000];
int get_int()
{
    char k;
    while (k = getchar(), (k < '0') || (k > '9')) {
    }
    int answer = 0;
    while ((k >= '0') && (k <= '9')) {
	answer = ((answer * 10) + k) - '0';
	k = getchar();
    }
    return answer;
}

int get_longlong()
{
    char k;
    while (k = getchar(), (k < '0') || (k > '9')) {
    }
    long long answer = 0;
    while ((k >= '0') && (k <= '9')) {
	answer = ((answer * 10) + k) - '0';
	k = getchar();
    }
    return answer;
}

int b(long long left, long long right)
{
    if (left == right) {
	return p[left % l];
    } else {
	long long mid = (left + right) / 2;
	int left_value = b(left, mid);
	int right_value = b(mid + 1, right);
	if ((left_value > 0) && (right_value > 0)) {
	    return map[left_value - 1][right_value - 1];
	}
	if ((left_value > 0) && (right_value < 0)) {
	    return (-1) * map[left_value - 1][((-1) * right_value) - 1];
	}
	if ((left_value < 0) && (right_value > 0)) {
	    return (-1) * map[((-1) * left_value) - 1][right_value - 1];
	}
	if ((left_value < 0) && (right_value < 0)) {
	    return map[((-1) * left_value) - 1][((-1) * right_value) - 1];
	}
    }
}

int Main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int index;
    int j;
    int a;
    int n;
    int res;
    int left;
    int right;
    int temp;
    int len_i;
    int len_k;
    long long i2;
    long long len;
    long long i_index[10000];
    long long index_k[10000];
    long long itr;
    n = get_int();
    for (a = 1; a <= n; a++) {
	l = get_int();
	i2 = get_longlong();
	len = i2 * l;
	for (index = 0; index < l; index++) {
	    p[index] = (getchar() - 'i') + 2;
	}
	res = 0;
	if ((len >= 3) && (b(0, len - 1) == (-1))) {
	    temp = 1;
	    len_i = 0;
	    for (itr = 0; itr < len; itr++) {
		if (temp > 0) {
		    temp = map[temp - 1][p[itr % l] - 1];
		} else {
		    temp = (-1) * map[((-1) * temp) - 1][p[itr % l] - 1];
		}
		if (temp == 2) {
		    i_index[len_i++] = itr;
		}
	    }
	    temp = 1;
	    len_k = 0;
	    for (itr = len - 1; itr >= 0; itr--) {
		if (temp > 0) {
		    temp = map[p[itr % l] - 1][temp - 1];
		} else {
		    temp = (-1) * map[p[itr % l] - 1][((-1) * temp) - 1];
		}
		if (temp == 4) {
		    index_k[len_k++] = itr;
		}
	    }
	    for (index = 0; index < len_i; index++) {
		if (res)
		    break;
		for (j = 0; j < len_k; j++) {
		    if ((index_k[j] - i_index[index]) > 1) {
			if (b(i_index[index] + 1, index_k[j] - 1) == 3) {
			    res = 1;
			    break;
			}
		    }
		}
	    }
	} else {
	    res = 0;
	}
	if (res)
	    printf("Case #%d: YES\n", a);
	else
	    printf("Case #%d: NO\n", a);
    }
}
