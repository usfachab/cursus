#include "_pipex.h"

void err_msg(char *str)
{
	perror(str);
	exit(1);
}


int main(int argc, char *argv[])
{
	int fd[2];
	int pid;

	(void)argc;
	if (pipe(fd) < 0)
		err_msg(NULL);
	if (access(argv[1], R_OK) < 0)
		err_msg(argv[1]);
	if ((fd[1] = open(argv[1], O_RDONLY)) < 0)
		err_msg(NULL);
	if ((pid = fork()) < 0)
		err_msg(NULL);
	if (pid == 0)
		execve(argv[2], argv, NULL);
	else
		wait(NULL);
	return (0);
}


// cas 1 --> absolute path /bin/ls --> check if its accessible and executable --> if not throw error
// cas 2 --> command -> go to $PATH split with ":" --> join the command with path --> check if accessible and executable