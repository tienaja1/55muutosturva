#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//asetetaan ääkköset ja öökköset
#include <locale.h>
//Tämä toimii visual studio codessa
#include <windows.h>
#include <time.h>

//functio pelaajan meren piirtämiseksi
void piirretaan_omameri(int omameri[10][10]){

    printf("Oma meri\n");  

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){          
            if (omameri[i][j]==0){ 
               printf("- ");
                }
            else if (omameri[i][j]==1) {
                   printf ("S "); 
                 }
            else if (omameri[i][j]==2) {
                   printf ("H "); 
                 }  
            else if (omameri[i][j]==3) {
                   printf ("R "); 
                 } 
            else if (omameri[i][j]==4) {
                   printf ("L "); 
                 }                                                                                 
             }
            printf("\n");
    }           
}

//functio vihollisen meren piirtämiseksi
void piirretaan_vihollisenmeri(int vihollisenmeri[10][10]){

    printf("Vihollisen meri\n");  

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){          
            if (vihollisenmeri[i][j]==0){ 
               printf("- ");
                }
            else if (vihollisenmeri[i][j]==1) {
                   printf ("S "); 
                 }
            else if (vihollisenmeri[i][j]==2) {
                   printf ("H "); 
                 }  
            else if (vihollisenmeri[i][j]==3) {
                   printf ("R "); 
                 } 
            else if (vihollisenmeri[i][j]==4) {
                   printf ("L "); 
                 }                                                                                 
             }
            printf("\n");
    }           
}


//functio oman turvaalueen piirtämiseksi
void piirretaan_oma_turvaalue(int turvaalueoma[10][10]){
    printf("Oma Turvaalue\n");

    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){          
            if (turvaalueoma[i][j]==0){ 
               printf("- ");
                }
            else if (turvaalueoma[i][j]==5) {
                   printf ("T ");
                }    
            else if (turvaalueoma[i][j]==6) {
                   printf ("Y ");
                } 
            else if (turvaalueoma[i][j]==7) {
                   printf ("B ");
                } 
            else if (turvaalueoma[i][j]==8) {
                   printf ("W ");
                }                                                   
            }
        printf("\n");    
    }
     

}

//functio vihollisen turvaalueen piirtämiseksi
void piirretaan_vihollisen_turvaalue(int turvaalue[10][10]){
    printf("Vihollisen Turvaalue\n");
 
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){          
            if (turvaalue[i][j]==0){ 
               printf("- ");
                }
            else if (turvaalue[i][j]==5) {
                   printf ("T ");
                }    
            else if (turvaalue[i][j]==6) {
                   printf ("Y ");
                } 
            else if (turvaalue[i][j]==7) {
                   printf ("B ");
                } 
            else if (turvaalue[i][j]==8) {
                   printf ("W ");
                }                                                   
            }
        printf("\n");    
    }
     

}
//functio joka tarkistaa onko vihollismeressä vielä ammuttavaa
int tarkistetaan_vihollisenmeri(int vihollisenmeri[10][10], bool vihollisenmerityhja){
    vihollisenmerityhja = true;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){          
            if (vihollisenmeri[i][j]!=0){ 
                vihollisenmerityhja = false; 
            }
        }
    }
    return vihollisenmerityhja;  

}
//functio joka tarkistaa onko omassa meressä vielä ammuttavaa
int tarkistetaan_omameri(int omameri[10][10], bool omamerityhja){
    omamerityhja = true;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){          
            if (omameri[i][j]!=0){ 
                omamerityhja = false; 
            }
        }
    }
    return omamerityhja;  

}


int main(){

//gneroidaan 10 * 10 taulukko
int omameri[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}}; 
int vihollisenmeri[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}}; 
int dummy[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}}; 
int turvaalue[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}}; 
int dummyoma[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}}; 
int turvaalueoma[10][10] = {{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0}}; 
int x = 0;
int y = 0; 
int z = 0;
int v = 0; 
int g = 0; 
int h = 0; 
int k = 0;
int l = 0; 
int r = 0; 
bool omamerityhja = true; 
bool vihollisenmerityhja = true; 

