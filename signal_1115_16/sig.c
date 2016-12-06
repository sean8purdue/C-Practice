/*
 * This is an example of how signals and signal handlers work. The key
 * function in this example is signal(). This will help you implement
 * the "&" operator.
 *
 * Normally, when the user types in a command, your shell should fork()
 * and execvp() the appropriate programs, then waitpid() for them to end
 * before waiting for the next command. But, if the command has a "&" at
 * the end, it should present the prompt and wait for the next command
 * right away. In that case, there is the problem that the parent
 * process should call wait() or waitpid() as soon as a child finishes,
 * in order to "clean up" the memory the child held. This is solved with
 * signals.
 *
 * When calling signal(), a process  is instructed that it should
 * execute the appropriate signal handler whenever a specific signal is
 * delivered to it. Signals are delivered to note various events, like
 * "interrupt from keyboard" (SIGINT) or "child ended" (SIGCHLD). For
 * more information, type "man 3 signal" or "man 7 signal".
 *
 * The idea is that whenever a child finishes, SIGCHLD is
 * "automatically" delivered to the parent process. So, the parent can
 * call wait() or waitpid() as soon as it receives SIGCHLD!
 *
 * In the following example, note the header of signalHandler(). The
 * header of any signal handler should be like that (any signal handler
 * should have an int as a parameter and return void).
 *
 * The example is pretty simple. A signal handler is set for SIGALRM,
 * SIGUSR1 and SIGCHLD (type "man 7 signal" for details). It sends
 * SIGALRM to the parent and then finishes (again, sending SIGCHLD).
 *
 * You can try sending signals to the parent process yourself! Just
 * try typing:
 *
 * kill -USR1 <parent_pid>
 * */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signal)
{
	printf("Cought signal %d!\n",signal);
	if (signal==SIGCHLD) {
		printf("Child ended\n");
		wait(NULL);
	}
}

int main()
{
	signal(SIGALRM,signalHandler);
	signal(SIGUSR1,signalHandler);
	signal(SIGCHLD,signalHandler);

	if (!fork()) {
		printf("Child running...\n");
		sleep(2);
		printf("Child sending SIGALRM...\n");
		kill(getppid(),SIGALRM); /*send alarm signal to parent*/
		sleep(5);
		printf("Child exitting...\n");
		return 0;
	}
	printf("Parent running, PID=%d. Press ENTER to exit.\n",getpid());
	getchar();
	printf("Parent exitting...\n");
	return 0;
}
