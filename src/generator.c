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
    fprintf(f, "SRC = $(SRC_DIR)/main.c\n");
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

    if (!create_header(project, upper)) {
        cleanup(project);
        return 0;
    }

    return 1;
}