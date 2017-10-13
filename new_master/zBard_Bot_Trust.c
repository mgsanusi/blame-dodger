#include <stdio.h>

#define TEST_CASES 100
#define MAX_POINTS 100

char robot_id[MAX_POINTS];
int robot_pts[MAX_POINTS];


int main(void)
{
    int i=0,k=0;
    long j=0;
    long current_ans=0;
    int no_tests =0;
    int current_no_pts =0;
    int current_ptr =0;
    int robo_location, robb_location;
    /* take input */
    scanf("%d",&no_tests);
    for (i=0;i<no_tests;i++)
    {
        /* Clear */
        scanf("%d",&current_no_pts);
        for(j=0;j<current_no_pts;j++)
        {
            /*robot_id[j]="X";
            robot_pts[j]=0;*/
            scanf(" %c", &robot_id[j]);
            scanf(" %d", &robot_pts[j]);
        }
        
        
        current_ans=0;
        current_ptr=0;
        robo_location = 1;
        robb_location = 1;

        /*for(j=0;j<MAX_POINTS;j++)*/
        j = 0 ;
        while(1)
        {
            //printf("step %ld, currentptr %d >> O : %d B : %d\n",j,current_ptr,robo_location,robb_location);//debug
            if(current_ptr == current_no_pts)
                {
                    current_ans = j;/*Check ?*/
                    printf("Case #%d: %ld\n",i+1,current_ans);
                    break;
                }

            if(robot_id[current_ptr] == 'O')
            { 
                //printf("in O - %d pt-%d\n",robot_pts[current_ptr],current_ptr);//debug 
                if(robot_pts[current_ptr]<robo_location)
                    robo_location--;
                else if(robot_pts[current_ptr]>robo_location)
                    robo_location++;
                else if(robot_pts[current_ptr]==robo_location)
                    {
                        robot_pts[current_ptr] = 0; /*Assume never inversion */
                        current_ptr++;
                    }
                /* Deal with other robot */
                /*Can memoize this*/
                for(k=current_ptr;(robot_id[k] == 'O') && (k!=current_no_pts);k++);
                if(k!=current_no_pts)
                {
                    if(robot_pts[k]<robb_location)
                        robb_location--;
                    else if(robot_pts[k]>robb_location)
                        robb_location++;
                }
             }
             else
             {
                //printf("in B - %d pt-%d",robot_pts[current_ptr],current_ptr);//debug 
                if(robot_pts[current_ptr]<robb_location)
                    robb_location--;
                else if(robot_pts[current_ptr]>robb_location)
                    robb_location++;
                else if(robot_pts[current_ptr]==robb_location)
                    {
                        robot_pts[current_ptr] = 0; /*Assume never inversion */
                        current_ptr++;
                    }
                /* Deal with other robot */
                /*Can memoize this*/
                for(k=current_ptr;(robot_id[k] == 'B') && (k!=current_no_pts);k++);
                if(k!=current_no_pts)
                {
                    if(robot_pts[k]<robo_location)
                        robo_location--;
                    else if(robot_pts[k]>robo_location)
                        robo_location++;
                }
             }

             /* Increment step*/
             j++;
             //   printf("O : %d B : %d\n",robo_location,robb_location);//debug
        }
    }

    return 1;
}
