int _execute(char **argv)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == -1)
		perror("Error:");
	/* The child process*/
	else if (child_pid == 0)
	{
		execve(*argv, argv, NULL);
	}
	else
	{
		wait(&status);
	}
	return (0);
}
