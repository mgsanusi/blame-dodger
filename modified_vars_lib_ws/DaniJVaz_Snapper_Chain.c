#include <stdio.h>
void doTestCase();
int Main()
{
    int no;
    int ans;
    scanf("%d", &ans);
    for (no = 1; no <= ans; no++) {
	printf("Case #%d: ", no);
	doTestCase();
    }
    return 0;
}

void doTestCase()
{
    int ans;
    int dy;
    scanf("%d %d", &ans, &dy);
    if (((dy + 1) & ((1 << ans) - 1)) != 0)
	printf("OFF\n");
    else
	printf("ON\n");
    return;
}
