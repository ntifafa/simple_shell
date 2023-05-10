#ifndef MAIN_H
#define MAIN_H

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
/* #include <crtdbg.h> */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void _puts(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
void _printf(const char *format, ...);
int _putchar(char c);

void execmd(char **argv);
char *find_path(char *argv0);
void _str_cpy_cat(char *fullpath, char *pathtok, char *argv0);
char *alloc_4_fullpath(char *pathtok, char *fullpath, char *argv0);
char **parse_string(char **argv, char *linePtr_copy, int counterT);
int count_tokens(char *linePtr, const char *delim);
pid_t waitpid(pid_t pid, int *status, int options);
void cdfunctionality(char **argv);
int exit_functionality(char **argv);
void free_memory(char **argv, char *linePtr, char *linePtr_copy);
char * dup_string(char *ustring, ssize_t num_read);
void free_before_exit(char **argv);
void free_argv(char **argv);
void _exit_if_eof(char *ustring);


#endif
