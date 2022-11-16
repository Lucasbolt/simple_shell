#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define END -2
#define EXIT -3
extern char **environ;

char **makenv(void);
int prompt(char **path);
int search(char *path);
int dirtest(char *dir, char *file, int errno);
int check(char *file1, char *file2);
char *mygetc(void);
int checkWord(char *command);
int startProcess( char **args, char **front);
int pathCheck(char **command, char **path, char **front);
char *modifier(char *string);
int delim_count(char *command);
char **string_splitter(char *command);
char **splitit(char *string, int words);
int freemem(char **arg, char **front);
char **epath(void);
void free_env(void);
char **fetch_env(const char *var);
int numberPath(char *path);
int pathProcess(char *dir, char **args, char **front);
int mexit(char *input);
#endif
