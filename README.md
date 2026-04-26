# Contact Manager in C

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/status-learning_project-green)
![Interface](https://img.shields.io/badge/interface-CLI-lightgrey)

Una piccola rubrica da riga di comando scritta in C per esercitarmi con struct, gestione dei file, parsing di stringhe e organizzazione modulare del codice.

## Descrizione del progetto

Questo progetto è una semplice rubrica da terminale che salva i contatti in un file di testo.

Ogni contatto contiene:

- Nome
- Cognome
- Numero di telefono

I contatti vengono salvati nel file `contatti.txt` usando un formato separato da punto e virgola:

```txt
Mario;Rossi;3331234567
Anna;Verdi;3497654321
```

L’obiettivo principale del progetto è stato rafforzare le mie basi in C costruendo un’applicazione piccola ma completa, con persistenza dei dati su file.

## Funzionalità

- Aggiungere un nuovo contatto
- Visualizzare tutti i contatti salvati
- Cercare un contatto per nome, cognome o numero di telefono
- Eliminare un contatto tramite indice
- Salvare i dati in un file di testo
- Sostituire in modo sicuro il file originale usando un file temporaneo

## Tecnologie usate

- C
- Libreria standard del C

## Cosa ho esercitato

Questo progetto mi ha permesso di esercitarmi con:

- uso delle `struct`
- gestione dei file con `FILE *`
- `fopen`, `fclose`, `fprintf`, `fgets`, `fputs`
- `fflush()` dopo le operazioni di scrittura
- parsing di testo strutturato con `sscanf`
- ricerca di sottostringhe con `strstr`
- sostituzione sicura di un file usando:
  - `remove()`
  - `rename()`
  - un file temporaneo
- suddivisione della logica in funzioni separate

## Struttura del progetto

```txt
.
├── main.c
├── mie_funzioni.c
├── mie_funzioni.h
├── contatti.txt
└── README.md
```

## Compilazione

Esempio con `gcc`:

```bash
gcc main.c mie_funzioni.c -o contact-manager
```

## Esecuzione

Su Linux/macOS:

```bash
./contact-manager
```

Su Windows:

```bash
contact-manager.exe
```

## Esempio di menu

```txt
1. Aggiungi un nuovo contatto
2. Visualizza tutti i contatti
3. Cerca un contatto
4. Elimina Contatto
5. Esci dal programma
```

## Dettagli implementativi

- I contatti vengono salvati in un semplice file di testo e non in un database.
- Il file viene aperto in modalità `a+` e riposizionato con `rewind()` prima delle operazioni di lettura.
- 
