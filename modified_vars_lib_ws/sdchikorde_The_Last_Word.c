#include <stdio.h>
#include <string.h>
#include <malloc.h>
void Main()
{
	int subject;
	char *str = (char *)malloc((sizeof(char)) * 1001);
	char *str2 = (char *)malloc((sizeof(char)) * 2002);
	char *r;
	char *v;
	scanf("%d", &subject);
	int q = 0;
	int count;
	while (q < subject) {
		q++;
		printf("Case #%d: ", q);
		scanf("%s", str);
		r = &str2[1001];
		v = r;
		for (count = 0; count < strlen(str); count++) {
			if (count == 0) {
				*v = str[count];
				v++;
			} else {
				if (str[count] < (*r)) {
					*v = str[count];
					v++;
				} else {
					r--;
					*r = str[count];
				}
			}
		}
		*v = '\0';
		printf("%s\n", r);
	}
}
