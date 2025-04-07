

#include "./inc/shell.h"



int execute_builtin(char *cmd , char *prompt , char **prompt_splited , env_t *my_envp)
{
	if(ft_strcmp(cmd , "cd"))
		if(prompt_splited[1])
			return 1+chdir(prompt_splited[1]);
		else 
			return 1 + chdir(NULL);
	else if(ft_strcmp(cmd , "pwd"))
	{
		char *pwd = malloc(1024 * sizeof(char));
		getcwd(pwd , 1024);
		printf("%s\n" , pwd);
		free(pwd);
	}
	else if(ft_strcmp(cmd , "export"))
		return export(prompt_splited , my_envp);
	else if(ft_strcmp(cmd , "env"))
		return env(prompt_splited , my_envp);
	else if(ft_strcmp(cmd , "unset"))
		return unset(prompt_splited , my_envp);
	else if(ft_strcmp(cmd , "echo"))
		return echo(prompt_splited , my_envp);
}

