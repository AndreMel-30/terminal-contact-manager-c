/*Funzione wrapper che include fgets e sscanf per ottenere un input intero utente da tastiera*/
int get_int(void); 
/*funzione che prende l'input utente ignorando spazi e parole dopo lo spazio.
L'array è creato FUORI la funzione e RIEMPITO dentro*/
void get_string_no_space(char input_string[]);
/* Funzione per l'acquisizione sicura di una stringa testuale.
Riceve in input il puntatore all'array di destinazione (dest) e la sua capienza fisica massima (n).
Restituisce un intero che funge da codice di stato: 1 (successo) o 0 (fallimento). Se viene inserita una stringa
più lunga di n essa viene troncata da fgets e rimangono caratteri nel buffer di input*/
int get_string(char dest[], unsigned long n);
