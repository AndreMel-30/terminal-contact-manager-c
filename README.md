# Contact Manager in C

![Language](https://img.shields.io/badge/language-C-blue)
![Project Status](https://img.shields.io/badge/status-learning_project-green)
![Platform](https://img.shields.io/badge/platform-CLI-lightgrey)

A small command-line contact manager written in C to practice file handling, structs, string parsing, and modular program design.

## Overview

This project is a simple terminal-based application that allows users to store and manage contacts in a plain text file.

Each contact contains:

- First name
- Last name
- Phone number

Contacts are stored in `contatti.txt` using a semicolon-separated format:

```txt
Mario;Rossi;3331234567
Anna;Verdi;3497654321
```

The goal of the project was to build a small but complete C program while practicing low-level file operations and string handling.

## Features

- Add a new contact
- View all saved contacts
- Search contacts by name, surname, or phone number
- Delete a contact by selecting its index
- Save contacts to a text file
- Replace the original file safely using a temporary file

## Tech stack

- C
- Standard C library
- File-based persistence with text files

## What I practiced

This project helped me practice:

- `struct` definitions and usage
- file handling with `FILE *`
- `fopen`, `fclose`, `fprintf`, `fgets`, `fputs`
- `fflush()` after write operations
- string parsing with `sscanf`
- substring search with `strstr`
- safe file replacement using:
  - `remove()`
  - `rename()`
  - a temporary file
- modularization through helper functions

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

Compile with `gcc`:

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
1. Aggiungi un nuovo contatto
2. Visualizza tutti i contatti
3. Cerca un contatto
4. Elimina Contatto
5. Esci dal programma
```

## Example data

```txt
Luca;Bianchi;3330001111
Anna;Verdi;3491234567
Mario;Rossi;3479876543
```

## Implementation notes

- Contacts are stored in a plain text file rather than a database.
- The program uses `fopen("contatti.txt", "a+")` and explicitly calls `rewind()` before read operations.
- Contact lines are parsed with bounded `sscanf` scansets:
  - `%49[^;]`
  - `%49[^;]`
  - `%19[^;]`
- File deletion is implemented by copying all valid records except the selected one into a temporary file, then replacing the original file.

## Limitations

- Search is currently case-sensitive.
- The delete operation does not yet validate whether the selected index is out of range before rewriting the file.
- Data validation is minimal, especially for phone numbers.
- The project currently uses a simple text-file format and is not intended for large datasets.
- Output formatting in the terminal may not align perfectly with accented UTF-8 characters depending on the console.

## Possible improvements

- Add contact editing
- Add case-insensitive search
- Improve phone number validation
- Validate delete index before file rewrite
- Refactor repeated parsing logic into a dedicated helper function
- Rename source files to more descriptive names
- Add unit tests for parsing and input handling

## What I learned

This project helped me move beyond very small exercises and work on a complete CLI application in C.

In particular, I improved my understanding of:

- the difference between reading raw lines and parsing structured fields
- how file streams behave when reading and writing
- how to safely update file contents through a temporary file
- how to organize a C program into smaller functions with separate responsibilities

## Author

Developed as a personal learning project while practicing C programming.
