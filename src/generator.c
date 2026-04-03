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

    // Check project type and set appropriate source files
    if (strstr(project, "minishell") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/parser.c $(SRC_DIR)/executor.c $(SRC_DIR)/builtins.c\n");
    } else if (strstr(project, "push_swap") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/sort.c $(SRC_DIR)/stack_ops.c\n");
    } else if (strstr(project, "cub3d") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/render.c $(SRC_DIR)/map.c\n");
    } else if (strstr(project, "ft_printf") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/ft_printf.c\n");
    } else if (strstr(project, "get_next_line") != NULL || strstr(project, "gnl") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/get_next_line.c\n");
    } else if (strstr(project, "so_long") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/game.c $(SRC_DIR)/map_parser.c\n");
    } else if (strstr(project, "philosophers") != NULL || strstr(project, "philo") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/philosopher.c $(SRC_DIR)/monitor.c\n");
    } else if (strstr(project, "ft_irc") != NULL || strstr(project, "irc") != NULL) {
        fprintf(f, "SRC = $(SRC_DIR)/main.c $(SRC_DIR)/utils.c $(SRC_DIR)/server.c $(SRC_DIR)/commands.c\n");
    } else if (strstr(project, "webserv") != NULL) {
        fprintf(f, "CC = c++\n");
        fprintf(f, "CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -Iinclude\n\n");
        fprintf(f, "SRC_DIR = src\n");
        fprintf(f, "INC_DIR = include\n\n");
        fprintf(f, "SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/server.cpp $(SRC_DIR)/request.cpp\n");
    } else if (strstr(project, "cpp") != NULL || strstr(project, "module") != NULL) {
        fprintf(f, "CC = c++\n");
        fprintf(f, "CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -Iinclude\n\n");
        fprintf(f, "SRC_DIR = src\n");
        fprintf(f, "INC_DIR = include\n\n");
        fprintf(f, "SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/%s.cpp\n", project);
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
    int is_cpp = (strstr(project, "webserv") != NULL || strstr(project, "cpp") != NULL || strstr(project, "module") != NULL);
    
    if (is_cpp) {
        snprintf(path, sizeof(path), "%s/src/main.cpp", project);
    } else {
        snprintf(path, sizeof(path), "%s/src/main.c", project);
    }
    
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen main file");
        return 0;
    }
    
    if (is_cpp) {
        fprintf(f, "#include \"%s.hpp\"\n\n", project);
        fprintf(f, "#include <iostream>\n\n");
        fprintf(f, "int main(int argc, char *argv[]) {\n");
        fprintf(f, "    std::cout << \"Hello, %s!\" << std::endl;\n", project);
        fprintf(f, "    // TODO: implement %s\n", project);
        fprintf(f, "    return 0;\n");
        fprintf(f, "}\n");
    } else {
        fprintf(f, "#include \"%s.h\"\n\n", project);
        fprintf(f, "int main(int argc, char *argv[]) {\n");
        fprintf(f, "    // TODO: implement %s\n", project);
        fprintf(f, "    return 0;\n");
        fprintf(f, "}\n");
    }
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

