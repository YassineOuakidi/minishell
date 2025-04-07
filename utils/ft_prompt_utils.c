

#include "../inc/shell.h"



int prompt_has_multi(char *prompt)
{
	size_t		i;

	i = 0;
	while(prompt[i])
		if(prompt[i++]==';')
			return 1;
	return 0;
}


int prompt_has_pipes(char *prompt)
{
	size_t		i;

	i = 0;
	while(prompt[i])
		if(prompt[i++]=='|')
			return 1;
	return 0;
}