srand(time(NULL));



piirretaan_omameri(omameri);

piirretaan_vihollisenmeri(vihollisenmeri);


//piirretään lentotukialus 
printf("piirra lentotukialus antamalla x ja y ja seka r arvo haluatko venen poikittain tai pitkittain\n");
piirra3:
//scanf("%d %d %d", &x, &y, &r); 
if (scanf("%d %d %d", &x, &y, &r) != 3) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Anna kolme kokonaislukua.\n");
    goto piirra3;
    }
      
if (x < 0 || x > 6 || y < 0 || y > 6|| r < 0 || r > 1) {
    printf("x ja y luvun pitaa olla valilla 0-6 ja r luvun valilla 0-1.\n");
    goto piirra3;           
    }

printf("%d %d %d\n", x, y, r);


if (r == 0){
   z = x;
   v = y+1;
   h = x;
   g = y+2;
   k = x;
   l = y+3;
}

else if (r == 1){
   z = x+1;
   v = y;
   h = x+2;
   g = y; 
   k = x+3;
   l = y;
}

if ((turvaalueoma[y][x]!=0)||(turvaalueoma[v][z]!=0)||(turvaalueoma[g][h]!=0)||(turvaalueoma[l][k]!=0)){
   printf("Tama menee toisen aluksenkanssa paallekkain tai liian lahelle anna uudet koordinaatit\n");
   goto piirra3;
}

omameri[y][x]=4;
omameri[v][z]=4;
omameri[g][h]=4;
omameri[l][k]=4;

//piirretään ruudukko uudelleen. 


piirretaan_omameri(omameri);

