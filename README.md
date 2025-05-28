# Minishell

**Minishell** is a C-based terminal control library that aims to recreate a simple shell, similar to a basic version of bash or zsh. This project focuses on understanding processes, file descriptors, and terminal manipulation, offering a glimpse into how shells operated before modern GUIs.

## 📝 Project Overview

The primary objective is to build your own functional shell that handles basic command execution, input/output redirection, pipes, and essential built-in commands. It leverages `termcap` for advanced line editing and history navigation, providing a more interactive user experience.

## 📁 Project Structure
```
minishell/
├── main.c     # Main shell loop and command handling
├── src/                     # Implementation files for various shell functionalities
│   ├── builtins.c           # Implementations for cd, echo, pwd, export, unset, env, exit
│   ├── command_execution.c  # Logic for searching and launching executables
│   ├── parsing.c            # Command line parsing (quotes, redirections, pipes)
│   ├── signal_handling.c    # Control+C, Control+D, Control+\\ handling
│   ├── term_utils.c         # termios and termcap related utilities for line editing
│   └── (other utility files as needed)
├── inc/                     # Header files
│   ├── minishell.h          # Main project headers
│   ├── (other utility headers)
├── Makefile                 # Build automation
└── .gitignore               # Files/directories to ignore in Git
```

## 🔧 Build Instructions

To build the project:

```bash
make
```
This compiles the program and generates an executable named `minishell` (as per the subject requirements).

## 🖥️ Run

After building, run the shell with:

```bash
./minishell
```

## 🧩 Dependencies

- `gcc`
- `make`
- `ncurses` library (or `libtinfo` which provides termcap functions)

On Debian/Ubuntu, install with:

```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

## 📄 Features

- **Prompt:** Displays a prompt while waiting for new commands.
- **Command Execution:** Searches and launches executables based on the `PATH` variable or using relative/absolute paths, similar to bash.
- **Built-in Commands:** Implements the following bash builtins:
  - `echo` with option `-n`
  - `cd` with only a relative or absolute path
  - `pwd` without any options
  - `export` without any options
  - `unset` without any options
  - `env` without any options and any arguments
  - `exit` without any options
- **Command Separator:** Supports `;` to separate commands, like in bash.
- **Quotes:** Handles `'` (single quotes) and `"` (double quotes) like in bash, excluding multiline commands.
- **Redirections:** Implements `<` (input redirection), `>` (output redirection), and `>>` (append output redirection) like in bash, excluding file descriptor aggregation.
- **Pipes:** Supports `|` (pipes) like in bash, excluding multiline commands.
- **Environment Variables:** Expands environment variables (`$VAR`) like in bash.
- **Exit Status Variable:** Supports `$?` to get the exit status of the last command.
- **Signal Handling:** `ctrl-C`, `ctrl-D`, and `ctrl-\` have the same result as in bash.
- **History Navigation:** Uses termcap to navigate through command history with up and down arrows.
- **Basic Line Editing:** Allows editing of commands from history (at least like classic lines).

## ✅ Allowed External Functions

`printf`, `malloc`, `free`, `write`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `errno`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`.

## 🛠️ Build Rules

Your `Makefile` must at least contain the following rules:

- `$(NAME)`
- `all`
- `clean`
- `fclean`
- `re`

## 📏 Norm & Error Handling

- All code must adhere to the project's Norm.
- Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.).
- All heap-allocated memory space must be properly freed; no leaks will be tolerated.

## 🧹 Clean

To clean the build artifacts:

```bash
make clean
```
