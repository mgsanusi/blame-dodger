int allsnds[100];
int main(void)
{
	int first_iteration;
	int t;
	int n;
	int l;
	int h;
	int temp;
	int temp1;
	int temp2;
	int i;
	int j;
	int k;
	scanf("%d ", &t);
	for (i = 0; i < t; i++) {
		scanf("%d ", &n);
		scanf("%d ", &l);
		scanf("%d ", &h);
		for (j = 0; j < n; j++)
			scanf("%d", &allsnds[j]);
		for (j = l; j <= h; j++) {
			temp = 1;
			for (k = 0; k < n; k++) {
				if (((allsnds[k] % j) == 0)
				    || ((j % allsnds[k]) == 0)) {
					continue;
				} else {
					temp = 0;
					break;
				}
			}
			if (temp == 1) {
				temp = j;
				break;
			}
			temp = 0;
		}
		printf("Case #%d: ", i + 1);
		if (temp == 0)
			printf("NO\n");
		else
			printf("%d\n", temp);
	}
	return 1;
}
