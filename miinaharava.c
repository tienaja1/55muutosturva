#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//asetetaan ääkköset ja öökköset
#include <locale.h>
//Tämä toimii visual studio codessa
#include <windows.h>
#include <time.h>

//funktio miinakentän piirtämistä varten
void piirretaan_miinakentta(int miinakentta[9][9]){

    printf("Miinakentta\n");  

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){          
            if (miinakentta[i][j]==0){ 
               printf("- ");
                }
            else if (miinakentta[i][j]==1) {
                   printf ("M "); 
                 }                                                                                 
             }
            printf("\n");
    }           
}

//piirretään dummy miinakenttä
void piirretaan_dummy(int dummy[9][9]){

    printf("Olet jo etsinyt taalta\n");  

    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){          
            if (dummy[i][j]==0){ 
               printf("- ");
                }
            else if (dummy[i][j]==1) {
                   printf ("X "); 
                 }                                                                                 
             }
            printf("\n");
    }           
}

//functio sisemmän piirin miinojen tutkimista varten 
int tsekataanymparisto(int miinakentta[9][9], int x, int y){
    int miinamaara= 0; 

    if ((x == 8)) {
       for (int i=x-1; i < x+1; i++){
           if (y == 8){
              for (int j=y-1; j < y+1; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     miinamaara++; 
                     }
                  }
              }    
           else if (y == 0){
              for (int j=y; j < y+2; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     miinamaara++; 
                     }
                  } 
             }
             else {
                 for (int j=y-1; j < y+2; j++){
                     if (miinakentta[j][i] == 1) 
                        {
                        miinamaara++; 
                        }
                  } 
             }       
           }  
       }

    else if ((x == 0)) {
       for (int i=x; i < x+2; i++){
           if (y == 8){
              for (int j=y-1; j < y+1; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     miinamaara++; 
                     }
                  }
              }    
           else if (y == 0){
              for (int j=y; j < y+2; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     miinamaara++; 
                     }
                  } 
             }
             else {
                 for (int j=y-1; j < y+2; j++){
                     if (miinakentta[j][i] == 1) 
                        {
                        miinamaara++; 
                        }
                  } 
             }       
           }  
       }   

    else {
       for (int i=x-1; i < x+2; i++){
           if (y == 8){
              for (int j=y-1; j < y+1; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     miinamaara++; 
                     }
                  }
              }    
           else if (y == 0){
              for (int j=y; j < y+2; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     miinamaara++; 
                     }
                  } 
             }
             else {
                 for (int j=y-1; j < y+2; j++){
                     if (miinakentta[j][i] == 1) 
                        {
                        miinamaara++; 
                        }
                  } 
             }       
           }  
        }         

    return miinamaara;                 
}

//funktio ulomman piirin miinojen etsimistä varten
int tsekataanulompiymparisto(int miinakentta[9][9], int x, int y){
    int ulompimiinamaara= 0;
    int v = 8-x; 
    int z = 8-y; 
    int s = 0+x;
    int r = 0+y; 
    if ((x >= 7)) {
       for (int i=x-2; i < x+1+v; i++){
           if (y >= 7){
              for (int j=y-2; j < y+1+z; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     ulompimiinamaara++; 
                     }
                  }
              }    
           else if (y <= 1){
              for (int j=y-r; j < y+3; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     ulompimiinamaara++; 
                     }
                  } 
             }
           else {
                 for (int j=y-2; j < y+3; j++){
                     if (miinakentta[j][i] == 1) 
                        {
                        ulompimiinamaara++; 
                        }
                  } 
             }       
           }  
       }

    else if ((x <= 1)) {
       for (int i=x-s; i < x+3; i++){
           if (y >= 7){
              for (int j=y-2; j < y+1+z; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     ulompimiinamaara++; 
                     }
                  }
              }    
           else if (y <= 1){
              for (int j=y-r; j < y+3; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     ulompimiinamaara++; 
                     }
                  } 
             }
           else {
                 for (int j=y-2; j < y+3; j++){
                     if (miinakentta[j][i] == 1) 
                        {
                        ulompimiinamaara++; 
                        }
                  } 
             }       
           }  
       }   

    else {
       for (int i=x-2; i < x+3; i++){
           if (y >= 7){
              for (int j=y-2; j < y+1+z; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     ulompimiinamaara++; 
                     }
                  }
              }    
           else if (y <= 1){
              for (int j=y-r; j < y+3; j++){
                  if (miinakentta[j][i] == 1) 
                     {
                     ulompimiinamaara++; 
                     }
                  } 
             }
             else {
                 for (int j=y-2; j < y+3; j++){
                     if (miinakentta[j][i] == 1) 
                        {
                        ulompimiinamaara++; 
                        }
                  } 
             }       
           }  
        }         

    return ulompimiinamaara;                               
}


