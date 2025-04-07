#include "./inc/shell.h"


pid_t execute_pipe(char *prompt, int *fds, int *prev_fds, int i, int num_cmds, env_t *my_envp)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (i > 0)
		{
			dup2(prev_fds[0], STDIN_FILENO);
			close(prev_fds[0]);
			close(prev_fds[1]);
		}
		if (i < num_cmds - 1)
		{
			dup2(fds[1], STDOUT_FILENO);
			close(fds[0]);
			close(fds[1]);
		}
		exit(execute_prompt(prompt, my_envp));
	}
	return (pid);
}

int exec_pipes(char *prompt, env_t *my_envp)
{
	char **prompts;
	int p_fds[2] = {-1, -1}, c_fds[2], i = 0, n = 0, st = 1, last_st = 1;
	pid_t pid, last_pid = -1;

	prompts = ft_split(prompt, '|');
	if (!prompts) return (perror("split"), 1);
	while (prompts[n]) n++;
	if (n == 0) return (free_mat2(prompts), 0);
	if (n == 1) {
		last_st = execute_prompt(prompts[0], my_envp);
		free_mat2(prompts); return last_st;
	}
	for (i = 0; i < n; i++) {
		if (i < n - 1 && pipe(c_fds) == -1) { perror("pipe"); break; }
		pid = execute_pipe(prompts[i], c_fds, p_fds, i, n, my_envp);
		if (pid < 0) { break; }
		if (i > 0) { close(p_fds[0]); close(p_fds[1]); }
		if (i < n - 1) { p_fds[0] = c_fds[0]; p_fds[1] = c_fds[1]; }
		last_pid = pid;
	}
	free_mat2(prompts);
	pid = 0;
	while ((pid = wait(&st)) > 0) {
		if (pid == last_pid) {
			 if (WIFEXITED(st)) last_st = WEXITSTATUS(st);
			 else if (WIFSIGNALED(st)) last_st = 128 + WTERMSIG(st);
		}
	}
	if (errno != ECHILD && errno != 0) perror("wait");
	return (last_st);
}

