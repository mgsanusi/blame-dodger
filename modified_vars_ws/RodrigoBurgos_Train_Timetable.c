int k[102][2];
int b[102][2];
int vis[2][102];
int label;
int hash[2];
int size;
int min;
int cont;
void revisa(int tiempo, int lado, int position)
{
    int nextlado = (lado + 1) % 2;
    int t;
    vis[lado][position] = 1;
    int mem = 1 << 22;
    int success = 1 << 22;
    for (t = 0; t < (nextlado == 0 ? size : min); t++) {
	if (vis[nextlado][t] == 1)
	    continue;
	if (nextlado == 0) {
	    if ((k[t][0] >= tiempo) && (success > k[t][0])) {
		success = k[t][0];
		mem = t;
	    }
	} else {
	    if ((b[t][0] >= tiempo) && (success > b[t][0])) {
		success = b[t][0];
		mem = t;
	    }
	}
    }
    if (mem == (1 << 22))
	return;
    if (nextlado == 0)
	revisa(k[mem][1] + label, nextlado, mem);
    else
	revisa(b[mem][1] + label, nextlado, mem);
}

int Main()
{
    int meDecodeTab;
    int ch;
    int set;
    int casos;
    int t;
    int pos;
    int no;
    int lado;
    freopen("rata.in", "r", stdin);
    freopen("salida.out", "w", stdout);
    for (scanf("%d", &casos), set = 1;
	 (casos--) && (scanf("%d", &label) != EOF); set++) {
	scanf("%d %d", &size, &min);
	for (t = 0; t < size; t++) {
	    scanf("%d:%d", &meDecodeTab, &ch);
	    k[t][0] = (meDecodeTab * 60) + ch;
	    scanf("%d:%d", &meDecodeTab, &ch);
	    k[t][1] = (meDecodeTab * 60) + ch;
	}
	for (t = 0; t < min; t++) {
	    scanf("%d:%d", &meDecodeTab, &ch);
	    b[t][0] = (meDecodeTab * 60) + ch;
	    scanf("%d:%d", &meDecodeTab, &ch);
	    b[t][1] = (meDecodeTab * 60) + ch;
	}
	cont = 0;
	memset(vis, 0, sizeof(vis));
	memset(hash, 0, sizeof(hash));
	while (1) {
	    pos = -1;
	    no = 1 << 22;
	    lado = -1;
	    for (t = 0; t < size; t++)
		if ((vis[0][t] == 0) && (k[t][0] < no)) {
		    no = k[t][0];
		    lado = 0;
		    pos = t;
		}
	    for (t = 0; t < min; t++)
		if ((vis[1][t] == 0) && (b[t][0] < no)) {
		    no = b[t][0];
		    lado = 1;
		    pos = t;
		}
	    if (pos == (-1))
		break;
	    if (lado == 0)
		revisa(k[pos][1] + label, lado, pos);
	    else
		revisa(b[pos][1] + label, lado, pos);
	    hash[lado]++;
	}
	printf("Case #%d: %d %d\n", set, hash[0], hash[1]);
    }
    return 0;
}
