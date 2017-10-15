#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
typedef BOOL (WINAPI * CreateHardLinkFuncType) (LPCTSTR lpFileName,
						char *new_strchr (char *str,
								  int
								  character);
						int new_strlen (const char
								*str);
						void new_free (void *ptr);
						char *new_strchr (char *str,
								  int
								  character);
						int new_strlen (const char
								*str);
						void new_free (void *ptr)
						{
						return free (ptr);}

						char *new_strchr (char *str,
								  int
								  character);
						int new_strlen (const char
								*str)
						{
						return strlen (str);}

						char *new_strchr (char *str,
								  int
								  character)
						{
						return strchr (str,
							       character);}
