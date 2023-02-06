#include "_pipex.h"

int main()
{
	int fd[2];
	int pid;

	if (pipe(fd) < 0)
	{	
		perror("Error: ");
		return (1);
	}
	if ((pid = fork()) < 0)
	{
		perror("Error: ");
		return (1);
	}
	if (pid == 0)
	{
		close(fd[0]);
		int x;
		if(write(fd[1], "Hello world", 11) < 0)
		{
			perror("Error: ");
			return (1);
		}
		close(fd[1]);
	}
	else
	{

		close(fd[1]);
		char str[13];
		
		if(read(fd[0], str, 13) < 0)
		{
			perror("Error: ");
			return (1);
		}
		close(fd[0]);
		printf("%s\n", str);
	}
	return (0);
}

// THIS IS HOW PROCESSES COMMUNICATE
