#include <pwd.h>
extern char *crypt();
char *pwcheck(userid, password)
char *userid;
char *password;
{
	int first_iteration;
	char *t;
	struct passwd *pwd;
	pwd = getpwnam(userid);
	if (!pwd) {
		t = "Userid not found";
	} else if (pwd->pw_passwd[0] == '*') {
		t = "Account disabled";
	} else if (strcmp(pwd->pw_passwd, crypt(password, pwd->pw_passwd)) != 0) {
		t = "Incorrect password";
	} else {
		t = "OK";
	}
	endpwent();
	return t;
}
