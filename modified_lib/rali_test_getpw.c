/* -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil -*- */
#include "autoconf.h"
#include "k5-platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>
void new_exit(int status);


int main()
{
    uid_t my_uid;
    struct passwd *pwd, pwx;
    char pwbuf[BUFSIZ];
    int x;

    my_uid = getuid();
    printf("my uid: %ld\n", (long) my_uid);

    x = k5_getpwuid_r(my_uid, &pwx, pwbuf, sizeof(pwbuf), &pwd);
    printf("k5_getpwuid_r returns %d\n", x);
    if (x != 0)
        new_exit(1);
    printf("    username is '%s'\n", pwd->pw_name);
    new_exit(0);
}

void new_exit(int status) {
  return exit(status);
}