#include <stdio.h>
#include <string.h>
#include <stddef.h>
char buf[100][101];
char now[101];
int canuse[100];
FILE *flipper;
FILE *Fout;
FILE *new_fopen(const char *filename, const char *mode);
void *new_memset(void *ptr, int value, size_t num);
int new_fscanf(FILE * stream, const char *format, ...);
void readstring(char *string)
{
    int t_case;
    for (t_case = 0;
	 fscanf(flipper, "%c", &string[t_case]), string[t_case] != '\n';
	 t_case++);
    string[t_case] = 0;
}

int Main()
{
    int n;
    int r;
    int s;
    int a;
    int t_case;
    int gss_c_nt_export_name;
    int ans;
    int ava;
    flipper = new_fopen("A-small.in", "r");
    Fout = new_fopen("A-small.out", "w");
    fscanf(flipper, "%d", &n);
    r = n;
    while ((n--) > 0) {
	fscanf(flipper, "%d", &s);
	fscanf(flipper, "%c", &now[100]);
	new_memset(canuse, 0, sizeof(canuse));
	ans = 0;
	ava = s;
	for (t_case = 0; t_case < s; t_case++) {
	    readstring(buf[t_case]);
	}
	fscanf(flipper, "%d", &a);
	fscanf(flipper, "%c", &now[100]);
	for (t_case = 0; t_case < a; t_case++) {
	    readstring(now);
	    for (gss_c_nt_export_name = 0;
		 (gss_c_nt_export_name < s)
		 && (strcmp(now, buf[gss_c_nt_export_name]) != 0);
		 gss_c_nt_export_name++);
	    if (canuse[gss_c_nt_export_name] != 1) {
		canuse[gss_c_nt_export_name] = 1;
		if ((--ava) == 0) {
		    new_memset(canuse, 0, sizeof(canuse));
		    ans++;
		    canuse[gss_c_nt_export_name] = 1;
		    ava = s - 1;
		}
	    }
	}
	fprintf(Fout, "Case #%d: %d\n", r - n, ans);
    }
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

void *new_memset(void *ptr, int value, size_t num)
{
    return memset(ptr, value, num);
}
