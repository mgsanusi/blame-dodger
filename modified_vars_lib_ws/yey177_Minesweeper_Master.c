#include <stdio.h>
int new_putchar(int character);
int new_puts(const char *str);
int Main()
{
    int x;
    int cas;
    int n;
    int n;
    int x;
    int gss_c_nt_user_name;
    int tn;
    int in;
    int l;
    int low;
    int high;
    scanf("%d", &x);
    for (cas = 1; cas <= x; cas++) {
	scanf("%d%d%d", &n, &n, &x);
	printf("Case #%d:\n", cas);
	if (n == 1) {
	    for (gss_c_nt_user_name = 0; gss_c_nt_user_name < x;
		 gss_c_nt_user_name++)
		new_putchar('*');
	    for (gss_c_nt_user_name = x; gss_c_nt_user_name < (n - 1);
		 gss_c_nt_user_name++)
		new_putchar('.');
	    new_puts("c");
	    continue;
	} else if (n == 1) {
	    for (gss_c_nt_user_name = 0; gss_c_nt_user_name < x;
		 gss_c_nt_user_name++)
		new_puts("*");
	    for (gss_c_nt_user_name = x; gss_c_nt_user_name < (n - 1);
		 gss_c_nt_user_name++)
		new_puts(".");
	    new_puts("c");
	    continue;
	} else if (x == ((n * n) - 1)) {
	    for (gss_c_nt_user_name = 1; gss_c_nt_user_name <= n;
		 gss_c_nt_user_name++) {
		for (tn = 1; tn <= n; tn++) {
		    new_putchar((gss_c_nt_user_name == n)
				&& (tn == n) ? 'c' : '*');
		}
		new_puts("");
	    }
	    continue;
	}
	for (gss_c_nt_user_name = 0; gss_c_nt_user_name <= (n - 2);
	     gss_c_nt_user_name++) {
	    for (tn = 0; tn <= (n - 2); tn++) {
		low = (n * n) - ((n - gss_c_nt_user_name) * (n - tn));
		high =
		    low +
		    (((n - 2) - gss_c_nt_user_name) * ((n - 2) - tn));
		if ((low <= x) && (x <= high)) {
		    x -= low;
		    for (in = 1; in <= gss_c_nt_user_name; in++) {
			for (l = 1; l <= n; l++)
			    new_putchar('*');
			new_puts("");
		    }
		    for (in = gss_c_nt_user_name + 1; in <= (n - 2); in++) {
			for (l = 1; l <= tn; l++)
			    new_putchar('*');
			for (l = tn + 1; l <= (n - 2); l++) {
			    new_putchar(x > 0 ? '*' : '.');
			    x--;
			}
			new_puts("..");
		    }
		    for (in = n - 1; in <= n; in++) {
			for (l = 1; l <= tn; l++)
			    new_putchar('*');
			for (l = tn + 1; l <= n; l++)
			    new_putchar((in == n) && (l == n) ? 'c' : '.');
			new_puts("");
		    }
		    goto END;
		}
	    }
	}
	new_puts("Impossible");
      END:
	continue;
    }
    return 0;
}

int new_putchar(int character);
int new_puts(const char *str)
{
    return puts(str);
}

int new_putchar(int character)
{
    return putchar(character);
}
