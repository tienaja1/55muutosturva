#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//asetetaan ääkköset ja öökköset
#include <locale.h>
//Tämä toimii visual studio codessa
#include <windows.h>
#include <time.h>

void otetaanpelaajannumero(int ruudukko[3][3]); 
void generoidaankoneennumerot(int ruudukko[3][3], bool *tyhjaatilaapointer);
int tarkistatulos(int ruudukko[3][3]); 

int main() {
    //määritellään muuttujat
    int ruudukko[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    bool tyhjaatilaa = false; 
    bool *tyhjaatilaapointer = &tyhjaatilaa; 


   srand(time(NULL));
    //ruudukossa 0 = "-"
    //           1 = "x"
    //           2 = "O"

    //piirretään tyhjä ruudukko. 
   for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
           printf("%d", ruudukko[i][j]);
        }
        printf("\n");
   }


   uusikierros: 
      otetaanpelaajannumero(ruudukko);

      if (tarkistatulos(ruudukko) == 1){
         printf("Onnea sina voitit!!!");
         //mennään loppuun
         goto loppu; 
      } 
       generoidaankoneennumerot(ruudukko, tyhjaatilaapointer);
    //tarkistetaan voittiko tietokone
       if (tarkistatulos(ruudukko)==2) {
           printf("Tietokone voitti!!!\n"); 
           goto loppu; 
       } 

       if ((tarkistatulos(ruudukko)==0)&&(*tyhjaatilaapointer==false)) {
           printf("Tasapeli!!!\n"); 
           goto loppu; 
       } 
       else {
           goto uusikierros;
       }
    //palataan loopin alkuun jossa kysytaan pelaajalta uusi arvo
    //goto uusikierros; 

    loppu: 
    printf("Game over!!! ");
    return 0; 
   }

void otetaanpelaajannumero(int ruudukko[3][3]){
    int x = 0; 
    int y = 0; 
    bool uusiarvo = false;
    bool oikeaformaatti = false;

        //tehdään looppi 
   while (uusiarvo==false) {          
       //otetaan numero sisään 
       printf("syota X ja Y positio arvo"); 
       //scanf("%d %d", &x, &y); 
       //printf("%d %d\n", x, y);
       //tarkistetaan onko syoton formaatti ok 
       if (scanf("%d %d", &x, &y) != 2) {
           int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Anna kaksi kokonaislukua.\n");
            continue;
           }
      
       if (x < 0 || x > 2 || y < 0 || y > 2) {
           printf("Luvun pitaa olla valilla 0-2.\n");
           continue;
           
       }

       //tsekataan onko kyseinen paikka tyhjä jos on uusiarvo lippu nostetaan ylös
       if (ruudukko[y][x]==0){
          uusiarvo = true;
          //ruudukko[y][x]=1;
       }
       else {
         uusiarvo = false; 
         printf("numerot on jo annettu kerran anna uudet arvot\n");
       } 
    
    }

   printf("###########################################\n");
    //mikäli uusi arvo lippiu on ylhäällä niin talletaan arvo taulukkoon
   if (uusiarvo == true){
         ruudukko[y][x]=1;
         //piirretään ruudukko uudelleen. 
         //ruudukko[x][y] = 1; 
        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){          
                if (ruudukko[i][j]==0){ 
                   printf("- ");
                 }
               else if (ruudukko[i][j]==1) {
                   printf ("X "); 
                 }
               else {
                    printf ("0 ");
               } 
               
             }
            printf("\n");
       }
        
   }
    //asetetaan uusi arvo lippu falseksi tietokoneen arvontaa varten. 
    uusiarvo = false;
    //tarkistetaan tulos oletko vielä voittanut


}

