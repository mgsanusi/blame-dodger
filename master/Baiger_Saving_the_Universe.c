#include <stdio.h>
#include <string.h>

#define MAXCNT 101
#define MAXLEN 110

char names[MAXCNT][MAXLEN];
int hash[1500];

int calc_hash(char s[])
{
     int sum = 0, i;
     for (i = 0; s[i] != '\0'; i++)
	  sum += s[i];
     return sum % 1000;
}

int main()
{
     int n, i;
     scanf("%d", &n);
     for (i = 1; i <= n; i++) {
	  int s, q, j;
	  scanf("%d\n", &s);
	  memset(hash, 0, sizeof(hash));
	  memset(names, 0, sizeof(names));
	  for (j = 1; j <= s; j++) {
	       int k, c;
	       for (k = 0; (c=getchar()) != '\n'; k++)
		    names[j][k] = c;
	       int key = calc_hash(names[j]);
	       while (hash[key] != 0)
		    key++;
	       hash[key] = j;
	  }
	  scanf("%d\n", &q);
	  int used[MAXCNT], cnt_used = 0, cnt_switch = 0;
	  char query[MAXLEN];
	  memset(used, 0, sizeof(used));
	  for (j = 0; j < q; j++) {
	       int k, c;
	       for (k = 0; (c=getchar()) != '\n'; k++)
		    query[k] = c;
	       query[k] = '\0';
	       int key = calc_hash(query);
	       while (hash[key] && strcmp(query, names[hash[key]]))
		    key++;
	       if (hash[key]) {
		    cnt_used += 1-used[hash[key]];
		    used[hash[key]] = 1;
		    if (cnt_used == s) {
			cnt_switch++;
			cnt_used = 1;
			memset(used, 0, sizeof(used));
			used[hash[key]] = 1;
		    }
	       }
	  }
	  
	  printf("Case #%d: %d\n", i, cnt_switch);
     }
     
     return 0;
}
