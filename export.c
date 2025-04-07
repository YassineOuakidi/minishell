

#include "./inc/shell.h"

void free_mat(char **list)
{
	size_t i ;
	i = 0 ; 
	while(list[i])
		free(list[i++]);
	free(list);
}

bool check_char(char c , int j)
{
	return (j>0 && c>='0' && c<='9') || (c>='a' && c<='z') || (c=='_') || (c>='A' && c<='Z');
}

bool is_valid(char *key)
{
	size_t 		i;

	i = 0;
	while(key[i])
	{
		if(!check_char(key[i] , i)) return 0;
		i++;
	}
	return true;
}


int export(char **prompt_splited , env_t *my_envp)
{
	size_t	i ;
	
	char **tmp ;
	i = 1;
	while(prompt_splited[i])
	{
		tmp = ft_split(prompt_splited[i] , '=');
		if(is_valid(tmp[0])) add_to_env(my_envp , tmp[0] , tmp[1] ? tmp[1] : "");
		else 
		{
			printf("minihell : Invalid Identifier\n");
			return 0;
		}
		free_mat(tmp);
		i++;
	}
	return 1;
}
