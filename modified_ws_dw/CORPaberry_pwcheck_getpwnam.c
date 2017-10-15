#include <pwd.h>
extern char *crypt();
char *pwcheck(userid, password)
char *userid;
char *password;
{
  int first_iteration;
  char *r;
  struct passwd *pwd;
  pwd = getpwnam(userid);
  if (!pwd)
  {
    r = "Userid not found";
  }
  else
    if (pwd->pw_passwd[0] == '*')
  {
    r = "Account disabled";
  }
  else
    if (strcmp(pwd->pw_passwd, crypt(password, pwd->pw_passwd)) != 0)
  {
    r = "Incorrect password";
  }
  else
  {
    r = "OK";
  }



  endpwent();
  return r;
}


