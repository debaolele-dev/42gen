#include <42gen.h>

void to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int is_valid_project_name(const char *name) {
    if (!name || !*name) return 0;
    for (const char *p = name; *p; p++) {
        if (!isalnum((unsigned char)*p) && *p != '_' && *p != '-') return 0;
    }
    return 1;
}

void cleanup(const char *project) {
    char path[512];

    // Remove main files (could be .c or .cpp)
    snprintf(path, sizeof(path), "%s/src/main.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/main.cpp", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/utils.c", project);
    unlink(path);

    // Remove header files (could be .h or .hpp)
    snprintf(path, sizeof(path), "%s/include/%s.h", project, project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/include/%s.hpp", project, project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/Makefile", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/.gitignore", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/author", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/README.md", project);
    unlink(path);

    // Remove minishell-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/parser.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/executor.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/builtins.c", project);
    unlink(path);

    // Remove push_swap-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/sort.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/stack_ops.c", project);
    unlink(path);

    // Remove cub3d-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/render.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/map.c", project);
    unlink(path);

    // Remove ft_printf-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/ft_printf.c", project);
    unlink(path);

    // Remove gnl-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/get_next_line.c", project);
    unlink(path);

    // Remove so_long-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/game.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/map_parser.c", project);
    unlink(path);

    // Remove philosophers-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/philosopher.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/monitor.c", project);
    unlink(path);

    // Remove ft_irc-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/server.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/commands.c", project);
    unlink(path);

    // Remove webserv-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/server.cpp", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/request.cpp", project);
    unlink(path);

    // Remove cpp-specific files if they exist
    snprintf(path, sizeof(path), "%s/src/main.cpp", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/%s.cpp", project, project);
    unlink(path);

    // Remove header files
    snprintf(path, sizeof(path), "%s/include/%s.h", project, project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/include/%s.hpp", project, project);
    unlink(path);

    // Remove directories
    snprintf(path, sizeof(path), "%s/include", project);
    rmdir(path);

    snprintf(path, sizeof(path), "%s/src", project);
    rmdir(path);

    rmdir(project);
}