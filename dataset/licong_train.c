#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000000

char train[100][1001];
int trainnum[100];
int res[100];
int use[100];
int m;
int N;

void gettrain(int p)
{
    char ch,ch0;
    while (1)
    {
        ch = getchar();
        if (ch>='a' && ch<='z')
            break;
    }
    ch0 = 0;
    trainnum[p] = 0;
    while (1)
    {
        if (ch!=ch0)
        {
                    trainnum[p]++;
        train[p][trainnum[p]-1] = ch;
        }
        ch0 = ch;
        ch = getchar();
        if (!(ch>='a' && ch<='z'))
            break;
    }
}

int checkcase()
{
    int p,subp;
    char ch,ch0;
    char usechar[255];
    int l1;
    int flag;

    p = 0;
    subp = 0;
    ch0 = 0;
    for (l1='a';l1<='z';l1++)
        usechar[l1] = 0;
    flag = 1;

    while ( p!=m )
    {
        ch = train[res[p]][subp];
        if (ch!=ch0)
            if (usechar[ch] == 1)
            {
                flag = 0;
                break;
            }
            else
                usechar[ch] = 1;
        ch0 = ch;
        subp++;
        if (subp == trainnum[res[p]])
        {
            p++;
            subp = 0;
        }
    }
    return flag;
}

int getcase()
{
    int l1;
    int resnum;

    if (!checkcase())
        return 0;

    if (m ==N)
        return 1;

    resnum =0;
    for (l1=0;l1<N;l1++)
        if (use[l1]==0)
        {
            use[l1] = 1;
            res[m] = l1;
            m++;
            resnum+=getcase();
            m--;
            use[l1] = 0;
        }
    return resnum;
}


int main()
{
    int iCase, T;
    int l1;

    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&T);
    for (iCase=1;iCase<=T;iCase++)
    {
        scanf("%d",&N);
        for (l1=0;l1<N;l1++)
            gettrain(l1);
        for (l1=0;l1<N;l1++)
            use[l1] = 0;
        m=0;
        printf("Case #%d: %d\n",iCase,getcase());
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
