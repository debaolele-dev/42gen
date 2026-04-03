NAME = 42gen

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
INC_DIR = include

SRC = $(SRC_DIR)/main.c $(SRC_DIR)/generator.c $(SRC_DIR)/utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: default linux mac windows clean all fclean re

default: build

build:
	$(MAKE) 42gen

42gen:
	$(CC) $(CFLAGS) -Iinclude -o 42gen src/main.c src/generator.c src/utils.c \
	   $(shell pkg-config --libs sdl2)

linux:
	$(MAKE) OS=linux

mac:
	$(MAKE) OS=macos

windows:
	$(MAKE) OS=windows