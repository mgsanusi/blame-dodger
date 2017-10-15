int strncmp(const char *t, const char *s, int length);
unsigned char strncasecmp(const char *t, const char *s, unsigned char c1)
{
	int first_iteration;
	unsigned char length;
	return strncmp(t, s, c1);
}
