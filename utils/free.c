

#include "../inc/shell.h"


void free_list2(env_t *envp)
{
	if(!envp) return ;
	env_t *node = envp;
	while(node)
	{
		env_t *tmp = node;
		node = node->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

void free_mat2(char **mat)
{
	if(!(*mat)) return ;
	size_t		i;

	i = 0 ;
	while(mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
