#include <stdio.h>
char c[20000];
char counter[256][256];
char target[256][256];
char opp[8] = { '1', '2', 'i', 'I', 'j', 'J', 'k', 'K' };

char inv[256];
int asd(int t, int n)
{
	int res;
	char vv = '1';
	for (res = 0; res < (n * t); res++) {
		vv = counter[vv][c[res % t]];
		if (vv == 'i')
			goto jck;
	}
	return 0;
 jck:
	vv = '1', ++res;
	for (; res < (n * t); res++) {
		vv = counter[vv][c[res % t]];
		if (vv == 'j')
			goto kck;
	}
	return 0;
 kck:
	vv = '1', ++res;
	for (; res < (n * t); res++)
		vv = counter[vv][c[res % t]];
	return vv == 'k';
}

int Main()
{
	int first;
	int size;
	int t;
	int n;
	int f1;
	int res;
	int j;
	scanf("%d", &size);
	counter['1']['1'] = (counter['2']['2'] = '1');
	counter['i']['I'] = (counter['I']['i'] = '1');
	counter['j']['J'] = (counter['J']['j'] = '1');
	counter['k']['K'] = (counter['K']['k'] = '1');
	counter['1']['2'] = (counter['2']['1'] = '2');
	counter['I']['I'] = (counter['i']['i'] = '2');
	counter['J']['J'] = (counter['j']['j'] = '2');
	counter['K']['K'] = (counter['k']['k'] = '2');
	counter['i']['1'] = (counter['1']['i'] = 'i');
	counter['i']['2'] = (counter['2']['i'] = 'I');
	counter['I']['1'] = (counter['1']['I'] = 'I');
	counter['I']['2'] = (counter['2']['I'] = 'i');
	counter['j']['1'] = (counter['1']['j'] = 'j');
	counter['j']['2'] = (counter['2']['j'] = 'J');
	counter['J']['1'] = (counter['1']['J'] = 'J');
	counter['J']['2'] = (counter['2']['J'] = 'j');
	counter['k']['1'] = (counter['1']['k'] = 'k');
	counter['k']['2'] = (counter['2']['k'] = 'K');
	counter['K']['1'] = (counter['1']['K'] = 'K');
	counter['K']['2'] = (counter['2']['K'] = 'k');
	counter['i']['j'] = (counter['j']['I'] = 'k');
	counter['i']['J'] = (counter['J']['I'] = 'K');
	counter['I']['j'] = (counter['j']['i'] = 'K');
	counter['I']['J'] = (counter['J']['i'] = 'k');
	counter['j']['k'] = (counter['K']['j'] = 'i');
	counter['j']['K'] = (counter['k']['j'] = 'I');
	counter['J']['k'] = (counter['K']['J'] = 'I');
	counter['J']['K'] = (counter['k']['J'] = 'i');
	counter['k']['i'] = (counter['I']['k'] = 'j');
	counter['k']['I'] = (counter['i']['k'] = 'J');
	counter['K']['i'] = (counter['I']['K'] = 'J');
	counter['K']['I'] = (counter['i']['K'] = 'j');
	for (res = 0; res < 8; res++)
		for (j = 0; j < 8; j++)
			target[opp[res]][counter[opp[res]][opp[j]]] = opp[j];
	inv['1'] = '2', inv['2'] = '1';
	inv['i'] = 'I', inv['I'] = 'i';
	inv['j'] = 'J', inv['J'] = 'j';
	inv['k'] = 'K', inv['K'] = 'k';
	for (first = 1; first <= size; first++) {
		scanf("%d %d", &t, &n);
		scanf("%s", c);
		f1 = 1;
		if (t == 1)
			f1 = 0;
		else if ((t == 2) && (n == 1))
			f1 = 0;
		else
			f1 = asd(t, n);
		printf("Case #%d: %s\n", first, f1 ? "YES" : "NO");
	}
}