//piirretään turvaalue 
    
                
if (r == 0){   

    if (x == 9){     
        for (int i=x-1; i < x+1; i++){
            if (y == 6){
                for (int j=y-1; j < y+4; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+5; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }    
            else {
                for (int j=y-1; j < y+5; j++){
                     (turvaalueoma[j][i] = 5);
                }    
            }
        }
    }
    else if (x == 0){     
        for (int i=x; i < x+2; i++){
            if (y == 6){
                for (int j=y-1; j < y+4; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+5; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else {
                for (int j=y-1; j < y+5; j++){
                     (turvaalueoma[j][i] = 5);
                }    
            }
      }
    }  

    else {
        for (int i=x-1; i < x+2; i++){
            if (y == 6){
                for (int j=y-1; j < y+4; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+5; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else {
                for (int j=y-1; j < y+5; j++){
                     (turvaalueoma[j][i] = 5);
                }    
            }
      }
    }
}

else if (r==1)   {   
    if (x == 6){     
        for (int i=x-1; i < x+4; i++){
            if (y == 9){
                for (int j=y-1; j < y+1; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+2; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }    
            else {
                for (int j=y-1; j < y+2; j++){
                     (turvaalueoma[j][i] = 5);
                }    
            }
        }
    }
    else if (x == 0){     
        for (int i=x; i < x+5; i++){
            if (y == 9){
                for (int j=y-1; j < y+1; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+2; j++){
                     (turvaalueoma[j][i] = 5);
                }
            }
            else {
                for (int j=y-1; j < y+2; j++){
                     (turvaalueoma[j][i] = 5);
                }    
            }
      }
    }  

   else {
          for (int i=x-1; i < x+5; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalueoma[j][i] = 5);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 5);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalueoma[j][i] = 5);
              }
           }
          }
    }
}


piirretaan_oma_turvaalue(turvaalueoma); 


//piirretään 2 risteilijää   

for (int s=0; s<2; s++){

   printf("piirra ristelija antamalla x ja y ja seka r arvo haluatko venen poikittain tai pitkittain\n");
   piirra2:
   //scanf("%d %d %d", &x, &y, &r);
   if (scanf("%d %d %d", &x, &y, &r) != 3) {
       int c;
       while ((c = getchar()) != '\n' && c != EOF) {}
       printf("Anna kolme kokonaislukua.\n");
       goto piirra2;
        }
      
   if (x < 0 || x > 7 || y < 0 || y > 7|| r < 0 || r > 1) {
    printf("x ja y luvun pitaa olla valilla 0-7 ja r luvun valilla 0-1.\n");
    goto piirra2;           
    }

   printf("%d %d %d\n", x, y, r);

   if (r == 0){
      z = x;
      v = y+1;
      h = x;
      g = y+2; 
   }
   else if (r == 1){
      z = x+1;
      v = y;
      h = x+2;
      g = y; 
   }

   if ((turvaalueoma[y][x]!=0)||(turvaalueoma[v][z]!=0)||(turvaalueoma[g][h]!=0)){
      printf("Tama menee toisen aluksenkanssa paallekkain tai liian lahelle anna uudet koordinaatit\n");
      goto piirra2;
   }

   else {
      omameri[y][x]=3;
      omameri[v][z]=3;
      omameri[g][h]=3;
   }


    
   piirretaan_omameri(omameri);

    /// piirretään turvaalue    
    
   if (r == 0){   
   
       if (x == 9){     
           for (int i=x-1; i < x+1; i++){
               if (y == 7){
                   for (int j=y-1; j < y+3; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+4; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }    
               else {
                   for (int j=y-1; j < y+4; j++){
                        (turvaalueoma[j][i] = 6);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+2; i++){
               if (y == 7){
                   for (int j=y-1; j < y+3; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+4; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }
               else {
                   for (int j=y-1; j < y+4; j++){
                        (turvaalueoma[j][i] = 6);
                   }    
               }
         }
       }  

       else {
          for (int i=x-1; i < x+2; i++){
              for (int j=y-1; j < y+4; j++){
               (turvaalueoma[j][i] = 6);
              }
           }
       }
       }

   else if (r==1)   {   
       if (x == 7){     
           for (int i=x-1; i < x+3; i++){
               if (y == 9){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }    
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 6);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+4; i++){
               if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                     (turvaalueoma[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 6);
                   }    
                }
         }
       }  

        else {
          for (int i=x-1; i < x+4; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 6);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalueoma[j][i] = 6);
              }
           }
          }
       }
   }
   
   piirretaan_oma_turvaalue(turvaalueoma); 

}

//piirretään 3 hävittäjää

for (int s=0; s<3; s++){
   printf("piirra havittaja antamalla x ja y ja seka r arvo haluatko venen poikittain tai pitkittain\n");
   piirra1:
   if (scanf("%d %d %d", &x, &y, &r) != 3) {
       int c;
       while ((c = getchar()) != '\n' && c != EOF) {}
       printf("Anna kolme kokonaislukua.\n");
       goto piirra1;;
        }
      
   if (x < 0 || x > 8 || y < 0 || y > 8|| r < 0 || r > 1) {
    printf("x ja y luvun pitaa olla valilla 0-8 ja r luvun valilla 0-1.\n");
    goto piirra1;           
    }

   printf("%d %d\n", x, y);
   if (r == 0){
      z = x;
      v = y+1;
   }
   else if (r == 1){
      z = x+1;
      v = y;
   }

   if ((turvaalueoma[y][x]!=0)||(turvaalueoma[v][z]!=0)){
      printf("Tama menee toisen aluksenkanssa paallekkain tai liian lahelle anna uudet koordinaatit\n");
      goto piirra1;
   }
   else {
       omameri[y][x]=2;
       omameri[v][z]=2;
   } 
   
   
    piirretaan_omameri(omameri);
       
    
    //piirretään turvaalue             
   if (r == 0){   
  
       if (x == 9){     
           for (int i=x-1; i < x+1; i++){
               if (y == 8){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+3; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }    
               else {
                   for (int j=y-1; j < y+3; j++){
                        (turvaalueoma[j][i] = 7);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+2; i++){
               if (y == 8){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+3; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else {
                   for (int j=y-1; j < y+3; j++){
                        (turvaalueoma[j][i] = 7);
                   }    
               }
         }
       }  

       else {
           for (int i=x-1; i < x+2; i++){
               if (y == 8){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+3; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else {
                   for (int j=y-1; j < y+3; j++){
                        (turvaalueoma[j][i] = 7);
                   }    
               }
         }
       }  
   }

   else if (r==1)   {   
       if (x == 8){     
           for (int i=x-1; i < x+2; i++){
               if (y == 9){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }    
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+3; i++){
               if (y == 9){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }    
               }
         }
       }  

      else {
          for (int i=x-1; i < x+3; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 7);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalueoma[j][i] = 7);
              }
           }
          }
       }
    }

   piirretaan_oma_turvaalue(turvaalueoma); 
}  

