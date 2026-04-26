#include <stdio.h>
#include <string.h>
#include "mie_funzioni.h"

struct Contatto {
    char nome[50];
    char cognome[50];
    char telefono[20];
};

FILE* open_file()
{
    FILE *fptr;
    fptr = fopen("contatti.txt", "a+");
    if (fptr == NULL) {  
        return NULL;  // es. non ho i permessi per leggere quel file 
    }
    return fptr;
}

void inserisci_nome(FILE *fptr, struct Contatto *contatto)
{
        // Acquisisco gli input (nome, congome, telefono)
        printf("Inserire nome: \n");
        get_string(contatto->nome,sizeof(contatto->nome)); 
        printf("Inserire cognome: \n");
        get_string(contatto->cognome, sizeof(contatto->cognome));
        printf("Inserire numero di telefono \n");
        get_string(contatto->telefono, sizeof(contatto->telefono));
        
        // li salvo nel file
        fprintf(fptr,"%s;%s;%s\n", contatto->nome, contatto->cognome, contatto->telefono);
        fflush(fptr); // forzare la scrittura dei dati buffered sul file associato allo stream
        printf("\n");
}

void visualizza_rubrica(FILE *fptr, char riga[], const int BUFFER_SIZE, struct Contatto *contatto)
{
    rewind(fptr);
    // intestazione
    printf("RUBRICA\n");
    printf("-------------------------------------------------------\n");
    printf("%-20s %-20s %-15s\n", "Nome", "Cognome", "Telefono");
    printf( "\n");

    while (fgets(riga,BUFFER_SIZE,fptr)!=NULL)
    {
        int v = sscanf(riga,"%49[^;];%49[^;];%19[^;]",contatto->nome,contatto->cognome,contatto->telefono);
        if(v == 3) // sscanf deve restituire 3 se il parsing è corretto
        {
            // allineo i testi lasciando gli spazi
            printf("%-20s %-20s %s", contatto->nome, contatto->cognome, contatto->telefono);
        }
        else 
        {
            continue;
        }
    } 
    printf("\n");
    printf("\n");
}

void cerca_contatto(FILE *fptr, char riga[], const int BUFFER_SIZE, struct Contatto *contatto)
{
    printf("Inserire nome, cognome o numero di telefono del contatto da cercare \n");
    char cercato[50]; // contatto da cercare
    get_string(cercato, sizeof(cercato));
    rewind(fptr); 
    while (fgets(riga,BUFFER_SIZE,fptr)!=NULL)
    {   
        // punta al primo byte della sottostringa trovata
        char* subs = strstr(riga, cercato);
        if (subs != NULL) 
        {
            // se trovo la sottostringa cercata in riga, la restituisco 
            int v = sscanf(riga,"%49[^;];%49[^;];%19[^;]",contatto->nome,contatto->cognome,contatto->telefono);
            if(v == 3) 
            {
                printf("%-20s %-20s %s", contatto->nome, contatto->cognome, contatto->telefono);
            }
            else // ho incontrato una riga formattata male, la salto
            {
                continue;
            }
        }
    }
    printf("\n");
}

