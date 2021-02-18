
/* PROGRAMMA MASTERMIND - Versione NUMERICA 2016 - Autore: ATTENE ALESSANDRO */               

         /* INIZIO DIRETTIVE PRE-COMPILATORE */
         
#include <stdio.h>                                                              // inclusione libreria standard C
#include <stdlib.h>                                                             // inclusione libreria standard C
#include <time.h>                                                               // inclusione libreria standard C
#define TENTATIVI_STANDARD 10                                                   // definizione cost TENTATIVI_STANDARD -> valore 10
#define USATA 1                                                                 // definizione cost USATA (conteggiata) -> valore 1
#define NON_USATA 0                                                             // definizione cost NON_USATA (non conteggiata) -> valore 0
  
         /* FINE DIRETTIVE PRE-COMPILATORE */
            
         /* INIZIO funzione MAIN (PARTE DICHIARATIVA + PARTE ESECUTIVA) */
     
int main() {
   
         /* INIZIO PARTE DICHIARATIVA funzione MAIN*/
        
   int  numCifreSeqCorretta;                                                    // var "numero cifre" della sequenza corretta (4,6,8)
   char livGioco[2];                                                            // array "stringa" livello di gioco scelto dall'utente
   int  cifraVietata;                                                           // var "controllo" cifra/char non ammessa da regolamento
   char *strSeqCorretta = NULL;                                                 // array "stringa" sequenza caratteri seq.corretta
   char *strTentativoUtente = NULL;                                             // array "stringa" sequenza caratteri tent.utente(+1)
   int  *cifraSeqCorretta = NULL;                                               // array "marcatuta" cifra/char della sequenza corretta
   int  *cifraTentativoUtente = NULL;                                           // array "marcatura" cifra/char del tentativo utente
   int  cifrePosCorretta;                                                       // var "conteggio" cifre/char corrette in posizione corretta
   int  cifrePosErrata;                                                         // var "conteggio" cifre/char corrette in posizione errata
   int  i = 0;                                                                  // var "contatore" ciclo for esterno
   int  j = 0;                                                                  // var "contatore" ciclo for interno
   int  tentativiRimasti = TENTATIVI_STANDARD;                                  // var "tentativi ancora disponibili" Utente 
   int  tentativiUtilizzati;                                                    // var "tentativi gia' utilizzati" dall'utente
         
         /* FINE PARTE DICHIARATIVA funzione MAIN */
         
         /* INIZIO PARTE ESECUTIVA funzione MAIN */
   
         /* INIZIO PRESENTAZIONE GIOCO */
                  
   printf ("                   ***** BENVENUTO in MASTERMIND *****\n"
           "                           (versione numerica)\n\n"
           "                    ***** REGOLAMENTO del GIOCO *****\n\n"
           " Il GIOCO consiste nel dover indovinare una SEQUENZA NUMERICA, composta\n"
           " da 4, 6 oppure 8 CIFRE, a seconda del Livello di GIOCO scelto dal GIOCATORE.\n\n"
           " Le CIFRE ammesse nella SEQUENZA NUMERICA sono 0,1,2,3,4,5,6,7,8,9 e le stesse \n"
           " hanno CARATTERE RIPETITIVO, ovvero possono ripetersi nelle diverse posizioni \n\n"
           " ESEMPIO di SEQUENZE NUMERICHE : 1234 , 1221 , 0000 , 9999, etc \n\n"
           " Nel momento in cui il GIOCATORE inserisce la SEQUENZA NUMERICA da Lui ritenuta\n"
           " corretta, ottiene in risposta un FEEDBACK da parte del COMPUTER, ovvero:\n\n"
           "    -> il numero di CIFRE INDOVINATE nella GIUSTA POSIZIONE\n"
           "    -> il numero di CIFRE INDOVINATE ma in POSIZIONE ERRATA\n\n"
           " Il NUMERO MASSIMO di TENTATIVI a disposizione del GIOCATORE per indovinare la\n"
           " SEQUENZA NUMERICA e' 10; quindi se tale SEQUENZA viene indovinata entro i 10\n"
           " tentativi, il GIOCATORE e' il VINCITORE altrimenti il VINCITORE e' il COMPUTER\n\n"
           
           "                                                        Buon Divertimento!!!\n");
   system ("pause");
         
         /* FINE PRESENTAZIONE GIOCO */
    
         /* INIZIO SCELTA LIVELLO GIOCO */
  
   system ("cls");                 
   printf("\n                  ***** SCELTA LIVELLO di GIOCO *****\n"   
           "\n Il GIOCO prevede TRE livelli di DIFFICOLTA':\n"
           "\n\t [1] Livello BASE (SEQUENZA di 4 CIFRE da indovinare)\n"
           "\n\t [2] Livello AVANZATO (SEQUENZA di 6 CIFRE da indovinare)\n"
           "\n\t [3] Livello PROFESSIONALE (SEQUENZA di 8 CIFRE da indovinare)\n"
           "\n\n Inserisci 1 , 2 o 3 e premi (invio/enter) per scegliere il \n\n"
           " LIVELLO di GIOCO desiderato : ");
   fgets (livGioco, 3, stdin);                                                  // acquisizione 2 caratteri immessi da tastiera            
   fflush(stdin);                                                               // pulizia buffer standard input (tastiera)
      
   while ((livGioco[0] != '1' && livGioco[0] != '2' && livGioco[0] != '3') || (livGioco[1] != '\n'))  {
          system("cls");
          printf("\n\a        ***** ATTENZIONE - SCELTA LIVELLO di GIOCO ERRATA *****\n"
                 "\n Il GIOCO prevede TRE livelli di DIFFICOLTA':\n"
                 "\n\t [1] Livello BASE (SEQUENZA di 4 CIFRE da indovinare)\n"
                 "\n\t [2] Livello AVANZATO (SEQUENZA di 6 CIFRE da indovinare)\n"
                 "\n\t [3] Livello PROFESSIONALE (SEQUENZA di 8 CIFRE da indovinare)\n"
                 "\n\n Inserisci 1 , 2 o 3 e premi (invio/enter) per scegliere il \n\n"
                 " LIVELLO di GIOCO desiderato : ");
          fgets (livGioco, 3, stdin);                                           // acquisizione 2 caratteri immessi da tastiera
          fflush(stdin);                                                        // pulizia buffer standard input (tastiera)
   }      
         /* FINE SCELTA LIVELLO GIOCO */
             
         /* INIZIO EFFETTIVO GIOCO */
                 
   system("cls");
   if (livGioco[0] == '1') {
        numCifreSeqCorretta = 4;
        printf("\n\n                  ***** INIZIO del GIOCO - LIVELLO BASE *****\n");
   }
   else if (livGioco[0] == '2') {
        numCifreSeqCorretta = 6;
        printf("\n\n                ***** INIZIO del GIOCO - LIVELLO AVANZATO *****\n");
   }
   else if(livGioco[0] == '3') {
        numCifreSeqCorretta = 8;
        printf("\n\n              ***** INIZIO del GIOCO - LIVELLO PROFESSIONALE *****\n"); 
   }        
   
          /* INIZIO ALLOCAZIONE DINAMICA MEMORIA */   
   
   strSeqCorretta = (char*)malloc(numCifreSeqCorretta*sizeof(char));            // allocazione dinamica memoria (dimensione 4,6,8)
   strTentativoUtente = (char*)malloc((numCifreSeqCorretta+1)*sizeof(char));    // allocazione dinamica memoria (dimensione 5,7,9)
   cifraSeqCorretta = (int*)malloc(numCifreSeqCorretta*sizeof(int));            // allocazione dinamica memoria (dimensione 4,6,8)
   cifraTentativoUtente = (int*)malloc(numCifreSeqCorretta*sizeof(int));        // allocazione dinamica memoria (dimensione 4,6,8)
   
         /* FINE ALLOCAZIONE DINAMICA MEMORIA
         
         /* VERIFICA CORRETTA ALLOCAZIONE DINAMICA MEMORIA */                 
   
   if ((strSeqCorretta!=NULL)&&(strTentativoUtente!=NULL)&&(cifraSeqCorretta!=NULL)&&(cifraTentativoUtente!=NULL)) {
   
      srand(time(NULL));                                                        // inizializzazione generatore cifre/char pseudo-casuali
      for ( i = 0 ; i < numCifreSeqCorretta ; i++) {                               
         strSeqCorretta[i] = (char) (48 + rand() % 10);                         // generazione di una cifra/char ASCII tra '0' e '9'
         printf("%c", strSeqCorretta[i]);                                     // UTILITY PROGRAMMATORE 
      }
   
      while (cifrePosCorretta != numCifreSeqCorretta && tentativiRimasti != 0) {   // apertura  MACRO_WHILE
      
         cifrePosCorretta = 0;                                                  // re-inizializzazione var ad ogni nuovo tent.utente 
         cifrePosErrata = 0;                                                    // re-inizializzazione var ad ogni nuovo tent.utente
         cifraVietata = NON_USATA;                                              // re-inizializzazione var ad ogni nuovo tent.utente
                  
         printf("\n\n TENTATIVI a Disposizione : %d", tentativiRimasti);
         printf("  -  Numero CIFRE in SEQUENZA da Indovinare : %d", numCifreSeqCorretta);
         printf("\n\n Inserisci la SEQUENZA CORRETTA di %d CIFRE e premi (invio/enter) : ", numCifreSeqCorretta);
             
         fgets (strTentativoUtente, numCifreSeqCorretta + 2, stdin );           // acquisizione (5,7,9) caratteri immessi da utente 
         fflush(stdin);                                                         // pulizia buffer standard input (tastiera)
                                          
         
         /* INIZIO VERIFICA CORRETTO INSERIMENTO CIFRA/CHAR e SEQUENZA (come da REGOLAMENTO) */              
      
            for (i = 0 ; i < numCifreSeqCorretta ; i++ ) {
                               
               if ((strTentativoUtente[i] < '0') || (strTentativoUtente[i] > '9')) {                                                                 
               cifraVietata = USATA;                                            // "marcatura->utilizzata" cifra/char vietata da Regolamento
               break;                                                           // uscita ciclo FOR
               }
            }
                                         
         if ((strTentativoUtente[numCifreSeqCorretta] == '\n') && (cifraVietata == NON_USATA)) {   // apertura MEDIO_IF
      
         /* FINE VERIFICA CORRETTO INSERIMENTO CIFRA/CHAR e SEQUENZA (come da REGOLAMENTO) */           
         
         
         /* INIZIO CONTEGGIO CIFRE CORRETTE IN POSIZIONE CORRETTA */
                    
            for (i = 0 ; i < numCifreSeqCorretta ; i++) {                              
                                                                                
               if (strTentativoUtente[i] == strSeqCorretta[i]) {
                  cifrePosCorretta++;                                           // "conteggio+1" cifra corretta in posizione corretta
                  cifraSeqCorretta[i] = USATA;                                  // "marcatura->conteggiata" cifra/char i-esima seq.corretta 
                  cifraTentativoUtente[i] = USATA;                              // "marcatura->conteggiata" cifra/char i-esima tent.utente 
               }
               else {
                  cifraSeqCorretta[i] = NON_USATA;                              // "marcatura->non conteggiata" cifra/char i-esima seq.corretta  
                  cifraTentativoUtente[i] = NON_USATA;                          // "marcatura->non conteggiata" cifra/char i-esima tent.utente
               }
            }
            
         /* FINE CONTEGGIO CIFRE CORRETTE IN POSIZIONE CORRETTA */
                  
         /* INIZIO CONTEGGIO CIFRE CORRETTE IN POSIZIONE ERRATA */ 
                 
            for (i = 0 ; i < numCifreSeqCorretta ; i++) {                       // ciclo cifre/char "non conteggiate" tentativo utente 
                                                                                
               if (cifraTentativoUtente[i] == NON_USATA) {                      // verifico cifra/char i-esima -> non sia stata "conteggiata"
           
                  for (j = 0 ; j < numCifreSeqCorretta ; j++) {                 // ciclo cifre/char "non conteggiate" sequenza corretta 
               
                     if (strTentativoUtente[i] == strSeqCorretta[j] && cifraSeqCorretta[j] == NON_USATA) {
                        
                        cifrePosErrata++;                                       // "conteggio+1" cifra corretta in posizione errata
                        cifraSeqCorretta[j] = USATA;                            // "marcatura->conteggiata" cifra/char j-esima seq.corretta 
                        break;                                                  // uscita ciclo for interno (secondo ciclo)
                     }
                  }
               }
            }
            
         /* FINE CONTEGGIO CIFRE CORRETTE IN POSIZIONE ERRATA */ 
                            
      
            printf("\n\t\t  CIFRE CORRETTE in POSIZIONE CORRETTA : %d", cifrePosCorretta);    // stampa cifre/char corrette in posizione corretta
            printf("\n\n\t\t    CIFRE CORRETTE in POSIZIONE ERRATA : %d\n", cifrePosErrata);  // stampa cifre/char corrette in posizione errata
            tentativiRimasti--;
         }                                                                      // chiusura MEDIO_IF
         else {                                                                 // apertura ELSE alternativa a MEDIO_IF
            printf (" \n\n\a                         ******* ATTENZIONE ******* "
                 " \n\n        La SEQUENZA NUMERICA inserita NON RISPETTA le REGOLE del GIOCO\n");
            tentativiRimasti--;                               
         }                                                                      // chiusura ELSE alternativa a MEDIO_IF
      
      }                                                                         // chiusura MACRO_WHILE
   
   tentativiUtilizzati = TENTATIVI_STANDARD - tentativiRimasti;
      
   if (cifrePosCorretta == numCifreSeqCorretta) {
      printf("\n\n\n                      ***** Complimenti , HAI VINTO *****\n\n  "
             "                     -> hai indovinato in %d TENTATIVI\n\n\n\n", tentativiUtilizzati);
   }
   else if(cifrePosCorretta != numCifreSeqCorretta) {
      printf("\n\n\n                      ***** Mi Spiace , HAI PERSO *****\n\n  "
             "              --> La SEQUENZA NUMERICA da indovinare era : ");
      for ( i = 0 ; i < numCifreSeqCorretta ; i++) {
         printf("%c", strSeqCorretta[i]);
      }
      printf("\n\n\n\n");     
   }
      
   }                                                                            // chiusura IF Controllo Allocazione Dinamica Memoria   
          
          /* INIZIO AVVERTIMENTO ERRATA ALLOCAZIONE DINAMICA MEMORIA */ 
   
   else { 
      system("cls");
      printf ("\a\n\n\n\n\t                     **** ATTENZIONE ****"
              "\n\n\n\t                 PROBLEMA ALLOCAZIONE MEMORIA"
              "\n\n\n\t                     CONTATTARE ASSISTENZA \n\n\n\n\n\n\n\n\n\n");
   }             
   
          /* FINE AVVERTIMENTO ERRATA ALLOCAZIONE DINAMICA MEMORIA */
          
          /* FINE CONTROLLO CORRETTA ALLOCAZIONE DINAMICA MEMORIA */ 
          
   free(strSeqCorretta);                                                        // deallocazione memoria -> evitare problema memory leak
   free(strTentativoUtente);                                                    // deallocazione memoria -> evitare problema memory leak
   free(cifraSeqCorretta);                                                      // deallocazione memoria -> evitare problema memory leak
   free(cifraTentativoUtente);                                                  // deallocazione memoria -> evitare problema memory leak
   
   system("\PAUSE");
   return 0;
      
         /* FINE GIOCO */
                   
         /* FINE PARTE ESECUTIVA della funzione MAIN */
         
}        /* FINE funzione MAIN e PROGRAMMA*/          
         
