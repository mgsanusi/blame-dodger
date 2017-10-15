#include <stdio.h>
#include <string.h>

char a[]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
char b[]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
char c[]="de kr kd eoya kw aej tysr re ujdr lkgc jv";

char d[]="our language is impossible to understand";
char e[]="there are twenty six factorial possibilities";
char f[]="so it is okay if you want to just give up";

int map[256];

void makemap(char *s,char *t) {
  while(*s) map[(int)*(s++)]=*(t++);
}

char s[16384];

int main() {
  int caseno=1,T,i;
  memset(map,0,sizeof(map));
  makemap(a,d);
  makemap(b,e);
  makemap(c,f);
  map['q']='z';
  map['z']='q';
  gets(s); sscanf(s,"%d",&T);
  while(T--) {
    gets(s);
    for(i=0;s[i];i++) s[i]=map[(int)s[i]];
    printf("Case #%d: %s\n",caseno++,s);
  }
  return 0;
}
