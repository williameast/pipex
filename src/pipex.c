/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weast <weast@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 10:53:12 by weast             #+#    #+#             */
/*   Updated: 2025/03/05 18:49:14 by weast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int redirect_with_dup()
{
	int fd;

	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
	if (fd < 0)
		error_exit("dont work");
	dup2(fd, STDOUT_FILENO);
	close(fd);
	ft_printf("here is some text to redirect\n");
	return (EXIT_SUCCESS);
}

int test_permission(char *path)
{
	ft_printf("PERMISSIONS: \n\n");
	ft_printf("testing if we can access %s\n", path);
	if (access(path, F_OK) == 0)
		ft_printf("File exists!\n");
	else
		error_exit("File does not exist, exiting.\n");
	if (access(path, R_OK) == 0)
		ft_printf("Read permission confirmed. \n");
	if (access(path, W_OK) == 0)
		ft_printf("Write permission confirmed. \n");
	if (access(path, X_OK) == 0)
		ft_printf("Executable permission confirmed \n");
	return (EXIT_SUCCESS);
}

int run_ls()
{
	char *args[3];

	args[0] = "ls";
	args[1] = "-l";
	args[2] = NULL;
	execve("/bin/ls", args, NULL);
	ft_printf("you will never see this!");

	return (EXIT_SUCCESS);
}

int fork_my_program()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		error_exit("PID is negative. couldn't fork.");
	if (pid == 0)
		ft_printf("im a baby! call me baby. (pid: %d)\n", getpid());
	else
		ft_printf("Im big daddy. (pid: %d)\n", getpid());
	return (EXIT_SUCCESS);
}

int piping_hot()
{
	int fd[2];
	pid_t pid;
	char buffer[27];

	if (pipe(fd) == -1)
		error_exit("pipe didnt work.");
	pid = fork();
	if (pid == -1)
		error_exit("fork didnt work.");
	if (pid == 0)
	{
		close(fd[0]); // close the read end of the pipe
		write(fd[1], "child says hello to parent", 27);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(fd[1]); // close the write end of the pipe
		read(fd[0], buffer, 27);
		close(fd[0]); // close the read end of the pipe
		ft_printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	}
}


int delete_file(char *file)
{
	if (unlink(file) == 0)
		ft_printf("%s successfully deleted.\n", file);
	else
		error_exit("Error deleting \n");
	return (EXIT_SUCCESS);
}

int execution(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		error_exit("fork didnt work.");

	else if (pid == 0)
	{
		ft_printf("I AM A BABAY.\n");
		sleep(6);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_printf("I am THE DADDY.\n");
		wait(NULL);
		ft_printf("Child process terminated after a 6s delay.\n");
	}
	return (EXIT_SUCCESS);
}

int main(void)
{
	/* redirect_with_dup(); */
	/* run_ls(); */
	/* fork_my_program(); */
	/* piping_hot(); */
	/* test_permission("example.txt"); */
	/* delete_file("example.txt"); */
	/* test_permission("example.txt"); */
	execution();
}
