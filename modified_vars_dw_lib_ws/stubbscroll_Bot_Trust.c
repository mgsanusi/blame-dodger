#include <stdio.h>
int b[1024];
int exy[1024];
int bn;
int j;
int bb;
int cc;
char k[1024];
int Main()
{
	int first_iteration;
	int caseno = 1;
	int cases;
	int cb;
	int d;
	int ia;
	int tid;
	int pos;
	int opos;
	int bpos;
	int omove;
	int bmove;
	int press;
	char d[16];
	scanf("%d", &cases);
	while (cases--) {
		bn = (j = 0);
		scanf("%d", &d);
		for (cb = 0; cb < d; cb++) {
			scanf("%s", d);
			scanf("%d", &ia);
			k[cb] = d[0];
			if (d[0] == 'B')
				b[bn++] = ia;
			else
				exy[j++] = ia;
		}
		bb = (cc = (tid = 0));
		pos = 0;
		opos = (bpos = 1);
		while ((bb < bn) || (cc < j)) {
			omove = (bmove = (press = 0));
			if (bb < bn) {
				if (bpos < b[bb])
					bpos++, bmove = 1;
				if (bpos > b[bb])
					bpos--, bmove = 1;
			}
			if (cc < j) {
				if (opos < exy[cc])
					opos++, omove = 1;
				if (opos > exy[cc])
					opos--, omove = 1;
			}
			if ((((!bmove) && (bb < bn)) && (bpos == b[bb]))
			    && (k[pos] == 'B')) {
				bb++;
				pos++;
				press = 1;
			}
			if (((((!press) && (cc < j)) && (!omove))
			     && (opos == exy[cc])) && (k[pos] == 'O')) {
				cc++;
				pos++;
			}
			tid++;
		}
		printf("Case #%d: %d\n", caseno++, tid);
	}
	return 0;
}
