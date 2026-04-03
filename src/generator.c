#include <42gen.h>

int create_dirs(const char *project) {
    char path[512];

    // Create project directory
    if (mkdir(project, 0755) != 0) {
        perror("mkdir project");
        return 0;
    }

    // Create src/
    snprintf(path, sizeof(path), "%s/src", project);
    if (mkdir(path, 0755) != 0) {
        perror("mkdir src");
        return 0;
    }

    // Create include/
    snprintf(path, sizeof(path), "%s/include", project);
    if (mkdir(path, 0755) != 0) {
        perror("mkdir include");
        return 0;
    }

    return 1;
}

int create_makefile(const char *project) {
    char path[512];
    snprintf(path, sizeof(path), "%s/Makefile", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen Makefile");
        return 0;
    }
    fprintf(f, "NAME = %s\n\n", project);
    fprintf(f, "CC = gcc\n");
    fprintf(f, "CFLAGS = -Wall -Wextra -Werror -Iinclude\n\n");
    fprintf(f, "SRC_DIR = src\n");
    fprintf(f, "INC_DIR = include\n\n");

    // Check if it's minishell project
    if (strstr(project, "minishell") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/parser.c $(SRC_DIR)/executor.c $(SRC_DIR)/builtins.c\n");
    } else {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c\n");
    }

    fprintf(f, "OBJ = $(SRC:.c=.o)\n\n");
    fprintf(f, "all: $(NAME)\n\n");
    fprintf(f, "$(NAME): $(OBJ)\n");
    fprintf(f, "\t$(CC) $(CFLAGS) -o $@ $^ \n\n");
    fprintf(f, "clean:\n");
    fprintf(f, "\trm -f $(OBJ)\n\n");
    fprintf(f, "fclean: clean\n");
    fprintf(f, "\trm -f $(NAME)\n\n");
    fprintf(f, "re: fclean all\n\n");
    fprintf(f, ".PHONY: all clean fclean re\n");
    fclose(f);
    return 1;
}

