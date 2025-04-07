

#include "./inc/shell.h"

int exec_multi(char *prompt , env_t *envp)
{
	size_t		i;
	
	char **prompts = ft_split(prompt , ';');
	
	i = 0;
	while(prompts[i])
	{
		if(execute_prompt(prompts[i] , envp)==0)
			return 0;
		i++;
	}
	return 1;
}