// piirretään 4 sukellusvenettä

for (int s=0; s < 4; s++){

   printf("piirra sukellusvene antamalla x ja y arvo\n");
   piirra0:
   //scanf("%d %d", &x, &y); 
   if (scanf("%d %d", &x, &y) != 2) {
       int c;
       while ((c = getchar()) != '\n' && c != EOF) {}
       printf("Anna kaksi kokonaislukua.\n");
       goto piirra0;;
        }
      
   if (x < 0 || x > 9 || y < 0 || y > 9) {
    printf("Luvun pitaa olla valilla 0-9.\n");
    goto piirra0;           
    }

   printf("%d %d\n", x, y);
   if ((turvaalueoma[y][x]!=0)){
      printf("Tama menee toisen aluksenkanssa paallekkain tai liian lahelle anna uudet koordinaatit\n");
      goto piirra0;
    }
   else {
       omameri[y][x]=1;
   } 
   
   omameri[y][x]=1;


   piirretaan_omameri(omameri);   
    
       //piirretään turvaalue
       if (x == 9){     
           for (int i=x-1; i < x+1; i++){
               if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalueoma[j][i] = 8);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 8);
                   }
               }    
               else {
                  for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 8);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+2; i++){
               if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalueoma[j][i] = 8);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 8);
                   }
               }
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalueoma[j][i] = 8);
                   }    
               }
         }
       }  

       else {
          for (int i=x-1; i < x+2; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalueoma[j][i] = 8);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalueoma[j][i] = 8);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalueoma[j][i] = 8);
              }
           }
          }
       }


   piirretaan_oma_turvaalue(turvaalueoma); 
   

    }

//piirretään satunnaisesti vihollisen lentotukialus

x = rand() % 7;
y = rand() % 7;
r = rand() % 2; 

if (r == 0){
   z = x;
   v = y+1;
   h = x;
   g = y+2; 
   k = x;
   l = y+3;
}
else if (r == 1){
   z = x+1;
   v = y;
   h = x+2;
   g = y; 
   k = x+3;
   l = y;
}

vihollisenmeri[y][x]=4;
vihollisenmeri[v][z]=4;
vihollisenmeri[g][h]=4;
vihollisenmeri[l][k]=4;


piirretaan_vihollisenmeri(vihollisenmeri);    
/////////////////////////////////////////////////////////
///testi 

//for (int i=0; i<10; i++){
//    for (int j=0; j<10; j++){
//        turvaalue[i][j] = 0;
//    }
//}