int create_main(const char *project) {
    char path[512];
    snprintf(path, sizeof(path), "%s/src/main.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen main.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "int main(int argc, char *argv[]) {\n");
    fprintf(f, "    // TODO: implement %s\n", project);
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
    fclose(f);
    return 1;
}

int create_utils(const char *project) {
    char path[512];
    snprintf(path, sizeof(path), "%s/src/utils.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen utils.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n", project);
    fprintf(f, "#include <unistd.h>\n\n");
    fprintf(f, "// Utility functions for %s\n\n", project);
    fprintf(f, "void ft_putstr(char *str) {\n");
    fprintf(f, "    while (*str) {\n");
    fprintf(f, "        write(1, str++, 1);\n");
    fprintf(f, "    }\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void ft_putendl(char *str) {\n");
    fprintf(f, "    ft_putstr(str);\n");
    fprintf(f, "    write(1, \"\\n\", 1);\n");
    fprintf(f, "}\n\n");
    fprintf(f, "int ft_strlen(char *str) {\n");
    fprintf(f, "    int len = 0;\n");
    fprintf(f, "    while (str[len])\n");
    fprintf(f, "        len++;\n");
    fprintf(f, "    return len;\n");
    fprintf(f, "}\n");
    fclose(f);
    return 1;
}

int create_gitignore(const char *project) {
    char path[512];
    snprintf(path, sizeof(path), "%s/.gitignore", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen .gitignore");
        return 0;
    }
    fprintf(f, "# Binaries\n");
    fprintf(f, "%s\n", project);
    fprintf(f, "*.o\n\n");
    fprintf(f, "# Temporary files\n");
    fprintf(f, "*.tmp\n");
    fprintf(f, "*.swp\n");
    fprintf(f, "*.swo\n\n");
    fprintf(f, "# OS generated files\n");
    fprintf(f, ".DS_Store\n");
    fprintf(f, ".DS_Store?\n");
    fprintf(f, "._*\n");
    fprintf(f, ".Spotlight-V100\n");
    fprintf(f, ".Trashes\n");
    fprintf(f, "ehthumbs.db\n");
    fprintf(f, "Thumbs.db\n");
    fclose(f);
    return 1;
}

int create_author(const char *project) {
    char path[512];
    snprintf(path, sizeof(path), "%s/author", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen author");
        return 0;
    }
    // You can customize this or make it configurable
    fprintf(f, "your_login\n");
    fclose(f);
    return 1;
}

int create_minishell_files(const char *project) {
    // Create parser.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/parser.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen parser.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Parser functions for %s\n\n", project);
    fprintf(f, "t_cmd *parse_command(char *input) {\n");
    fprintf(f, "    // TODO: Implement command parsing\n");
    fprintf(f, "    return NULL;\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create executor.c
    snprintf(path, sizeof(path), "%s/src/executor.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen executor.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Executor functions for %s\n\n", project);
    fprintf(f, "int execute_command(t_cmd *cmd) {\n");
    fprintf(f, "    // TODO: Implement command execution\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create builtins.c
    snprintf(path, sizeof(path), "%s/src/builtins.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen builtins.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Built-in commands for %s\n\n", project);
    fprintf(f, "int builtin_echo(char **args) {\n");
    fprintf(f, "    // TODO: Implement echo builtin\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "int builtin_cd(char **args) {\n");
    fprintf(f, "    // TODO: Implement cd builtin\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_readme(const char *project) {
    char path[512];
    snprintf(path, sizeof(path), "%s/README.md", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen README.md");
        return 0;
    }
    fprintf(f, "# %s\n\n", project);
    fprintf(f, "A 42 school project implementation.\n\n");
    fprintf(f, "## Description\n\n");
    fprintf(f, "This project is part of the 42 curriculum.\n\n");

    if (strstr(project, "minishell") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- Command parsing\n");
        fprintf(f, "- Command execution\n");
        fprintf(f, "- Built-in commands (echo, cd, pwd, export, unset, env, exit)\n");
        fprintf(f, "- Redirections (<, >, >>, <<)\n");
        fprintf(f, "- Pipes\n");
        fprintf(f, "- Environment variable expansion\n");
        fprintf(f, "- Signal handling\n\n");
    }

    fprintf(f, "## Compilation\n\n");
    fprintf(f, "```bash\n");
    fprintf(f, "make\n");
    fprintf(f, "```\n\n");
    fprintf(f, "## Usage\n\n");
    fprintf(f, "```bash\n");
    fprintf(f, "./%s\n", project);
    fprintf(f, "```\n\n");
    fprintf(f, "## Requirements\n\n");
    fprintf(f, "- GCC compiler\n");
    fprintf(f, "- Make\n");
    fprintf(f, "- Readline library (for minishell)\n\n");
    fprintf(f, "## Project Structure\n\n");
    fprintf(f, "```\n");
    fprintf(f, "%s/\n", project);
    fprintf(f, "├── src/\n");
    fprintf(f, "│   ├── main.c\n");
    fprintf(f, "│   └── utils.c\n");

    if (strstr(project, "minishell") != NULL) {
        fprintf(f, "│   ├── parser.c\n");
        fprintf(f, "│   ├── executor.c\n");
        fprintf(f, "│   └── builtins.c\n");
    }

    fprintf(f, "├── include/\n");
    fprintf(f, "│   └── %s.h\n", project);
    fprintf(f, "├── Makefile\n");
    fprintf(f, "├── README.md\n");
    fprintf(f, "├── author\n");
    fprintf(f, "└── .gitignore\n");
    fprintf(f, "```\n");
    fclose(f);
    return 1;
}

int create_header(const char *project, const char *upper) {
    char path[512];
    snprintf(path, sizeof(path), "%s/include/%s.h", project, project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen header");
        return 0;
    }
    fprintf(f, "#ifndef %s_H\n", upper);
    fprintf(f, "# define %s_H\n\n", upper);
    fprintf(f, "// Header for %s\n\n", project);
    fprintf(f, "#endif\n");
    fclose(f);
    return 1;
}

int create_project(const char *project, const char *upper) {
    if (!create_dirs(project)) {
        cleanup(project);
        return 0;
    }

    if (!create_makefile(project)) {
        cleanup(project);
        return 0;
    }

    if (!create_main(project)) {
        cleanup(project);
        return 0;
    }

    if (!create_utils(project)) {
        cleanup(project);
        return 0;
    }

    if (!create_header(project, upper)) {
        cleanup(project);
        return 0;
    }

    if (!create_gitignore(project)) {
        cleanup(project);
        return 0;
    }

    if (!create_author(project)) {
        cleanup(project);
        return 0;
    }

    if (!create_readme(project)) {
        cleanup(project);
        return 0;
    }

    // Create project-specific files
    if (strstr(project, "minishell") != NULL) {
        if (!create_minishell_files(project)) {
            cleanup(project);
            return 0;
        }
    }

    return 1;
}