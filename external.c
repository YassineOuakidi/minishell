

#include "./inc/shell.h"

char *find_path(char **pathnames , char *cmd)
{
	size_t i ;
	char *tmp ;
	char *path ; 

	i = 0;
	while(pathnames[i])
	{
		tmp = ft_strjoin(pathnames[i] , "/");
		path = ft_strjoin(tmp , cmd);
		if(access(path , X_OK)==0)
			return path;
		i++;
		free(tmp);
		free(path);
	}
	return NULL;
}

char *get_path_value(env_t *my_env)
{
	env_t *node = my_env;
	while(node)
	{
		if(ft_strcmp(node->key , "PATH")){

			return ft_strdup(node->value);
		}
		node = node->next;
	}
}


int execute_external(char *cmd , char **prompt_splited , env_t *my_env)
{
	pid_t pid;

	char *PATH_VALUE = get_path_value(my_env);

	char **pathnames = ft_split(PATH_VALUE , ':');

	char *path = find_path(pathnames , cmd);
		
	char **envp = list_to_char(my_env);
	
	pid = fork();
	
	if(pid==0)
		if(execve(path , prompt_splited , envp)==-1)
			return 0;
		else 
			return 1;
	else if(pid>0)
		waitpid(pid , NULL , 0);
}
