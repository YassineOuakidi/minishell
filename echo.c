
#include "./inc/shell.h"


char *make_str(char c)
{
	char *s = malloc(2 * sizeof(char ));
	s[0] = c;
	s[1] = '\0';
	return s;
}

int is_var_name_valid(char c , int pos)
{
	return ((c>='0' && c<='9' && pos!=0) || (c>='a' && c<='z') || (c>='A' && c<='Z') || c=='_') ? 1 : 0;
}

char *get_new_string(char *s , env_t *my_envp)
{
	size_t		i;
	size_t		ans;
	size_t		j;
	i = 0;
	ans = 0;
	
	char *prompt  = ft_strdup("");
	while(s[i])
	{
		if(s[i] =='$'){
			j = i+1;
			while(s[j] && is_var_name_valid(s[j] , j-i-1)==1)
				j++;
			char *key = malloc((j-i-1) * sizeof(char) + 1);
			ft_memcpy(key , s + i + 1 , j-i-1);
			key[j-i-1] = '\0';
			char *value = get_value(key , my_envp);
			if(!value)
			{
				prompt = ft_strjoin(prompt , "$");
				prompt = ft_strjoin(prompt , key);
			}
			else 
			{
				prompt = ft_strjoin(prompt , value);
			}
			free(key);
			i = j-1;
		} 
		else 
		{
			prompt = ft_strjoin(prompt , make_str(s[i]));
		}
		i++;
	}
	return prompt;
}
	

char **expand_vars(char **prompt_splited , env_t *my_envp)
{
	size_t 		len;
	size_t		i;
	size_t		j;
	int 	quotations ;
	char **final;
	
	len = get_matrix_height(prompt_splited);
	final = malloc((len + 1) * sizeof(char *));
	
	if(ft_strcmp(prompt_splited[1] , "-n"))
		i = 2;
	else 
		i = 1;
	j = 0;
	while(prompt_splited[i])
	{
		final[j] = get_new_string (prompt_splited[i] , my_envp);
		i++;
		j++;
	}
	final[j] = NULL;
	return final;
}


int echo(char **prompt_splited , env_t *my_envp)
{
	
	char **prompt_expanded = expand_vars(prompt_splited , my_envp);
	
	char found = 'c';

	size_t		i;
	size_t		j;

	i=0;
	while(prompt_expanded[i])
	{
		j = 0;
		while(prompt_expanded[i][j])
		{
			if(prompt_expanded[i][j]=='\'')
				if(found=='\'')
					found  = 'c';
				else if(found=='c')
					found = '\'';
				else 
					printf("%c" , prompt_expanded[i][j]);
			else if(prompt_expanded[i][j]=='"')
				if(found=='"')
					found = 'c';
				else if(found=='c')
					found = '"';
				else 
					printf("%c" , prompt_expanded[i][j]);
			else 
				printf("%c" , prompt_expanded[i][j]);
			j++;
		}
		printf(" ");
		i++;
	}
	if(!ft_strcmp( prompt_splited[1] , "-n" ))printf("\n");

}