void generoidaankoneennumerot(int ruudukko[3][3], bool *tyhjaatilaapointer){

  //tarkistetaan onko taulukossa tyhjää tilaa 
   
   bool uusiarvo = false;
   *tyhjaatilaapointer = false; 
   int x = 0; 
   int y = 0; 
   for (int i = 0; i < 3; i++) {
       for (int j = 0; j < 3; j++) {
           if (ruudukko[i][j] == 0) {
                *tyhjaatilaapointer = true;    
                // ei koskaan takaisin false-arvoon
               }
         }
   }
   if (*tyhjaatilaapointer == false){      
        return;      
   }  
    //kone generoi satunnaisvastauksen   
    // jos uusi arvo on false ja tyhjaa tilaa lippu on true niin pyoritaan 
    //while loopissa niin kauan kun tietokone löytää tyhjän slotin.
   while ((uusiarvo==false)&&(*tyhjaatilaapointer==true)) { 
       x = rand() % 3;
       y = rand() % 3;

        Sleep(5);
      //jos tyhja sloti löytyy niin nostetaan uusi arvo lippu ylos
      // ja poistutaan loopista. 
      if (ruudukko[y][x]==0){
         uusiarvo = true;
         }
      //jos ei loydy niin pysytaan loopissa   
      else {
             uusiarvo = false;
         }
      } 


    printf("############################\n");
   //kun tyhja sloti on loytynyt siihen laitetaan arvo
   if (uusiarvo == true){
       ruudukko[y][x]=2;

   //piirretään ruudukko uudelleen. 

   for (int i=0; i<3; i++){
       for (int j=0; j<3; j++){
             
            if (ruudukko[i][j]==0){ 
                 printf("- ");
              }
              else if (ruudukko[i][j]==1) {
                 printf ("X "); 
              }
              else {
                 printf ("0 ");
              } 
           }
           //asetetaan uusi arvo lippu falseksi
           uusiarvo = false; 
           printf("\n");
            
    }      
   }  
}


int tarkistatulos(int ruudukko[3][3]){ 
       // vaakarivit tasan 
    if (((ruudukko [0][0])==1 && (ruudukko [0][1])==1 && (ruudukko [0][2])==1)||
    ((ruudukko [1][0])==1 && (ruudukko [1][1])==1 && (ruudukko [1][2])==1)||
    ((ruudukko [2][0])==1 && (ruudukko [2][1])==1 && (ruudukko [2][2])==1)||
    //pystyrivit tasan
    ((ruudukko [0][0])==1 && (ruudukko [1][0])==1 && (ruudukko [2][0])==1)||
    ((ruudukko [0][1])==1 && (ruudukko [1][1])==1 && (ruudukko [2][1])==1)||
    ((ruudukko [0][2])==1 && (ruudukko [1][2])==1 && (ruudukko [2][2])==1)||
    //poikittain molempiin suuntiin tasan. 
    ((ruudukko [0][0])==1 && (ruudukko [1][1])==1 && (ruudukko [2][2])==1)||
    ((ruudukko [2][0])==1 && (ruudukko [1][1])==1 && (ruudukko [0][2])==1))
    {
    return 1;
    }

    else if (((ruudukko [0][0])==2 && (ruudukko [0][1])==2 && (ruudukko [0][2])==2)||
    ((ruudukko [1][0])==2 && (ruudukko [1][1])==2 && (ruudukko [1][2])==2)||
    ((ruudukko [2][0])==2 && (ruudukko [2][1])==2 && (ruudukko [2][2])==2)||
    //pystyrivit tasan
    ((ruudukko [0][0])==2 && (ruudukko [1][0])==2 && (ruudukko [2][0])==2)||
    ((ruudukko [0][1])==2 && (ruudukko [1][1])==2 && (ruudukko [2][1])==2)||
    ((ruudukko [0][2])==2 && (ruudukko [1][2])==2 && (ruudukko [2][2])==2)||
    //poikittain molempiin suuntiin tasan. 
    ((ruudukko [0][0])==2 && (ruudukko [1][1])==2 && (ruudukko [2][2])==2)||
    ((ruudukko [2][0])==2 && (ruudukko [1][1])==2 && (ruudukko [0][2])==2))
    { 
    return 2;
    }
    else {
      return 0; 
    }
}



