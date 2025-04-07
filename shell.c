#include "./inc/shell.h"

env_t *my_envp;
char *prompt ;
char **prompt_splited;

int LAST_EXIT = 0; 

int is_builtin(char *cmd)
{
	if(ft_strcmp(cmd , "cd") || ft_strcmp(cmd , "export") || ft_strcmp(cmd , "unset") || ft_strcmp(cmd , "pwd") || ft_strcmp(cmd , "echo") || ft_strcmp(cmd , "env"))
		return 1;
	return 0;
}

int execute_prompt(char *prompt , env_t *my_envp)
{
	if(prompt_has_multi(prompt)==1)
		return exec_multi(prompt , my_envp);

	else if(prompt_has_pipes(prompt)==1)
		return exec_pipes(prompt , my_envp);

	char **tmp_prompt_splited = ft_split(prompt , ' ');
	char **prompt_splited = ft_remove_endl(tmp_prompt_splited);
	char *cmd = ft_strdup(prompt_splited[0]);

	if(is_builtin(cmd))
	{
		return execute_builtin(cmd , prompt , prompt_splited , my_envp);
	} else
	{
		return execute_external(cmd , prompt_splited , my_envp);	
	}
}

void handle_sigint(int sig)
{
	free_list2(my_envp);
	free_mat2(prompt_splited);
	free(prompt);
	exit(1);
}

int main(int argc , char **argv , char **envp)
{
	signal(SIGINT , handle_sigint);
	init_env(envp , &my_envp);
	
	while(true)
	{
		write(1 , "\033[36muser@minihell$> \033[0m" , 25);
		prompt = get_next_line(STDIN_FILENO);
		int return_code = execute_prompt(prompt , my_envp);
		LAST_EXIT = return_code;
		free(prompt);	
	}
}