//////////////////////////////////////////////////
//piirretään turvaalue 
    
                
if (r == 0){   
//piirretään turvaalue
    if (x == 9){     
        for (int i=x-1; i < x+1; i++){
            if (y == 6){
                for (int j=y-1; j < y+4; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+5; j++){
                     (turvaalue[j][i] = 5);
                }
            }    
            else {
                for (int j=y-1; j < y+5; j++){
                     (turvaalue[j][i] = 5);
                }    
            }
        }
    }
    else if (x == 0){     
        for (int i=x; i < x+2; i++){
            if (y == 6){
                for (int j=y-1; j < y+4; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+5; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else {
                for (int j=y-1; j < y+5; j++){
                     (turvaalue[j][i] = 5);
                }    
            }
      }
    }  

    else {
        for (int i=x-1; i < x+2; i++){
            if (y == 6){
                for (int j=y-1; j < y+4; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+5; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else {
                for (int j=y-1; j < y+5; j++){
                     (turvaalue[j][i] = 5);
                }    
            }
      }
    }
}
else if (r==1)   {   
    if (x == 6){     
        for (int i=x-1; i < x+4; i++){
            if (y == 9){
                for (int j=y-1; j < y+1; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+2; j++){
                     (turvaalue[j][i] = 5);
                }
            }    
            else {
                for (int j=y-1; j < y+2; j++){
                     (turvaalue[j][i] = 5);
                }    
            }
        }
    }
    else if (x == 0){     
        for (int i=x; i < x+5; i++){
            if (y == 9){
                for (int j=y-1; j < y+1; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else if (y == 0){
                for (int j=y; j < y+2; j++){
                     (turvaalue[j][i] = 5);
                }
            }
            else {
                for (int j=y-1; j < y+2; j++){
                     (turvaalue[j][i] = 5);
                }    
            }
      }
    }  

    else {
          for (int i=x-1; i < x+5; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 5);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 5);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalue[j][i] = 5);
              }
           }
          }
    }
}   

 

piirretaan_vihollisen_turvaalue(turvaalue);    

 

//piirretään satunnaisesti 2 risteilijaa

for (int s=0; s<2; s++){

   do  {

     x = rand() % 8;
     y = rand() % 8;
     r = rand() % 2; 

     if (r == 0){
        z = x;
        v = y+1;
        h = x;
        g = y+2; 
     }
     else if (r == 1){
        z = x+1;
        v = y;
        h = x+2;
        g = y; 
     }


   } while ((turvaalue[y][x]!=0)||(turvaalue[v][z]!=0)||(turvaalue[g][h]!=0));

   vihollisenmeri[y][x]=3;
   vihollisenmeri[v][z]=3;
   vihollisenmeri[g][h]=3;

   piirretaan_vihollisenmeri(vihollisenmeri);
    
    //piirretään turvaalue            
   if (r == 0){   
   
       if (x == 9){     
           for (int i=x-1; i < x+1; i++){
               if (y == 7){
                   for (int j=y-1; j < y+3; j++){
                        (turvaalue[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+4; j++){
                        (turvaalue[j][i] = 6);
                   }
               }    
               else {
                   for (int j=y-1; j < y+4; j++){
                        (turvaalue[j][i] = 6);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+2; i++){
               if (y == 7){
                   for (int j=y-1; j < y+3; j++){
                        (turvaalue[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+4; j++){
                        (turvaalue[j][i] = 6);
                   }
               }
               else {
                   for (int j=y-1; j < y+4; j++){
                        (turvaalue[j][i] = 6);
                   }    
               }
        }
       }  

       else {
          for (int i=x-1; i < x+2; i++){
              for (int j=y-1; j < y+4; j++){
               (turvaalue[j][i] = 6);
              }
           }
       }
       }

   else if (r==1)   {   
       if (x == 7){     
           for (int i=x-1; i < x+3; i++){
               if (y == 9){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 6);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 6);
                   }
               }    
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 6);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+4; i++){
               if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 6);
                   }
              }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 6);
                   }
               }
               else {
                   for (int j=y-1; j < y+2; j++){
                     (turvaalue[j][i] = 6);
                   }    
               }
         }
       }  

        else {
          for (int i=x-1; i < x+4; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 6);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 6);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalue[j][i] = 6);
              }
           }
          }
       }
     }   


   printf("x = %d, y = %d, r = %d\n", x, y, r);
   
   piirretaan_vihollisen_turvaalue(turvaalue);
}   



