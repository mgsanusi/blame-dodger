#include <config.h>
#include <stddef.h>
#include <arpa/inet.h>
char *new_strchr(char *str, int character);
void *new_memcpy(void *destination, const void *source, int num);
char *new_strchr(char *str, int character);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}

char *new_strchr(char *str, int character)
{
	return strchr(str, character);
}
