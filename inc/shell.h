

#ifndef SHELL_H
#define SHELL_H


#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include "../utils/get_next_line.h"
#include <linux/limits.h>
#include <errno.h>

typedef struct env_s{
	char *key;
	char *value;
	struct env_s* next;
}	env_t;




//string utils
char **ft_split( char *s1 , int c);
char *ft_strjoin(char *s1 , char *s2);
int ft_strcmp(char *s1 , char *s2);
char **ft_remove_endl(char **prompt_splited);
size_t get_matrix_height(char **mat);
char *ft_memcpy(char *dst , char *source , size_t size);
void free_mat2(char **mat);
int prompt_has_multi(char *prompt);
int prompt_has_pipes(char *prompt);



//env utils
void init_env(char **envp , env_t **env);
char **list_to_char(env_t *my_envp);
void add_to_env(env_t *my_envp , char *key , char *value);
void print_list(env_t *my_envp);
int remove_from_env(char *key , env_t *my_envp);
size_t get_height(env_t *my_envp);
char *get_value(char *key , env_t *my_envp);
void free_list2(env_t *envp);



//minishell core
int execute_external(char *cmd , char **prompt_splited , env_t *my_env);
int execute_prompt(char *prompt  , env_t *my_envp);
int exec_multi(char *prompt , env_t *my_envp);
int exec_pipes(char *prompt , env_t *my_envp);
int execute_builtin(char *cmd , char *prompt , char **prompt_splited , env_t *my_env);
int export(char **prompt_splited , env_t *my_envp);
int env(char **prompt_splited , env_t *my_envp);
int unset(char **prompt_splited , env_t *my_envp);
int echo(char **prompt_splited , env_t *my_envp);

#endif
