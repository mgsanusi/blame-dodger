# include <stdio.h>
# define MAX_TEAMS 10

char teams[MAX_TEAMS][MAX_TEAMS];
int teams_won[MAX_TEAMS];
int teams_played[MAX_TEAMS];
double teams_owp[MAX_TEAMS];
double teams_oowp[MAX_TEAMS];

int main(void)
{
    //var
    int t,n,a,b;
    double wp_sum;
    //loop
    int i,j,k;
    char temp;

    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d ",&n);
        for(j=0;j<n;j++)
        {
            teams_won[j] = 0;
            teams_played[j] = 0;
            teams_owp[j] = 0;
            teams_oowp[j] = 0;

            for(k=0;k<n;k++)
                scanf("%c ",&teams[j][k]);
                //printf(">>%c<<\n",teams[j][k]);}
        }
         //scanf("%c",&temp);

        for(j=0;j<n;j++)
            for(k=0;k<n;k++)
            {
                switch(teams[j][k])
                {
                    case '.': break; 
                    case '1': teams_won[j]++;
                    case '0': teams_played[j]++;
                }
             }

        for(j=0;j<n;j++)
        {
            wp_sum =0;
            for(k=0;k<n;k++)
            {
                switch(teams[j][k])
                {
                    case '.': break; 
                    case '0': wp_sum += ((double)teams_won[k]-1)/(teams_played[k]-1);
                              break; 
                    case '1': wp_sum += ((double)teams_won[k])/(teams_played[k]-1);
                              break; 
                }
             }
             teams_owp[j] = wp_sum / teams_played[j]; 
        }    


        for(j=0;j<n;j++)
        {
            wp_sum =0;
            for(k=0;k<n;k++)
            {
                switch(teams[j][k])
                {
                    case '.': break; 
                    case '0':  
                    case '1': wp_sum += teams_owp[k];  
                              break; 
                }
             }
             teams_oowp[j] = wp_sum / teams_played[j]; 
        }    
                

        printf("Case #%d:\n",i+1);
        for(j=0;j<n;j++)
        {
            wp_sum = 0;
            wp_sum = ((double) teams_won[j])/teams_played[j];
//            printf("Win percent %f\n",wp_sum);
            wp_sum = wp_sum * 0.25;
            wp_sum += (0.5 * teams_owp[j]);
            wp_sum += (0.25 * teams_oowp[j]);
            printf("%6f\n",wp_sum);
        }
     }
            
    return 1;
}

        
