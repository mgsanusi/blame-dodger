#include<stdio.h>
int a[100][100],r[100],c[100],n,m;
int main()
{
    freopen("C:\\Users\\vivek\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\vivek\\Desktop\\out.txt","w",stdout);

    int t,i,j,k,cs;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<100;i++)r[i]=c[i]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]>r[i])r[i]=a[i][j];
                if(a[i][j]>c[j])c[j]=a[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;(j<m)&&((a[i][j]>=r[i])||(a[i][j]>=c[j]));j++);
            if(j<m)break;
        }
        if(i<n)
        printf("Case #%d: NO\n",cs);
        else
        printf("Case #%d: YES\n",cs);
    }
    return 0;
}