int main(){
//määritellään muuttujat    
int miinakentta[9][9] = {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}}; 
int tarkistuskentta[9][9] = {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
int dummy[9][9] = {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};  
int x = 0;
int y = 0;
int etsinnat = 0; 

srand(time(NULL));

piirretaan_miinakentta(miinakentta);

//piirretään satunnaisesti 10 miinaa

for (int s = 0; s<10; s++){

   do {
       x = rand() % 9;
       y = rand() % 9;    
     
   } while (tarkistuskentta[y][x]!=0);  
   miinakentta[y][x]=1;
   tarkistuskentta[y][x]=1;

}

piirretaan_miinakentta(miinakentta);

//etsitään tyhjiä ruutuja miinakentästä  
//otetaan aikaleima talteen
time_t alku = time(NULL);     
etsimiina:
printf("anna koordinaatit mista haluat etsia miinaa\n");
// formaatin tarkistus ja tarkistus että ollaan oikeassa arvoalueessa
if (scanf("%d %d", &x, &y) != 2) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Anna kaksi kokonaislukua.\n"); 
    goto etsimiina;   
    }
      
if (x < 0 || x > 8 || y < 0 || y > 8) {
    printf("Luvun pitaa olla valilla 0-8.\n");  
    goto etsimiina;           
    }
if (dummy[y][x]!=0){ 
   printf("olet jo ampunut tahan. anna uudet koordinaatit mihin haluat ampua\n");
   goto etsimiina;
}

else {
    dummy[y][x]=1;
} 

//Tarkistetaan tulos 

//miina osuma pelaaja hävis 
if  ((miinakentta[y][x])==1){
     printf("Miina rajahti\n");
     miinakentta[y][x]=0;
     goto loppu; 

}

//tyhjä ruutu 
else{
    printf("Ei miinaa! \n");
    //tutkitaan sisempi ympyrä
    if (tsekataanymparisto(miinakentta, x, y)==0){
        printf("ei miinoja sisemmalla kehalla!\n");
        //tutkitaan ulompi ympyrä jos sisemmältä ei löytynyt miinoja
        if (tsekataanulompiymparisto(miinakentta, x, y)==0){
            printf("ei miinoja ulommalla kehalla!\n"); 
        }    
        else {
            printf("miinoja ulommalla kehalla: %d\n", tsekataanulompiymparisto(miinakentta, x, y));
        }    

    }
    else{
        printf("miinoja sisemmalla kehalla: %d\n", tsekataanymparisto(miinakentta, x, y));
    }
    //kerrotaan pelaajalle mihin ollaan jo ammuttu.
    piirretaan_dummy(dummy);
    //päivitetään etsintäkierrosten lukumäärä
    etsinnat++;
    //ruutuja on 9x9 = 81 ja siitä pois 10 miinaa = 71 vapaata ruutua.
    //jos kaikki 71 ruutua on merkattu pelaaja voittaa
    if (etsinnat == 71){
        printf("Onnea!! Merkitsit kaikki miinattomat kohdat\n");
        goto loppu;
        
    }
    else
       goto etsimiina; 
}

loppu:
//otetaan aikaleima talteen
time_t loppu = time(NULL);
//lasketaan alun ja lopun aikaleimojen erotus
double peliinkulutettuaika = difftime(loppu, alku);
//ilmoitetaan peliin käytetty aika sekunteina
printf("Peliin kului %.0f sekuntia\n", peliinkulutettuaika);

printf("\n");
printf("Game over!!");

}
