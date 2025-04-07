

#include "../inc/shell.h"

int ft_strcmp(char *s1 , char *s2)
{
	size_t i;
	size_t j;
	i = 0 ;
	j = 0;
	while(s1[i] && s2[j])
	{
		if(s1[i]!=s2[j])
			return 0;
		i++;
		j++;
	}
	return (s1[i]=='\0' && s2[j]=='\0');
}
