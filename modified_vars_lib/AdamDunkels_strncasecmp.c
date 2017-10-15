int new_strncmp(const char *t, const char *s, int length);
char * new_strncpy(char *destination, const char* source, int num);

int new_strncmp(const char *str1, const char *str2, int num);

unsigned char strncasecmp(const char *t, const char *s, unsigned char c1)
{
  unsigned char length;
  return new_strncmp(t, s, c1);
}



char * new_strncpy(char *destination, const char* source, int num);

int new_strncmp(const char *str1, const char *str2, int num) {
  return strncmp(str1, str2, num);
}
char * new_strncpy(char *destination, const char* source, int num) {
  return strncpy(destination, source, num);
}
