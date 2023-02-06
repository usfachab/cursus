#include "_pipex.h"

int main()
{
	int fd[2];
	int pid;
	int	arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int start, end;
	int arrSize = sizeof(arr) / sizeof(int);
	int sum = 0;
	if (pipe(fd) < 0)
		return (1);
	if ((pid = fork()) < 0)
		return (1);
	if (pid == 0)
	{
		start = 0;
		end = arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	for (int i = start; i < end; i++)
		sum += arr[i];
	if (pid == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(int)) < 0)
				return (1);
		close(fd[1]);
	}
	else
	{
		int sumFromChild;

		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(int)) < 0)
			return (1);
		close(fd[0]);
		printf("%d\n", sumFromChild + sum);
	}
	return (0);
}

// TWO PROCESSES COMMUNICATION USING PIPE