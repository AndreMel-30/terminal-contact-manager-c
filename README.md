# Rubrica da terminale in C

![Language](https://img.shields.io/badge/language-C-blue)
![Status](https://img.shields.io/badge/status-learning_project-green)
![Interface](https://img.shields.io/badge/interface-CLI-lightgrey)

Piccolo progetto in C sviluppato per esercitarmi con struct, gestione dei file, parsing di stringhe e organizzazione del codice in funzioni.

## Il progetto

Questa applicazione è una semplice rubrica da terminale che permette di salvare, visualizzare, cercare ed eliminare contatti utilizzando un file di testo come archivio.

Ogni contatto contiene:

- Nome
- Cognome
- Numero di telefono

I dati vengono salvati nel file `contatti.txt` nel formato:

```txt
Mario;Rossi;3331234567
Anna;Verdi;3497654321
```

L’obiettivo del progetto è stato mettere in pratica alcuni concetti fondamentali del C attraverso un programma piccolo, ma completo e persistente.

## Funzionalità

- Inserimento di un nuovo contatto
- Visualizzazione di tutti i contatti salvati
- Ricerca per nome, cognome o numero di telefono
- Eliminazione di un contatto tramite indice
- Salvataggio dei dati su file
- Sostituzione sicura del file originale tramite file temporaneo

## Strumenti usati

- Linguaggio C
- Libreria standard del C

## Competenze esercitate

Con questo progetto ho lavorato su:

- uso delle `struct`
- gestione dei file con `FILE *`
- `fopen`, `fclose`, `fprintf`, `fgets`, `fputs`
- `fflush()` dopo la scrittura
- parsing di righe strutturate con `sscanf`
- ricerca di sottostringhe con `strstr`
- aggiornamento sicuro di un file con:
  - `remove()`
  - `rename()`
  - file temporaneo
- organizzazione del codice in funzioni separate

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

## Avvio

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

- I contatti vengono memorizzati in un file di testo, non in un database.
- Il file viene aperto in modalità `a+` e riposizionato con `rewind()` prima della lettura.
- Il parsing delle righe avviene con `sscanf` usando limiti di lunghezza:
  - `%49[^;]`
  - `%49[^;]`
  - `%19[^;]`
- L’eliminazione di un contatto viene gestita copiando i record validi in un file temporaneo e poi sostituendo il file originale.
- Gli errori nelle operazioni sui file vengono segnalati con `perror()`.

## Limitazioni

- La ricerca è sensibile a maiuscole e minuscole.
- La validazione del numero di telefono è ancora minimale.
- Il controllo dell’indice da eliminare può essere migliorato.
- Il progetto è pensato per scopi didattici e per quantità ridotte di dati.
- L’allineamento dell’output può non essere perfetto con caratteri accentati UTF-8, a seconda del terminale.

## Possibili sviluppi

- Aggiungere la modifica di un contatto
- Rendere la ricerca case-insensitive
- Migliorare la validazione dell’input
- Spostare il parsing ripetuto in una funzione dedicata
- Rinominare i file sorgente con nomi più descrittivi
- Aggiungere test per parsing e input handling

## Cosa ho imparato

Questo progetto mi ha aiutato a fare un passo oltre gli esercizi molto piccoli, lavorando su un programma completo da riga di comando.

In particolare mi ha permesso di consolidare:

- la differenza tra lettura di testo grezzo e parsing di dati strutturati
- il comportamento dei file stream in lettura e scrittura
- l’aggiornamento sicuro di un file tramite file temporaneo
- la suddivisione del codice in funzioni con responsabilità chiare

## Autore

Progetto personale sviluppato per esercitarmi con il linguaggio C.
