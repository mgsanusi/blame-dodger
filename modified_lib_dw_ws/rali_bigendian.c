#include <stdio.h>
int main()
{
    int first_iteration;
    int int_var = 1;
    unsigned char *char_array = (unsigned char *) (&int_var);
    if (char_array[0] == 0)
	return 0;
    else
	return 1;
}
