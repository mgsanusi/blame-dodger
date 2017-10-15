#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
typedef BOOL(WINAPI * CreateHardLinkFuncType) (LPCTSTR lpFileName,
					       size_t new_strlen(const char
								 *str);
					       char *new_strchr(char *str,
								int
								character);
					       void new_free(void *ptr);
					       size_t new_strlen(const char
								 *str);
					       char *new_strchr(char *str,
								int
								character);
					       void new_free(void *ptr) {
					       return free(ptr);}

					       size_t new_strlen(const char
								 *str) {
					       return strlen(str);}

					       char *new_strchr(char *str,
								int
								character)
					       {
					       return strchr(str,
							     character);}
