int min(int a, int s)
{
    if (a < s)
	return a;
    else
	return s;
}

int Main()
{
    int former;
    int height;
    int base;
    int curl;
    int res;
    int v;
    int a;
    int s;
    int size;
    int x;
    int val[10010];
    int change[10010];
    int cost0[10010];
    int cost1[10010];
    scanf("%d", &former);
    for (curl = 1; curl <= former; curl++) {
	scanf("%d%d", &height, &base);
	for (res = 0; res < ((height - 1) / 2); res++) {
	    scanf("%d", &val[res]);
	    scanf("%d", &change[res]);
	}
	for (res = (height - 1) / 2; res < height; res++) {
	    scanf("%d", &val[res]);
	    cost0[res] = (cost1[res] = 1000000);
	    if (val[res])
		cost1[res] = 0;
	    else
		cost0[res] = 0;
	}
	int q = 10000;
	for (res = ((height - 1) / 2) - 1; res >= 0; res--) {
	    cost0[res] = 1000000;
	    cost1[res] = 1000000;
	    a = cost1[(res * 2) + 1] + cost1[(res * 2) + 2];
	    s = cost1[(res * 2) + 1] + cost0[(res * 2) + 2];
	    size = cost0[(res * 2) + 1] + cost1[(res * 2) + 2];
	    x = cost0[(res * 2) + 1] + cost0[(res * 2) + 2];
	    if (val[res]) {
		cost1[res] = min(cost1[res], a);
		cost0[res] = min(cost0[res], s);
		cost0[res] = min(cost0[res], size);
		cost0[res] = min(cost0[res], x);
	    } else {
		cost1[res] = min(cost1[res], a);
		cost1[res] = min(cost1[res], s);
		cost1[res] = min(cost1[res], size);
		cost0[res] = min(cost0[res], x);
	    }
	    if (change[res]) {
		if (val[res]) {
		    cost1[res] = min(cost1[res], a + 1);
		    cost1[res] = min(cost1[res], s + 1);
		    cost1[res] = min(cost1[res], size + 1);
		    cost0[res] = min(cost0[res], x + 1);
		} else {
		    cost1[res] = min(cost1[res], a + 1);
		    cost0[res] = min(cost0[res], s + 1);
		    cost0[res] = min(cost0[res], size + 1);
		    cost0[res] = min(cost0[res], x + 1);
		}
	    }
	}
	if (base)
	    q = cost1[0];
	else
	    q = cost0[0];
	if (q >= 10000)
	    printf("Case #%d: IMPOSSIBLE\n", curl);
	else
	    printf("Case #%d: %d\n", curl, q);
    }
}
