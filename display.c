//tubes ppmc
//trial bagian display
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <display.h>

void displaySeed(){
    char nama[100];
    printf("input file seed : ");
    gets(nama);
    FILE *file_seed = fopen(nama, "r");
    int baris = 0;
    char s[1024];
    while(fgets(s, 1024, file_seed)){
        baris++;
        printf("%s", s);
    }

    fclose(file_seed);
}

void displayMenu(int *game_over){
    int pilihan;
    printf("\n\nPilihan menu: \n");
    printf("1. Animate\n");
    printf("2. Tick\n");
    printf("3. Quit\n");
    printf("Masukkan menu yang dipilih : ");
    scanf("%d", &pilihan);
    if(pilihan == 1){
        printf("fungsi animate()");
    }else if(pilihan == 2){
        printf("fungsi tick()");
    }else{
        *game_over = 1;
    }
}

void displayInterface(){
    printf("\n---------------------Welcome to---------------------\n");
    printf("\n--------------------Game of Life--------------------\n");
}

/*int main()
{
   int game_over = 0;
   int pilihan_quit;
   displayInterface();
   displaySeed();
   while (game_over == 0){
        displayMenu(&game_over);
   }
   if (game_over == 1){
        printf("Apakah masih ingin bermain?\n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("pilihan : ");
        scanf("%d", &pilihan_quit);
        if(pilihan_quit == 1){
            printf("fungsi getSeedData()\n");
            displaySeed();
        }else if(pilihan_quit == 2){
            printf("Game Over\n");

        }else{
            printf("pilihan salah\n");
        }
   }

   return 0;
}*/
