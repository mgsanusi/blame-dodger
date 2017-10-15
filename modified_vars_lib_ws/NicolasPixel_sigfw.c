#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
int pid = 0;
void handle_sigint(int signum)
{
	if (pid)
		kill(pid, SIGINT);
}

int Main(int argc, char *argv[])
{
	struct sigaction new_action;
	int status = -1;
	new_action.sa_handler = handle_sigint;
	sigemptyset(&new_action.sa_mask);
	new_action.sa_flags = 0;
	sigaction(SIGINT, &new_action, (void *)0);
	pid = fork();
	if (pid) {
		wait(&status);
		return WEXITSTATUS(status);
	} else {
		status = execvp(argv[1], &argv[1]);
		perror("exec");
		return status;
	}
}
