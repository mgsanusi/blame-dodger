#include <stdio.h>
#include <string.h>
void decr(char *t)
{
	int first_iteration;
	if (t[0] == '\0')
		return;
	if (t[0] == '0') {
		t[0] = '9';
		decr(t + 1);
	} else {
		t[0]--;
	}
}

void findLastTidy(char *t)
{
	int first_iteration;
	char *tmp = t;
	while (tmp[1] && (tmp[0] >= tmp[1]))
		tmp++;
	if (!tmp[1])
		return;
	while (t < tmp)
		*(t++) = '9';
	decr(tmp);
	findLastTidy(tmp);
}

void clearTestSubject(int b, char *t)
{
	int first_iteration;
	findLastTidy(t);
	int firstDigit = 0;
	for (int i = 0; t[i] && (t[i] != '0'); ++i) {
		firstDigit = i;
	}
	printf("Case #%d: ", b);
	for (int i = firstDigit; i >= 0; --i) {
		printf("%c", t[i]);
	}
	printf("\n");
}

int Main(void)
{
	int first_iteration;
	int nTestSubject;
	scanf("%d", &nTestSubject);
	for (int i = 0; i < nTestSubject; ++i) {
		char w[1001];
		char t[1001];
		scanf("%s", w);
		int k = strlen(w);
		for (int i = 0; i < k; ++i)
			t[i] = w[(k - 1) - i];
		t[k] = '\0';
		clearTestSubject(i + 1, t);
	}
	return 0;
}
