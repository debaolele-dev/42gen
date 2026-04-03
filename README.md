# 42gen (42 Project Starter Generator)

`42gen` is a C command-line generator for 42 school projects. It creates a project skeleton with standard 42 layout and compiles via a one-command build.

## ✅ What it generates

Given a project name `myproject`, it creates:

- `myproject/`
  - `src/`
    - `main.c`
    - `utils.c` (with common utility functions)
  - `include/`
    - `myproject.h`
  - `Makefile`
  - `README.md` (comprehensive documentation)
  - `author` (42 login file)
  - `.gitignore` (standard C/gitignore patterns)

**Special for minishell projects:**
- Additional source files: `parser.c`, `executor.c`, `builtins.c`
- Updated Makefile to compile all files
- Enhanced README with minishell-specific features

**Git integration:**
- Automatically initializes git repository
- Adds all files and creates initial commit

Generated Makefile uses:
- `-Wall -Wextra -Werror`
- `-Iinclude`

## 📁 Project source structure

- `src/main.c` (command line entry)
- `src/generator.c` (scaffolding functions)
- `src/utils.c` (helpers)
- `include/42gen.h` (declarations)
- `Makefile` (build targets)
- `README.md`

## 🛠 Build

```bash
make
```

## ▶️ Usage

```bash
./42gen <project_name>
```

Example:

```bash
./42gen minishell
```

## 📌 Validations included

- Accept only `[A-Za-z0-9_-]` project names
- Prevent directory overwrite
- Use safe functions (`snprintf`, `strncpy`)
- Cleanup on failure (`unlink`, `rmdir`)
- `--help` output built-in

## 📦 Makefile targets

- `make` / `make default`: build the generator
- `make 42gen`: compile `42gen` binary
- `make clean`: remove objects
- `make fclean`: remove objects + binary
- `make re`: rebuild
- `make linux` / `make mac` / `make windows`: OS-specific stubs

## 🔮 Future features

- `--bonus` and `--git`
- norminette template
- GUI mode (SDL2/webview)
- Cross-platform installer (Linux/macOS/Windows)

---

## 🤝 Contribution

Fork + PRs welcome.

---

## 🤝 Contributing

Contributions are welcome!
Feel free to fork, improve, and submit a pull request.

---

## 📄 License

This project is open-source and available under the MIT License.

---