//piirretään satunnaisesti 3 hävittäjää

for (int s=0; s<3; s++){    

   do {
     x = rand() % 9;
     y = rand() % 9;
     r = rand() % 2; 

     if (r == 0){
        z = x;
        v = y+1;
     }
     else if (r == 1){
        z = x+1;
        v = y;
     }
   } while ((turvaalue[y][x]!=0)||(turvaalue[v][z]!=0));  
   vihollisenmeri[y][x]=2;
   vihollisenmeri[v][z]=2;

  
   piirretaan_vihollisenmeri(vihollisenmeri);
   
   //piirretään turvaalue
   if (r == 0){   
   
       if (x == 9){     
           for (int i=x-1; i < x+1; i++){
               if (y == 8){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+3; j++){
                        (turvaalue[j][i] = 7);
                   }
               }    
               else {
                   for (int j=y-1; j < y+3; j++){
                        (turvaalue[j][i] = 7);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+2; i++){
               if (y == 8){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+3; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else {
                   for (int j=y-1; j < y+3; j++){
                        (turvaalue[j][i] = 7);
                   }    
               }
         }
       }  

       else {
           for (int i=x-1; i < x+2; i++){
               if (y == 8){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+3; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else {
                   for (int j=y-1; j < y+3; j++){
                        (turvaalue[j][i] = 7);
                   }    
               }
         }
       }  
   }

   else if (r==1)   {   
       if (x == 8){     
           for (int i=x-1; i < x+2; i++){
               if (y == 9){
                  for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }    
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+3; i++){
               if (y == 9){
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }    
               }
         }
       }  


      else {
          for (int i=x-1; i < x+3; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 7);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 7);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalue[j][i] = 7);
              }
           }
          }
       }
    }


    piirretaan_vihollisen_turvaalue(turvaalue);  
    }

/////////////////////////////////////////////////////////

//kone piirtää randomina 4 sukellusvenetta 

for (int s = 0; s<4; s++){

   do {
       x = rand() % 10;
       y = rand() % 10;    
     
   } while ((turvaalue[y][x]!=0));  
   vihollisenmeri[y][x]=1;
    
    piirretaan_vihollisenmeri(vihollisenmeri);

    //piirretään turvaalue 
    
      
       if (x == 9){     
           for (int i=x-1; i < x+1; i++){
               if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 8);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 8);
                   }
               }    
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 8);
                   }    
               }
           }
       }
       else if (x == 0){     
           for (int i=x; i < x+2; i++){
               if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 8);
                   }
               }
               else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 8);
                   }
               }
               else {
                   for (int j=y-1; j < y+2; j++){
                        (turvaalue[j][i] = 8);
                   }    
               }
         }
       }  

       else {
          for (int i=x-1; i < x+2; i++){
             if (y == 9){
                   for (int j=y-1; j < y+1; j++){
                        (turvaalue[j][i] = 8);
                   }
               }
             else if (y == 0){
                   for (int j=y; j < y+2; j++){
                        (turvaalue[j][i] = 8);
                   }
               }

             else {                 
                 for (int j=y-1; j < y+2; j++){
                      (turvaalue[j][i] = 8);
              }
           }
          }
       }

    piirretaan_vihollisen_turvaalue(turvaalue); 
}    





uusikierros:    
// ammutaan 

printf("anna koordinaatit mihin haluat ampua\n"); 
ammu:
if (scanf("%d %d", &x, &y) != 2) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
    printf("Anna kaksi kokonaislukua.\n"); 
    goto ammu;   
    }
      
if (x < 0 || x > 9 || y < 0 || y > 9) {
    printf("Luvun pitaa olla valilla 0-9.\n");  
    goto ammu;           
    }
