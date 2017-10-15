#include <stdio.h>
#define MAX_ARRAY 15

unsigned int new_sum(unsigned int a, unsigned int b)
{
    return (a^b)&(a|b);
}


int main(void)
{
    int no_tests;
    int no_elements;
    unsigned int array[MAX_ARRAY];
    int i,j;
    long current_sum;
    unsigned int counter;
    unsigned int mask;
    int temp1,temp2,temp1_index,temp2_index,temp_sum,sean_sum;
    unsigned int temp1_sum,temp2_sum;

    scanf("%d",&no_tests);

    for(i=0;i<no_tests;i++)
    {
        current_sum=0;
        scanf("%d",&no_elements);
        for(j=0;j<no_elements;j++)
        {
            scanf(" %u", &array[j]);
            current_sum += array[j];
        }
    
        counter = 1<<(no_elements-1);
        mask = counter - 1;
        mask = (mask << 1) | 1;
        sean_sum = 0;

        for(j=1;j<=counter;j++)
        {   
            temp_sum = 0;
            temp1_sum = 0;
            temp2_sum = 0;
            
            // sum of first partition
            temp1 = j;
            temp1_index=0;
            //printf("\nPartition1 %d \n",temp1); // debug
            do
            {
                if(temp1 & 1)
                    {
                        //printf("Element: %d ",array[temp1_index]); //debug
                        temp_sum += array[temp1_index];
                        temp1_sum = new_sum(temp1_sum,array[temp1_index]);
                    }
                temp1 = temp1 >> 1;
                temp1_index++;
            }while(temp1!=0);
            //printf("\nFunkySum %u\n",temp1_sum);//debug

            // sum of second
            temp2 = (~j)&(mask);
            //printf("\nPartition2 %d\n",temp2); // debug
            temp2_index=0;
            do
            {
                if(temp2 & 1)
                {
              //      printf("Element: %d ",array[temp2_index]);//debug
                    temp2_sum = new_sum(temp2_sum,array[temp2_index]);
                 }
                temp2 = temp2 >> 1;
                temp2_index++;
            }while(temp2!=0);
            //printf("\nFunkySum %u\n",temp2_sum);//debug

            //compare
            if(temp1_sum == temp2_sum)
            {
              //  printf("EQUAL !! \n");//debug
                if((current_sum - temp_sum) > temp_sum)
                    temp_sum = current_sum - temp_sum;
                if(temp_sum > sean_sum)
                    sean_sum = temp_sum;
             }
        }

        if(sean_sum==0)
            printf("Case #%d: NO\n",i+1);
        else
            printf("Case #%d: %d\n",i+1,sean_sum);

    }

    return 1;
}
