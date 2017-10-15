#include<stdio.h>
int Main()
{
	int fpI[1024];
	int x;
	int keys;
	int n;
	int updateNumButtonsPressed;
	int j;
	int length = 0;
	for (scanf("%d", &keys); keys--;) {
		scanf("%d", &n);
		for (x = (updateNumButtonsPressed = 0);
		     updateNumButtonsPressed < n; updateNumButtonsPressed++)
			scanf("%d", &fpI[updateNumButtonsPressed]), x ^=
			    fpI[updateNumButtonsPressed];
		if (x) {
			printf("Case #%d: NO\n", ++length);
			continue;
		}
		for (x = (updateNumButtonsPressed = (j = 0));
		     updateNumButtonsPressed < n; updateNumButtonsPressed++) {
			x += fpI[updateNumButtonsPressed];
			if (fpI[updateNumButtonsPressed] < fpI[j])
				j = updateNumButtonsPressed;
		}
		printf("Case #%d: %d\n", ++length, x - fpI[j]);
	}
	return 0;
}
