void *new_memcpy(void *destination, const void *source, int num);
void *new_memcpy(void *destination, const void *source, int num)
{
	return memcpy(destination, source, num);
}
