#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int prompt(void);
char **search(char *path);
int dirtest(char *dir, char *file);
int check(char *file1, char *file2);
#endif
