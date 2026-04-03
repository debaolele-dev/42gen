#ifndef FORTYTWO_GEN_H
# define FORTYTWO_GEN_H

// Header for 42GEN Project Starter Generator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

// Utility functions
void to_upper(char *str);
int is_valid_project_name(const char *name);
void cleanup(const char *project);

// Generator functions
int create_dirs(const char *project);
int create_makefile(const char *project);
int create_main(const char *project);
int create_header(const char *project, const char *upper);
int create_project(const char *project, const char *upper);

#endif