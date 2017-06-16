#include<stdio.h>
#include<string.h>
int f(char* s)
{
    int i, cha=0;
    char mem=s[0];
    for(i=1;s[i]!='\0';i++)
    {
        if(s[i]!=mem)
        {
            mem=s[i];
            cha++;
        }
    }
    if(s[i-1]=='+')
        return cha;
    return cha+1;
}

int main()
{
    int t, i;
    char s[101];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",s);
        printf("Case #%d: %d\n",i+1,f(s));
    }
	return 0;
}

