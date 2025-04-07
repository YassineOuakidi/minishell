

#include "../inc/shell.h"


size_t get_matrix_height(char **mat)
{
	size_t ans ;
	ans = 0;
	while(mat[ans])
		ans++;
	return ans;
}

char **ft_remove_endl(char **prompt_splited)
{
	size_t height;
	size_t i;

	height = get_matrix_height(prompt_splited);

	char **ans = malloc(sizeof(char *) * height + 1);

	i = 0;
	while(i<height-1){
		ans[i] = ft_strdup(prompt_splited[i]);
		i++;
	}
	
	ans[height-1] = malloc(ft_strlen(prompt_splited[height-1]));
	
	i = 0;
	while(prompt_splited[height-1][i])
	{
		if(prompt_splited[height-1][i]!='\n')
			ans[height-1][i] = prompt_splited[height-1][i];
		else break;
		i++;
	}
	ans[height-1][i] = '\0';

	ans[height] = NULL;
	return ans;
}
