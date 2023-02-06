#include "_pipex.h"

int main()
{
	int fd1[2]; // child --> parent
	int	fd2[2];	// parent --> child
	int pid;

	if (pipe(fd1) < 0 || pipe(fd2) < 0)
		exit(1);
	if ((pid = fork()) < 0)
		exit(1);
	if (pid == 0)
	{
		int x;
		close(fd2[1]);
		close(fd1[0]);
		if (read(fd2[0], &x, sizeof(int)) <= 0)
			exit(1);
		printf("recieved var from parent: %d\n", x);
		x *= 4;
		if (write(fd1[1], &x, sizeof(int)) < 0)
			return (1);
		printf("multiplied and sent back to sent to parent: %d\n", x);
		close(fd2[0]);
		close(fd1[1]);
	}
	if (pid > 0)
	{
		int y;

		close(fd2[0]);
		close(fd1[1]);
		y = 4;
		if (write(fd2[1], &y, sizeof(int)) < 0)
			exit(1);
		printf("first worte var: %d\n", y);
		if (read(fd1[0], &y, sizeof(int)) <= 0)
			exit(1);
		printf("received from the child after mutilplied: %d\n", y);
		close(fd2[1]);
		close(fd1[0]);
	}
	return (0);
}

// TWO PROCESSES COMMUNICATION USING TWO PIPES