if (dummyoma[y][x]!=0){ 
   printf("olet jo ampunut tahan. anna uudet koordinaatit mihin haluat ampua\n");
   goto ammu;
}
else {
    dummyoma[y][x]=1;
} 
  

//raportoidaan tulos (osuma, osuma&upotus, ohi)
if  ((vihollisenmeri[y][x])==1){
     printf("osuma sukellusveneessa\n");
     vihollisenmeri[y][x]=0;
     if (tarkistetaan_vihollisenmeri(vihollisenmeri, vihollisenmerityhja)==true){
        printf("sina voitit !"); 
        goto loppu;
     }
     else 
          piirretaan_vihollisenmeri(vihollisenmeri);
          goto uusikierros;   
}
   
else if ((vihollisenmeri[y][x])==2){
     printf("osuma havittajassa\n"); 
        vihollisenmeri[y][x]=0;
          if (tarkistetaan_vihollisenmeri(vihollisenmeri, vihollisenmerityhja)==true){
        printf("sina voitit !"); 
        goto loppu;
     }
     else 
          piirretaan_vihollisenmeri(vihollisenmeri);
          goto uusikierros;   
}

else if ((vihollisenmeri[y][x])==3){
     printf("osuma risteilijassa\n");
     vihollisenmeri[y][x]=0;
      if (tarkistetaan_vihollisenmeri(vihollisenmeri, vihollisenmerityhja)==true){
         printf("sina voitit !"); 
         goto loppu;
     }
     else 
        piirretaan_vihollisenmeri(vihollisenmeri);
        goto uusikierros;   
}

else if ((vihollisenmeri[y][x])==4){
     printf("osuma lentotukialuksessa\n"); 
     vihollisenmeri[y][x]=0;
     if (tarkistetaan_vihollisenmeri(vihollisenmeri, vihollisenmerityhja)==true){
        printf("sina voitit !"); 
        goto loppu;
     }
     else 
        piirretaan_vihollisenmeri(vihollisenmeri);
        goto uusikierros;   
}
else {
    printf("Ei osumaa! \n");
}
   
vihollisenmeri[y][x]=0; 

uusikierros2:

//tietokone ampuu sinua 
do {
    x = rand() % 10;
    y = rand() % 10;
 } while ((dummy[y][x] !=0));  
  

printf("tietokone ampui positioon %d %d\n", x, y); 
dummy[y][x]=1;  

//raportoidaan tulos 
if ((omameri[y][x])==1){
     printf("osuma sukellusveneessa\n");
     omameri[y][x]=0;
     if (tarkistetaan_omameri(omameri, omamerityhja)==true){
        printf("vihollinen voitti !"); 
        goto loppu;
     }
     else 
          piirretaan_omameri(omameri);
          goto uusikierros2;   
}
     
   
else if ((omameri[y][x])==2){
     printf("osuma havittajassa\n"); 
     omameri[y][x]=0;
     if (tarkistetaan_omameri(omameri, omamerityhja)==true){
        printf("vihollinen voitti !"); 
        goto loppu;
     }
     else 
        piirretaan_omameri(omameri);
        goto uusikierros2;   
}

else if ((omameri[y][x])==3){
     printf("osuma risteilijassa\n"); 
     omameri[y][x]=0;
     if (tarkistetaan_omameri(omameri, omamerityhja)==true){
        printf("vihollinen voitti !"); 
        goto loppu;
     }
     else 
        piirretaan_omameri(omameri);
        goto uusikierros2;   
}

else if ((omameri[y][x])==4){
     printf("osuma lentotukialuksessa\n");
     omameri[y][x]=0;
     if (tarkistetaan_omameri(omameri, omamerityhja)==true){
        printf("vihollinen voitti !"); 
        goto loppu;
     }
     else 
        piirretaan_omameri(omameri);
        goto uusikierros2;   
}

else {
    printf("Ei osumaa! \n");
    goto uusikierros;
}
   

loppu:
printf("Game over!!");

}
