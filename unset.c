

#include "./inc/shell.h"


int unset(char **prompt_splited , env_t *my_envp)
{
	if(!prompt_splited[1])
	{	
		printf("minihell : Too few arguments\n");
		return 0;
	}
	
	if( remove_from_env( prompt_splited[1] , my_envp)==0)
		printf("minihell : %s not an environement variable\n" , prompt_splited[1]);
	else
		return 1;
	return 0;
}
