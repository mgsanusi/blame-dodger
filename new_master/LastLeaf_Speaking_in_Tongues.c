#include <stdio.h>
#include <stdlib.h>

char srcs[] = {"ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvzq"};
char dess[] = {"ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupqz"};
char maps[128] = {0};

int main()
{
	int i, test, testc;
	char s[101];
	
	freopen("gcj1_1.in", "r", stdin);
	freopen("gcj1_1.out", "w", stdout);
	
	for(i=0; srcs[i]; i++) {
		maps[(int)srcs[i]] = dess[i];
		maps[(int)srcs[i]-32] = dess[i]-32;
		maps[(int)' '] = ' ';
	}
	
	scanf("%d\n", &testc);
	for(test=1; test<=testc; test++) {
		gets(s);
		for(i=0; s[i]; i++)
			s[i] = maps[(int)s[i]];
		printf("Case #%d: %s\n", test, s);
	}
	
	return 0;
}
