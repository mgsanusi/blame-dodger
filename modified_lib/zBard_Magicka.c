#include <stdio.h>

#define COMBINE 36
#define DESTROY 28
#define STRING_SIZE 100
#define MAX_TEST 100

int reaction_array[26][26];
int destruction_array[26][26];
int element_seen[26];

int main(void)
{
    int i,j,k,m,flag;
    int tot_test_cases, num_combine, num_destroy,num_string;
    char combine_str[4], destroy_str[3], input_str[100],output_str[100];
    int output_len=0;
    int new_element, previous_element;
    scanf("%d",&tot_test_cases);

    for(i=0;i<tot_test_cases;i++)
    {
        //clear
        output_len=0;
        for(j=0;j<26;j++)
        {
            element_seen[j]=0;
            for(k=0;k<26;k++)
            {
                reaction_array[j][k]=-1;
                destruction_array[j][k] =0;
            }
        }


        scanf("%d",&num_combine);
        for(;num_combine>0;num_combine--)
            {
                scanf(" %s",combine_str);
                reaction_array[combine_str[0]-'A'][combine_str[1]-'A'] = combine_str[2]-'A';
                reaction_array[combine_str[1]-'A'][combine_str[0]-'A'] = combine_str[2]-'A';
            //    printf("<%s>",combine_str);//debug
            }


        scanf("%d",&num_destroy);
        for(;num_destroy>0;num_destroy--)
            {
                scanf(" %s",destroy_str);
                destruction_array[destroy_str[0]-'A'][destroy_str[1]-'A'] = 1;
                destruction_array[destroy_str[1]-'A'][destroy_str[0]-'A'] = 1;
          //      printf("<%s>",destroy_str);//debug
            }
        
        scanf("%d",&num_string);
        scanf(" %s",input_str);
        //gets(input_str);
        //printf("<%s>",input_str);//debug
        
        //printf("Next !!\n");//debug
        for(j=0;j<num_string;j++)
        {
            new_element = input_str[j]-'A';
            do
            {
                flag = 0;
                if(output_len!=0)
                {
                    //check combine
                    previous_element = output_str[output_len-1] - 'A';
                    if(reaction_array[new_element][previous_element] != -1)
                    {
                        //printf("Combine\n");//debug
                        flag=1;
                        new_element = reaction_array[new_element][previous_element];
                        output_len--;
                        element_seen[previous_element]--;
                        continue;
                    }

                    // check destroy
                    for(k=0;k<26;k++)
                    {
                        if(destruction_array[new_element][k] && element_seen[k])
                        { 
                            //printf("Destroy\n");//debug
                            flag=2;
                            for(m=0;m<26;m++)
                            {
                                element_seen[m]=0;
                                output_len=0;
                            }
                            break;
                        }
                    }
                }
            } while ((flag!=0) && (flag!=2));

            if(flag!=2)
            {
                //printf("adding %c",new_element+'A'); // debug
                output_str[output_len++] = new_element+'A';
                element_seen[new_element]++;
            }
        }

        printf("Case #%d: [",i+1);
        for(m=0;m<output_len-1;m++)
            printf("%c, ",output_str[m]);
        if(output_len!=0)
            printf("%c",output_str[output_len-1]);
        printf("]\n");
     }

     return 1;
}

        


