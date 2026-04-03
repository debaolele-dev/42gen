# 🚀 42gen

**42gen** is a lightweight CLI tool designed for 42 students to instantly generate clean, norm-compliant project structures — so you can focus on coding, not setup.

---

## 🧠 Why 42gen?

At 42, every project starts the same way:

* Creating folders (`src/`, `include/`)
* Writing a Makefile
* Adding basic files (`main.c`, `.h`)

This process is repetitive and error-prone.

👉 **42gen solves this in one command.**

---

## ⚡ Features

* 📁 Auto-generate project structure
* ⚙️ Ready-to-use Makefile (42 compliant)
* 🧾 Starter files (`main.c`, headers)
* 🌿 Optional Git initialization
* 🎯 Bonus file support
* 🧠 Beginner-friendly and fast

---

## 🛠️ Installation

```bash
git clone https://github.com/yourusername/42gen.git
cd 42gen
make
```

---

## 🚀 Usage

### Basic Command

```bash
./42gen <project_name>
```

### Example

```bash
./42gen minishell
```

👉 This will create:

```
minishell/
├── src/
├── include/
├── Makefile
└── main.c
```

---

## ⚙️ Options

### 🔹 Add Bonus Files

```bash
./42gen minishell --bonus
```

---

### 🔹 Initialize Git Repository

```bash
./42gen minishell --git
```

---

### 🔹 Add Author Name

```bash
./42gen minishell --author your_login
```

---

### 🔹 Full Command Example

```bash
./42gen minishell --bonus --git --author your_login
```

---

## 📂 Generated Makefile (Example)

```make
NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

---

## 🧑‍🏫 How It Works

42gen performs these steps internally:

1. Reads project name from arguments
2. Creates project directory
3. Generates subfolders (`src`, `include`)
4. Creates required files
5. Writes template content inside files
6. Applies optional features (`--git`, `--bonus`, etc.)

---

## 🌟 Why This Project Matters

* Saves time for every 42 student
* Reduces setup errors
* Encourages clean project structure
* Demonstrates system programming skills (file handling, CLI parsing)

---

## 🔮 Future Improvements

* 🔧 Norminette auto-check integration
* 🎨 Custom templates
* 🌐 Multi-language support
* 📦 Package installer (brew / apt)

---

## 🤝 Contributing

Contributions are welcome!
Feel free to fork, improve, and submit a pull request.

---

## 📄 License

This project is open-source and available under the MIT License.

---