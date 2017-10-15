int graph[2002][2002 * 4];
int no_cases[2002][2002 * 4];
int ngraph[2002];
int Main()
{
    int first_iteration;
    int set;
    int casos;
    int query;
    int i;
    int i;
    int ot;
    int mask;
    int ban;
    int case_t;
    int i;
    int i;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    for (set = 1, scanf("%d", &casos); casos--; set++) {
	scanf("%d", &query);
	scanf("%d", &i);
	memset(ngraph, 0, sizeof(ngraph));
	for (i = 0; i < i; i++) {
	    scanf("%d", &case_t);
	    for (; case_t--;) {
		scanf("%d %d", &i, &i);
		i--;
		no_cases[i][(i * 2) + i] = set;
		graph[i][ngraph[i]++] = (i * 2) + i;
	    }
	}
	printf("Case #%d:", set);
	for (mask = 0; mask < (1 << query); mask++) {
	    ban = 0;
	    for (i = 0; (i < i) && (ban == 0); i++) {
		for (ot = 0; ot < query; ot++) {
		    case_t = (mask & (1 << ot)) > 0 ? 1 : 0;
		    if (no_cases[i][(ot * 2) + case_t] == set)
			break;
		}
		if (ot >= query)
		    ban = 1;
	    }
	    if (ban == 0) {
		for (i = 0; i < query; i++)
		    printf(" %d", (mask & (1 << i)) == 0 ? 0 : 1);
		printf("\n");
		break;
	    }
	}
	if (mask >= (1 << query))
	    printf(" IMPOSSIBLE\n");
    }
    return 0;
}
