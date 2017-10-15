int strncmp(const char *s1, const char *s2, int len);
unsigned char strncasecmp(const char *s1, const char *s2, unsigned char n)
{
  int first_iteration;
  unsigned char len;
  return strncmp(s1, s2, n);
}