int create_push_swap_files(const char *project) {
    // Create sort.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/sort.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen sort.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Sorting algorithms for %s\n\n", project);
    fprintf(f, "void bubble_sort(int *arr, int size) {\n");
    fprintf(f, "    // TODO: Implement bubble sort\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void quick_sort(int *arr, int low, int high) {\n");
    fprintf(f, "    // TODO: Implement quick sort\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create stack_ops.c
    snprintf(path, sizeof(path), "%s/src/stack_ops.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen stack_ops.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Stack operations for %s\n\n", project);
    fprintf(f, "void push(t_stack *stack, int value) {\n");
    fprintf(f, "    // TODO: Implement push operation\n");
    fprintf(f, "}\n\n");
    fprintf(f, "int pop(t_stack *stack) {\n");
    fprintf(f, "    // TODO: Implement pop operation\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "int is_empty(t_stack *stack) {\n");
    fprintf(f, "    // TODO: Check if stack is empty\n");
    fprintf(f, "    return 1;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_cub3d_files(const char *project) {
    // Create render.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/render.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen render.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Rendering functions for %s\n\n", project);
    fprintf(f, "void render_frame(t_game *game) {\n");
    fprintf(f, "    // TODO: Implement frame rendering\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void draw_wall(t_game *game, int x, int height) {\n");
    fprintf(f, "    // TODO: Implement wall drawing\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create map.c
    snprintf(path, sizeof(path), "%s/src/map.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen map.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Map handling functions for %s\n\n", project);
    fprintf(f, "int load_map(t_game *game, char *filename) {\n");
    fprintf(f, "    // TODO: Implement map loading\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "int validate_map(char **map) {\n");
    fprintf(f, "    // TODO: Implement map validation\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_ft_printf_files(const char *project) {
    // Create ft_printf.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/ft_printf.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen ft_printf.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// ft_printf implementation\n\n");
    fprintf(f, "int ft_printf(const char *format, ...) {\n");
    fprintf(f, "    // TODO: Implement ft_printf\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void handle_specifier(char specifier, va_list args) {\n");
    fprintf(f, "    // TODO: Handle format specifiers\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_gnl_files(const char *project) {
    // Create get_next_line.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/get_next_line.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen get_next_line.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Get Next Line implementation\n\n");
    fprintf(f, "#ifndef BUFFER_SIZE\n");
    fprintf(f, "# define BUFFER_SIZE 42\n");
    fprintf(f, "#endif\n\n");
    fprintf(f, "char *get_next_line(int fd) {\n");
    fprintf(f, "    // TODO: Implement get_next_line\n");
    fprintf(f, "    return NULL;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "char *read_line(int fd, char **stash) {\n");
    fprintf(f, "    // TODO: Read line from file descriptor\n");
    fprintf(f, "    return NULL;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_so_long_files(const char *project) {
    // Create game.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/game.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen game.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Game logic for %s\n\n", project);
    fprintf(f, "void init_game(t_game *game) {\n");
    fprintf(f, "    // TODO: Initialize game state\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void update_game(t_game *game) {\n");
    fprintf(f, "    // TODO: Update game logic\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void render_game(t_game *game) {\n");
    fprintf(f, "    // TODO: Render game graphics\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create map_parser.c
    snprintf(path, sizeof(path), "%s/src/map_parser.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen map_parser.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Map parsing for %s\n\n", project);
    fprintf(f, "int load_map(t_game *game, char *filename) {\n");
    fprintf(f, "    // TODO: Load and validate map file\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "int validate_map(char **map, int height, int width) {\n");
    fprintf(f, "    // TODO: Check map validity (walls, player, collectibles, exit)\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_philosophers_files(const char *project) {
    // Create philosopher.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/philosopher.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen philosopher.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Philosopher thread logic\n\n");
    fprintf(f, "void *philosopher_routine(void *arg) {\n");
    fprintf(f, "    t_philo *philo = (t_philo *)arg;\n");
    fprintf(f, "    \n");
    fprintf(f, "    while (!philo->data->simulation_end) {\n");
    fprintf(f, "        // TODO: Think, eat, sleep cycle\n");
    fprintf(f, "        take_forks(philo);\n");
    fprintf(f, "        eat(philo);\n");
    fprintf(f, "        put_forks(philo);\n");
    fprintf(f, "        sleep_and_think(philo);\n");
    fprintf(f, "    }\n");
    fprintf(f, "    return NULL;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void take_forks(t_philo *philo) {\n");
    fprintf(f, "    // TODO: Implement fork taking logic\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create monitor.c
    snprintf(path, sizeof(path), "%s/src/monitor.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen monitor.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// Monitor thread for death detection\n\n");
    fprintf(f, "void *monitor_routine(void *arg) {\n");
    fprintf(f, "    t_data *data = (t_data *)arg;\n");
    fprintf(f, "    \n");
    fprintf(f, "    while (!data->simulation_end) {\n");
    fprintf(f, "        // TODO: Check if any philosopher died\n");
    fprintf(f, "        usleep(1000);\n");
    fprintf(f, "    }\n");
    fprintf(f, "    return NULL;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_ft_irc_files(const char *project) {
    // Create server.c
    char path[512];
    snprintf(path, sizeof(path), "%s/src/server.c", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen server.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// IRC server implementation\n\n");
    fprintf(f, "int init_server(t_server *server, int port) {\n");
    fprintf(f, "    // TODO: Initialize server socket\n");
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void run_server(t_server *server) {\n");
    fprintf(f, "    // TODO: Main server loop\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void handle_client(t_server *server, int client_fd) {\n");
    fprintf(f, "    // TODO: Handle client connections and messages\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create commands.c
    snprintf(path, sizeof(path), "%s/src/commands.c", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen commands.c");
        return 0;
    }
    fprintf(f, "#include \"%s.h\"\n\n", project);
    fprintf(f, "// IRC command handling\n\n");
    fprintf(f, "void handle_nick(t_client *client, char *nick) {\n");
    fprintf(f, "    // TODO: Handle NICK command\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void handle_join(t_client *client, char *channel) {\n");
    fprintf(f, "    // TODO: Handle JOIN command\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void handle_privmsg(t_client *client, char *target, char *message) {\n");
    fprintf(f, "    // TODO: Handle PRIVMSG command\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_webserv_files(const char *project) {
    // Create server.cpp
    char path[512];
    snprintf(path, sizeof(path), "%s/src/server.cpp", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen server.cpp");
        return 0;
    }
    fprintf(f, "#include \"%s.hpp\"\n\n", project);
    fprintf(f, "// Web server implementation\n\n");
    fprintf(f, "Server::Server() {\n");
    fprintf(f, "    // TODO: Initialize server\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void Server::run() {\n");
    fprintf(f, "    // TODO: Main server loop\n");
    fprintf(f, "}\n\n");
    fprintf(f, "void Server::handleRequest(int client_fd) {\n");
    fprintf(f, "    // TODO: Handle HTTP requests\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create request.cpp
    snprintf(path, sizeof(path), "%s/src/request.cpp", project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen request.cpp");
        return 0;
    }
    fprintf(f, "#include \"%s.hpp\"\n\n", project);
    fprintf(f, "// HTTP request parsing\n\n");
    fprintf(f, "Request::Request(std::string raw_request) {\n");
    fprintf(f, "    // TODO: Parse HTTP request\n");
    fprintf(f, "}\n\n");
    fprintf(f, "std::string Request::getMethod() {\n");
    fprintf(f, "    return method;\n");
    fprintf(f, "}\n\n");
    fprintf(f, "std::string Request::getPath() {\n");
    fprintf(f, "    return path;\n");
    fprintf(f, "}\n");
    fclose(f);

    return 1;
}

int create_cpp_files(const char *project) {
    // Create main.cpp
    char path[512];
    snprintf(path, sizeof(path), "%s/src/main.cpp", project);
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen main.cpp");
        return 0;
    }
    fprintf(f, "#include \"%s.hpp\"\n\n", project);
    fprintf(f, "#include <iostream>\n\n");
    fprintf(f, "int main(int argc, char *argv[]) {\n");
    fprintf(f, "    std::cout << \"Hello, %s!\" << std::endl;\n", project);
    fprintf(f, "    // TODO: Implement %s\n", project);
    fprintf(f, "    return 0;\n");
    fprintf(f, "}\n");
    fclose(f);

    // Create class.cpp
    snprintf(path, sizeof(path), "%s/src/%s.cpp", project, project);
    f = fopen(path, "w");
    if (!f) {
        perror("fopen class.cpp");
        return 0;
    }
    fprintf(f, "#include \"%s.hpp\"\n\n", project);
    fprintf(f, "// %s class implementation\n\n", project);
    fprintf(f, "%s::%s() {\n", project, project);
    fprintf(f, "    // Constructor\n");
    fprintf(f, "}\n\n");
    fprintf(f, "%s::~%s() {\n", project, project);
    fprintf(f, "    // Destructor\n");
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
    } else if (strstr(project, "push_swap") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- Stack sorting algorithms\n");
        fprintf(f, "- Stack operations (push, pop, swap, rotate)\n");
        fprintf(f, "- Sorting instruction generation\n");
        fprintf(f, "- Performance optimization\n\n");
    } else if (strstr(project, "cub3d") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- 3D raycasting engine\n");
        fprintf(f, "- Map parsing and validation\n");
        fprintf(f, "- Texture rendering\n");
        fprintf(f, "- Player movement and rotation\n");
        fprintf(f, "- Wall collision detection\n\n");
    } else if (strstr(project, "ft_printf") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- Custom printf implementation\n");
        fprintf(f, "- Format specifiers (%%c, %%s, %%p, %%d, %%i, %%u, %%x, %%X, %%%%)\n");
        fprintf(f, "- Width and precision handling\n");
        fprintf(f, "- Flag support (-, 0, #, +, space)\n\n");
    } else if (strstr(project, "get_next_line") != NULL || strstr(project, "gnl") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- Read line from file descriptor\n");
        fprintf(f, "- Dynamic buffer management\n");
        fprintf(f, "- Handle multiple file descriptors\n");
        fprintf(f, "- Memory leak prevention\n\n");
    } else if (strstr(project, "so_long") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- 2D game with player movement\n");
        fprintf(f, "- Map parsing and validation\n");
        fprintf(f, "- Collectible items and exit condition\n");
        fprintf(f, "- Wall collision detection\n");
        fprintf(f, "- Sprite rendering\n\n");
    } else if (strstr(project, "philosophers") != NULL || strstr(project, "philo") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- Multi-threaded dining philosophers problem\n");
        fprintf(f, "- Mutex synchronization\n");
        fprintf(f, "- Death detection and monitoring\n");
        fprintf(f, "- Thread-safe operations\n");
        fprintf(f, "- Performance timing\n\n");
    } else if (strstr(project, "ft_irc") != NULL || strstr(project, "irc") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- IRC server implementation\n");
        fprintf(f, "- Client connection handling\n");
        fprintf(f, "- Channel management\n");
        fprintf(f, "- IRC protocol commands (NICK, JOIN, PRIVMSG, etc.)\n");
        fprintf(f, "- Multi-client support\n\n");
    } else if (strstr(project, "webserv") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- HTTP web server\n");
        fprintf(f, "- Request parsing and handling\n");
        fprintf(f, "- CGI support\n");
        fprintf(f, "- Configuration file parsing\n");
        fprintf(f, "- Multi-threading support\n\n");
    } else if (strstr(project, "cpp") != NULL || strstr(project, "module") != NULL) {
        fprintf(f, "## Features\n\n");
        fprintf(f, "- C++98 standard implementation\n");
        fprintf(f, "- Object-oriented design\n");
        fprintf(f, "- STL usage\n");
        fprintf(f, "- Memory management\n");
        fprintf(f, "- Exception handling\n\n");
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
    } else if (strstr(project, "push_swap") != NULL) {
        fprintf(f, "│   ├── sort.c\n");
        fprintf(f, "│   └── stack_ops.c\n");
    } else if (strstr(project, "cub3d") != NULL) {
        fprintf(f, "│   ├── render.c\n");
        fprintf(f, "│   └── map.c\n");
    } else if (strstr(project, "ft_printf") != NULL) {
        fprintf(f, "│   └── ft_printf.c\n");
    } else if (strstr(project, "get_next_line") != NULL || strstr(project, "gnl") != NULL) {
        fprintf(f, "│   └── get_next_line.c\n");
    } else if (strstr(project, "so_long") != NULL) {
        fprintf(f, "│   ├── game.c\n");
        fprintf(f, "│   └── map_parser.c\n");
    } else if (strstr(project, "philosophers") != NULL || strstr(project, "philo") != NULL) {
        fprintf(f, "│   ├── philosopher.c\n");
        fprintf(f, "│   └── monitor.c\n");
    } else if (strstr(project, "ft_irc") != NULL || strstr(project, "irc") != NULL) {
        fprintf(f, "│   ├── server.c\n");
        fprintf(f, "│   └── commands.c\n");
    } else if (strstr(project, "webserv") != NULL) {
        fprintf(f, "│   ├── server.cpp\n");
        fprintf(f, "│   └── request.cpp\n");
    } else if (strstr(project, "cpp") != NULL || strstr(project, "module") != NULL) {
        fprintf(f, "│   ├── main.cpp\n");
        fprintf(f, "│   └── %s.cpp\n", project);
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
    int is_cpp = (strstr(project, "webserv") != NULL || strstr(project, "cpp") != NULL || strstr(project, "module") != NULL);
    
    if (is_cpp) {
        snprintf(path, sizeof(path), "%s/include/%s.hpp", project, project);
    } else {
        snprintf(path, sizeof(path), "%s/include/%s.h", project, project);
    }
    
    FILE *f = fopen(path, "w");
    if (!f) {
        perror("fopen header");
        return 0;
    }
    
    if (is_cpp) {
        fprintf(f, "#ifndef %s_HPP\n", upper);
        fprintf(f, "# define %s_HPP\n\n", upper);
        fprintf(f, "#include <iostream>\n");
        fprintf(f, "#include <string>\n");
        fprintf(f, "#include <vector>\n\n");
        fprintf(f, "// Header for %s\n\n", project);
        fprintf(f, "class %s {\n", project);
        fprintf(f, "public:\n");
        fprintf(f, "    %s();\n", project);
        fprintf(f, "    ~%s();\n", project);
        fprintf(f, "    // TODO: Add methods\n");
        fprintf(f, "};\n\n");
        fprintf(f, "#endif\n");
    } else {
        fprintf(f, "#ifndef %s_H\n", upper);
        fprintf(f, "# define %s_H\n\n", upper);
        fprintf(f, "// Header for %s\n\n", project);
        fprintf(f, "#endif\n");
    }
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
    } else if (strstr(project, "push_swap") != NULL) {
        if (!create_push_swap_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "cub3d") != NULL) {
        if (!create_cub3d_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "ft_printf") != NULL) {
        if (!create_ft_printf_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "get_next_line") != NULL || strstr(project, "gnl") != NULL) {
        if (!create_gnl_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "so_long") != NULL) {
        if (!create_so_long_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "philosophers") != NULL || strstr(project, "philo") != NULL) {
        if (!create_philosophers_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "ft_irc") != NULL || strstr(project, "irc") != NULL) {
        if (!create_ft_irc_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "webserv") != NULL) {
        if (!create_webserv_files(project)) {
            cleanup(project);
            return 0;
        }
    } else if (strstr(project, "cpp") != NULL || strstr(project, "module") != NULL) {
        if (!create_cpp_files(project)) {
            cleanup(project);
            return 0;
        }
    }

    return 1;
}