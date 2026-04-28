# Terminal Contact Manager in C

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/status-learning_project-green)
![Interface](https://img.shields.io/badge/interface-CLI-lightgrey)

A small command-line contact manager written in C.

This project was developed as a practical exercise to work on core C concepts such as:
- structs
- file handling
- string parsing
- input validation
- and code organization across multiple functions

## Project overview

The program stores a simple contact list in a text file and allows the user to:

- add a new contact
- display all saved contacts
- search for a contact
- delete a contact by index

Each contact contains:
- first name
- last name
- phone number

The data is stored in a plain text file called `contatti.txt`, using a semicolon-separated format such as:

```txt
Mario;Rossi;3331234567
Anna;Verdi;3497654321
```

This is a small educational project, so the goal is not to build a full address book application, but to practice low-level programming and file-based data management in C.

## Features

- Add a new contact
- View all saved contacts
- Search by name, surname, or phone number
- Delete a contact by selecting its index
- Persistent storage using a text file
- Safe file replacement through a temporary file

## Technologies used

- **C**
- **C Standard Library**

## Concepts practiced

This project was useful to reinforce:

- `struct` usage
- file handling with `FILE *`
- `fopen`, `fclose`, `fprintf`, `fgets`, `fputs`
- `fflush()` after writes
- parsing structured lines with `sscanf`
- substring search with `strstr`
- safe file update using:
  - `remove()`
  - `rename()`
  - a temporary file
- splitting logic into separate functions

## Project structure

```txt
.
├── main.c
├── mie_funzioni.c
├── mie_funzioni.h
├── contatti.txt
└── README.md
```

## Build

Example with `gcc`:

```bash
gcc main.c mie_funzioni.c -o contact-manager
```

## Run

On Linux/macOS:

```bash
./contact-manager
```

On Windows:

```bash
contact-manager.exe
```

## Example menu

```txt
1. Add a new contact
2. View all contacts
3. Search for a contact
4. Delete a contact
5. Exit
```

## Implementation notes

- Contacts are stored in a text file, not in a database.
- The file is opened in `a+` mode and repositioned with `rewind()` before reading.
- Contact fields are parsed with `sscanf` using length limits to reduce overflow risks.
- Deletion is handled by copying valid records into a temporary file and then replacing the original one.
- File-related errors are reported with `perror()`.

## Current limitations

- Search is case-sensitive.
- Phone number validation is still minimal.
- Index validation for deletion can be improved.
- The project is intended for small datasets and learning purposes.
- Output alignment may vary depending on terminal and character encoding.

## Possible improvements

- Add contact editing
- Make search case-insensitive
- Improve input validation
- Move repeated parsing logic into a dedicated helper function
- Rename source files with more descriptive names
- Add tests for parsing and input handling

## Why this project

The main purpose of this project was to move beyond very small C exercises and build a simple but complete terminal application with persistent data.

It helped reinforce the difference between:
- raw text input and structured parsing
- basic file reading and safe file updating
- writing code that works and organizing it into reusable functions

---

**Author:** Andrea Melissari
