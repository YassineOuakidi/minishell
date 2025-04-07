#include "../inc/shell.h"

size_t get_height(env_t *my_envp)
{
	size_t i = 0;
	env_t *node = my_envp;
	while(node)
	{
		node = node->next;
		i++;
	}
	return i;
}

char **list_to_char(env_t *my_envp)
{
	size_t height;
	char **ans;
	env_t *node = my_envp;
	
	height = get_height(my_envp);
	
	ans = malloc(sizeof(char *) * height + 1);
	
	height = 0;
	while(node)
	{
		char *line = ft_strjoin(node->key , "=");
		line = ft_strjoin(line , node->value);
		ans[height] = ft_strdup(line);
		height++;
		node = node->next;
	}
	ans[height] = NULL;
	return ans;
}

void init_env(char **envp , env_t **env)
{
	size_t i = 1;
    	env_t *node, *new_node;

    	if (!envp || !envp[0]) 
    	{
       		*env = NULL;
        	return;
    	}
	char **first = ft_split(envp[0] , '=');
    	*env = malloc(sizeof(env_t));
    	if (!*env)
        	return;
    	(*env)->key = ft_strdup(first[0]);
	(*env)->value = ft_strdup(first[1]);
    	(*env)->next = NULL;
    	node = *env;
   	
	while (envp[i])
    	{
		char **tmp = ft_split(envp[i] , '=');
        	new_node = malloc(sizeof(env_t));
        	if (!new_node)
           		return;
        	new_node->key = ft_strdup(tmp[0]);
		new_node->value = ft_strdup(tmp[1]);
        	new_node->next = NULL;

        	node->next = new_node;  
        	node = new_node;
        	i++;
		free(tmp);
    	}	
}

void print_list(env_t *my_envp)
{
	env_t *node = my_envp;
	while(node)
	{
		printf("%s , %s\n" , node->key , node->value); 
		node = node->next;
	}
}

void add_to_env(env_t *my_envp , char *key , char *value)
{
	env_t *node = my_envp;

	while(node->next)
	{
		if(ft_strcmp(node->key , key))
		{
			free(node->value);
			if(value) node->value = ft_strdup(value);
			return ;
		}
		node = node->next;
	}
	env_t *new_node = malloc(sizeof(env_t));
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	node->next = new_node;
	return ;
}

char *get_value(char *key , env_t *my_envp)
{
	env_t *node = my_envp;
	while(node)
	{
		if(ft_strcmp(key , node->key))
		{
			return node->value;
		}
		node = node->next;
	}
	return NULL;
}

int remove_from_env(char *key , env_t *my_envp)
{
	env_t *node = my_envp;
	while(node->next)
	{
		if(ft_strcmp(key , node->next->key))
		{
			env_t *tmp = node->next;
			node->next = node->next->next;
			free(tmp->key);
			free(tmp->value);
			return 1;
		}
		node = node->next;
	}
	return 0;
}
