#include<stdio.h>
typedef long long ll;
int n,a[100],b[100];
int Qsort(int left,int right)
{
	int mid,i,j;

	int tmp;

	i=left;
	j=right;
	mid=a[(left+right)/2];
	do
	{
		while(a[i]<mid)
		i++;
		while(mid<a[j])
		j--;
		if(i<=j)
		{
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
			i++;
			j--;
		}
	}while(i<=j);
	if(left<j)
	Qsort(left,j);
	if(i<right)
	Qsort(i,right);
}
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);

    int t,cs,i,j,k,r;
    ll c,t1,t2;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%lld %d",&c,&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        if(c==1)
        {
            printf("Case #%d: %d\n",cs,n);
            continue;
        }
        Qsort(0,n-1);
        r=0;
        for(i=0;i<n;i++)
        {
            if(c>a[i])
            {
                c+=a[i];
                b[i]=0;
            }
            else
            {
                for(j=1,t1=c+c-1;t1<=a[i];j++,t1=2*t1-1);
                c=t1+a[i];
                b[i]=j;
            }
        }
        k=n;
        for(i=0,r=0;i<n;i++)
        {
            r+=b[i];
            if((r+n-i-1)<k)k=r+n-i-1;
        }
        printf("Case #%d: %d\n",cs,k);
    }

    return 0;
}
