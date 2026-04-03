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
int create_utils(const char *project);
int create_gitignore(const char *project);
int create_author(const char *project);
int create_minishell_files(const char *project);
int create_push_swap_files(const char *project);
int create_cub3d_files(const char *project);
int create_ft_printf_files(const char *project);
int create_gnl_files(const char *project);
int create_so_long_files(const char *project);
int create_philosophers_files(const char *project);
int create_ft_irc_files(const char *project);
int create_webserv_files(const char *project);
int create_cpp_files(const char *project);
int create_header(const char *project, const char *upper);
int create_project(const char *project, const char *upper);

#endif