void elimina_contatto(char riga[], const int BUFFER_SIZE, struct Contatto *contatto)
{
    // creo il puntatore al file
    FILE* fptr = open_file();
    if(fptr == NULL)
    {
        perror("Errore nell'aprire i file");
        return;
    }
    // prima visualizzo i contatti nel formato indice. Nome Cognome Telefono
    int indice = 1; // indice numerico della lista
    printf("\n");
    rewind(fptr);
    while (fgets(riga,BUFFER_SIZE,fptr)!=NULL)
    {  
        int v = sscanf(riga,"%49[^;];%49[^;];%19[^;]",contatto->nome,contatto->cognome,contatto->telefono);
        if(v == 3)
        {
            printf("%2d. %-20s %-20s %s", indice ,contatto->nome,contatto->cognome,contatto->telefono);
        }
        else 
        {
            continue;
        }
        indice++;
    }
    printf("\n"); 
    printf("Scegli l'indice del contatto da eliminare o premi \"0\" per annullare\n");
    int select = get_int(); // prendi l'indice
    if(select == 0)
    {
        // esci dalla funzione
        printf("\n");
        printf("Annullamento...");
        fclose(fptr);
        printf("\n");
        printf("\n");
        return;
    }
    int i = 1; // indice che uso per contare
    // file temporaneo che userò per copiare tutte le righe tranne quella da eliminare 
    FILE *temp_file;
    temp_file = fopen("contatti_temp.txt", "w");
    if (temp_file == NULL) 
    {   
        perror("Errore nell'aprire i file");
        fclose(fptr); // chiudo l'altro file
        return;
    }
    rewind(fptr);
    while (fgets(riga,BUFFER_SIZE,fptr)!=NULL)
    {   
        int v = sscanf(riga,"%49[^;];%49[^;];%19[^;]",contatto->nome,contatto->cognome,contatto->telefono);
        if(v == 3)  
        { 
            if(i != select) // riga da NON eliminare
            {   
                // copio la riga nel file temporaneo
                fputs(riga, temp_file);
            }
            i++;
        }
        else 
        {
            continue;
        }
    } 
    // chiudo entrambi i file
    fclose(fptr);
    fclose(temp_file);
    // rimuovo il vecchio file
    int rem = remove("contatti.txt");
    if (rem != 0) // errore di rimozione 
    {
        perror("\nErrore di rimozione\n");
        return;
    }
    // rinomino il nuovo come il primo 
    int ren = rename("contatti_temp.txt","contatti.txt");
    if(ren != 0)   // errore di rinominazione 
    {
        perror("\nErrore di rinominazione\n");
        return; 
    }
    printf("\n");
}

int main(void)
{
    // dimensione array che conterrà le righe del file 
    const int BUFFER_SIZE = 255;
    char riga[BUFFER_SIZE];
    struct Contatto contatto;

    while(1)
    {
        printf("1. Aggiungi un nuovo contatto\n");
        printf("2. Visualizza tutti i contatti\n");
        printf("3. Cerca un contatto\n");
        printf("4. Elimina Contatto\n");
        printf("5. Esci dal programma\n");
        int scelta = get_int();
        printf("\n");
        switch (scelta) { 	
                case 1: 
                {    
                    printf("\n");
                    printf("SCELTA 1: \n");
                    printf("\n");
                    FILE* fptr = open_file();
                    if(fptr == NULL)
                    {
                        perror("Errore nell'aprire i file");
                        break;
                    }
                    inserisci_nome(fptr, &contatto);
                    fclose(fptr);
                    break;
                }
                case 2: 
                {
                    printf("\n");
                    printf("SCELTA 2: \n");
                    printf("\n");
                    FILE* fptr = open_file();
                    if(fptr == NULL)
                    {
                        perror("Errore nell'aprire i file");
                        break;
                    }
                    visualizza_rubrica(fptr, riga, BUFFER_SIZE,&contatto);
                    fclose(fptr);
                    break;
                }
                case 3:
                {
                    printf("\n");
                    printf("SCELTA 3: \n");
                    printf("\n");
                    FILE* fptr = open_file();
                    if(fptr == NULL)
                    {
                        perror("Errore nell'aprire i file");
                        break;
                    }
                    cerca_contatto(fptr, riga, BUFFER_SIZE, &contatto);
                    printf("\n");
                    fclose(fptr);
                    break;
                }
                case 4:
                {
                    printf("\n");
                    printf("SCELTA 4: \n");
                    printf("\n");
                    // apertura e chiusura gestita da elimina contatto
                    elimina_contatto(riga, BUFFER_SIZE, &contatto);
                    break;
                }
                case 5: 
                {
                    printf("\n");
                    printf("SCELTA 5: \n");
                    printf("\n"); 
                   printf("Chiusura programma...\n");
                   return 0;
                }   
                default: 
                {
                    printf("Scelta non valida\n"); 
                    break; 
                }
            } 
    } 
    return 0; 
}
