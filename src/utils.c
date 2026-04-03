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

    // Remove files first
    snprintf(path, sizeof(path), "%s/src/main.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/src/utils.c", project);
    unlink(path);

    snprintf(path, sizeof(path), "%s/include/%s.h", project, project);
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

    // Remove directories
    snprintf(path, sizeof(path), "%s/include", project);
    rmdir(path);

    snprintf(path, sizeof(path), "%s/src", project);
    rmdir(path);

    rmdir(project);
}