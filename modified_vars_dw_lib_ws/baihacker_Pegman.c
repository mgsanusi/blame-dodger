#include <pe>
void *new_memset(void *ptr, int value, int num);
void *new_memset(void *ptr, int value, int num)
{
	return memset(ptr, value, num);
}
