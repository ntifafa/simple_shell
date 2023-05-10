#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void _puts(char *s);
char *_strcat_sp(char *destin, char *source);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
char *_strcpy(char *destin, char *source);
unsigned int _strlen(char *s);
void _shell_prompt(void);
void _EOF_case(char *LinePtr);
char *_get_home_dir(char **env);
char *_get_oldpwd(char **env);
void _exit_shell(char **LinePtr_copy);
void _invok_child(char **LinePtr_copy, char *name, char **env, size_t prompt_i);
int _strncmp(const char *s1, const char *s2, size_t n);
int _change_dir_func(char *path, char **env);
void _execmd(char **LinePtr_copy, char *name, char **env, size_t prompt_i);
void _envir_print(char **env);
char **_get_pathtok(char **env);
void _error_msg(char *name, size_t prompt_i, char **LinePtr_copy);
char **_parse_token(char *LinePtr, char *delimit);
void _free_argv(char **LinePtr_copy);
void _free_before_exit(char **LinePtr_copy);
void _handle(int signals);
int main(int ac, char **av, char **env);
int count_tokens(char *LinePtr, char *delim);


#endif
