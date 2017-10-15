int Main()
{
    int first_iteration;
    int ret;
    int visited;
    int at;
    int n;
    int caseno[1000];
    long long gain[1000];
    int prev[1000];
    long long sum;
    int counter;
    int pd;
    int s;
    int a;
    int n;
    int l;
    int i1;
    int loop;
    scanf("%d", &ret);
    for (counter = 0; counter < ret; counter++) {
	scanf("%d%d%d", &visited, &at, &n);
	for (pd = 0; pd < n; pd++) {
	    scanf("%d", &caseno[pd]);
	}
	memset(gain, 255, (sizeof(long long)) * 1000);
	memset(prev, 255, (sizeof(int)) * 1000);
	sum = 0;
	s = 0;
	loop = 0;
	for (pd = 0; pd < visited; pd++) {
	    if ((!loop) && (prev[s] != (-1))) {
		loop = ((visited - pd) - 1) / (pd - prev[s]);
		sum += loop * (sum - gain[s]);
		pd += loop * (pd - prev[s]);
	    }
	    prev[s] = pd;
	    gain[s] = sum;
	    i1 = 0;
	    for (n = 0; n < n; n++) {
		if ((caseno[(n + s) % n] + i1) <= at) {
		    i1 += caseno[(n + s) % n];
		} else {
		    break;
		}
	    }
	    sum += i1;
	    s = (s + n) % n;
	}
	printf("Case #%d: %lld\n", counter + 1, sum);
    }
}
