# include <stdio.h>
# include <stdlib.h>
long long star_dist[1000];

int cmpr(const void* a, const void* b)
{
    long long aa = *((long long*)a);
    long long bb = *((long long*)b);

    if(aa == bb)
        return 0;
    if(aa > bb)
        return 1;
    if(aa < bb)
        return -1;
}



int main(void)
{
    //var 
    long long t, l,time,n,c;
    long long temp=0,temp1,temp2,temp3;

    //loop
    long long i,j,k;


    scanf("%lld ",&t);

    for(i=0;i<t;i++)
    {
        scanf("%lld ",&l);
        scanf("%lld ",&time);
        scanf("%lld ",&n);
        scanf("%lld ",&c);

        for(j=0;j<c;j++)
        {
            scanf("%lld",&star_dist[j]);
            star_dist[j] *= 2;
        }

        for(j=0;j<n;j++)
        {
            star_dist[j] = star_dist[j%c];
        }

        temp = 0;
        // Solve
        if(l != 0)
            temp = time;

        for(j=0;j<n && (temp!=0);j++)
        {
            if(star_dist[j] <= temp)
            {
                temp -= star_dist[j];
                star_dist[j] = 0;
            }
            else
            {
                star_dist[j] -= temp;
                temp = 0;
            }
        }
        
        // find the two largest left over
        temp = 0;
        temp2 = 0;
        temp3 = 0;

        qsort(star_dist,n,sizeof(long long),&cmpr);
        for(j=0;j<n;j++)
        {
            temp3 += star_dist[j];
            if((n-1-j)<l)
                temp += star_dist[j];
/*
            if(star_dist[j] > temp)
                temp = star_dist[j];
            else if(star_dist[j] > temp2)
                temp2 = star_dist[j];
                */

        }

/*
        if(l == 0)
        {   temp = 0;
            temp2 = 0;}
        if(l == 1)
        {   temp2 = 0;}
*/
        

        if(l!=0)
            temp3 += time;
        temp3 = temp3 - temp + (temp/2) ;
        // output print
        printf("Case #%lld: %lld\n",i+1,temp3);
     }

    return 1;
}

