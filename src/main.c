#include <42gen.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || (argc == 2 && strcmp(argv[1], "--help") == 0)) {
        printf("INIT42 Project Starter Generator\n");
        printf("Usage: %s <project_name>\n", argv[0]);
        printf("Options:\n");
        printf("  --help    Show this help message\n");
        return 0;
    }

    if (argc != 2) {
        printf("Usage: %s <project_name>\n", argv[0]);
        return 1;
    }

    char *project = argv[1];

    if (!is_valid_project_name(project)) {
        printf("❌ Error: Invalid project name. Use only letters, numbers, underscores, and hyphens.\n");
        return 1;
    }

    // Check if project already exists
    if (access(project, F_OK) == 0) {
        printf("❌ Error: Project '%s' already exists!\n", project);
        return 1;
    }

    char project_upper[256];
    strncpy(project_upper, project, sizeof(project_upper) - 1);
    project_upper[sizeof(project_upper) - 1] = '\0';
    to_upper(project_upper);

    if (!create_project(project, project_upper)) {
        return 1;
    }

    // Initialize git repository
    char git_cmd[512];
    snprintf(git_cmd, sizeof(git_cmd), "cd %s && git init && git add . && git commit -m \"Initial commit\"", project);
    system(git_cmd);

    printf("✅ Project '%s' created successfully!\n", project);
    printf("👉 Next: cd %s && make\n", project);
    return 0;
}