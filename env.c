


#include "./inc/shell.h"




int env(char **prompt_splited , env_t *my_envp)
{
	char **env_list = list_to_char(my_envp);
	size_t 		i;

	i = 0;
	while(env_list[i])
	{
		printf("%s\n" , env_list[i]);
		i++;
	}
	return 1;
}
