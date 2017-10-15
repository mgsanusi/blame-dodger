#include <stdio.h>
#include <string.h>
int Main()
{
    int check[] =
	{ 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
  0, 0, 0, 0 };
    long long int group;
    long long int cur;
    long long int result;
    int idx;
    int j;
    char sen[1000005];
    int dx;
    int n;
    int len;
    scanf("%d", &dx);
    for (idx = 0; idx < dx; idx++) {
	scanf("%s %d", sen, &n);
	len = strlen(sen);
	group = 1;
	cur = 0;
	result = 0;
	for (j = 0; j < len; j++) {
	    group++;
	    if (check[sen[j] - 'a'] == 1) {
		if (cur != 0)
		    cur = 0;
	    } else {
		cur++;
		if (cur == n) {
		    group -= n;
		    result += group * (len - j);
		    cur--;
		    group = n;
		}
	    }
	}
	printf("Case #%d: %lld\n", idx + 1, result);
    }
    return 0;
}
