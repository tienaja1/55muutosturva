#include <stdio.h>
#include <string.h> // Vaaditaan strlen-funktiota varten
#include <stdlib.h>
#include <stdbool.h>
//asetetaan ääkköset ja öökköset
#include <locale.h>
//Tämä toimii visual studio codessa
#include <windows.h>
#include <time.h>

void piirrahirttopuu(int vaaravastaus);

int main() {
    // Taulukko, jossa jokainen solu on osoitin merkkijonoon
    char *nimet[] = {"jorma", "liisa", "irmeli", "kalevi", "esko", "vesa", "annikki", "ari", "seppo", "jussi"};
    int vaaravastaus = 0;
     
    //char *arr[]  = NULL;  
    srand(time(NULL));

    int x = rand() % 10;
    //printf("%s ")
    // Syntaksi ensimmäisen solun (indeksi 0, eli "Jorma") pituuden laskemiseen:
    int pituus = strlen(nimet[x]);

    //for (int i =0; i < pituus; i++){
    //    printf("_");
    //}
    //printf("\n");    
    
    //printf("Nimen %s pituus on %d kirjainta.\n", nimet[x], pituus); // Tulostaa 5

    //for (int i = 0; i < 10; i++) {
    for (int j=0; j < strlen(nimet[x]); j++) {
        //printf("%c ", arr[i][j]);
        printf("%c ", nimet[x][j]);    
    }
    printf("\n");
    //}

    char *nimi = malloc(pituus+1);
    if (nimi == NULL) {
      printf("Muistin varaus epaonnistui\n");
      return 1;
    }
    

    char *dummy = malloc(pituus+1);
    if (dummy == NULL) {
      printf("Muistin varaus epaonnistui\n");
      return 1;
    }

    strcpy(nimi, nimet[x]);

    //for (int i=0; i<pituus; i++){
    //    dummy[i] = '_'; 
    //}
    memset(dummy, '_', pituus);
    dummy[pituus] = '\0';

    char y; 

    //for (int i =0; i < pituus; i++){
    //    printf("_\n");
    //} 
    bool voitto = false; 
    bool oikein = false;
    while ((vaaravastaus<10)&&(voitto==false)){
      printf("arvaa kirjain nimesta\n");
      for (int i =0; i < pituus; i++){
           printf("%c ",dummy[i]);}
      printf("\n");

      scanf(" %c", &y); 
      oikein = false; 

      for (int i =0; i < pituus; i++){
          if (y == nimi[i]){
             dummy[i] = y;
             oikein = true; 
          }          
        }

      if (oikein == false){
         vaaravastaus++;
         printf("%d\n", vaaravastaus);
         piirrahirttopuu(vaaravastaus);
      }  
      /*for (int p =0; p < pituus; p++){
            printf("%c ", dummy[p]);
          }
      printf("\n");*/
      voitto = true;    
      for (int l =0; l < pituus; l++){
              if (dummy[l]=='_'){
                 voitto = false; 
                 break;
              } 
          } 
      if (voitto==true){
             printf("Onnea sinä voitit!! Game over\n");
             }  
    }

    if (voitto==false){
        printf("Tietokone voitti!! Game over\n");
    }
    free(nimi);
    free(dummy);




    return 0;
    

}

void piirrahirttopuu(int vaaravastaus){
    if (vaaravastaus == 1){
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("                                           \n");
        printf("___________________________________________\n");
    }

     else if (vaaravastaus == 2){
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

    else if (vaaravastaus == 3){
        printf("                          _________________ \n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

    else if (vaaravastaus == 4){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }


    else if (vaaravastaus == 5){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                          |                |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

        else if (vaaravastaus == 6){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                          |                |\n");
        printf("                          O                |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

    else if (vaaravastaus == 7){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                          |                |\n");
        printf("                          O                |\n");
        printf("                         /|\\               |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

        else if (vaaravastaus == 8){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                          |                |\n");
        printf("                          O                |\n");
        printf("                         /|\\               |\n");
        printf("                          |                |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

    else if (vaaravastaus == 9){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                          |                |\n");
        printf("                          O                |\n");
        printf("                         /|\\               |\n");
        printf("                          |                |\n");
        printf("                           \\               |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }

    else if (vaaravastaus == 10){
        printf("                          _________________ \n");
        printf("                          |                |\n");
        printf("                          |                |\n");
        printf("                          O                |\n");
        printf("                         /|\\               |\n");
        printf("                          |                |\n");
        printf("                         / \\               |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("                                           |\n");
        printf("___________________________________________\n");
    }
}