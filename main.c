/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 - TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Kamis, 16 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : main.c
*   Deskripsi : Program utama dari implementasi Conway's Game Of Life
*   Catatan : Finishing program utama 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "display.h"
#include "game_of_life_lib.h"

int main()
{
    char filename[40];
    int x_dim, y_dim;
    char **seedData;
    int pilihan_menu;
    int start = 0;
    int quit = 0;
    char pilihan_quit[10];
    int num_of_ticks;

    displayInterface();

    FILE *fptr;
    while(start == 0){
        quit = 0;
        printf("\nMasukkan nama file seed : ");
        scanf("%s",filename);
        fptr = fopen(filename, "r");
        if(fptr == NULL){
            printf("\nmohon maaf tidak terdapat file %s, coba lagi..\n", filename);
        }else{
            seedData = getSeedData(&fptr,&x_dim,&y_dim);
            displaySeed(seedData, &x_dim, &y_dim);
            while(quit == 0){
                pilihan_menu = displayMenu();
                switch(pilihan_menu)
                {
                case 1:
                    //fungsi Animate
                    printf("Masukan jumlah ticks : ");
                    scanf("%d", &num_of_ticks);
                    seedData = Animate(seedData, &x_dim, &y_dim, num_of_ticks);
                    break;
                case 2:
                    seedData = tick(seedData, &x_dim, &y_dim);
                    displaySeed(seedData, &x_dim, &y_dim);
                    break;
                case 3:
                    printf("Apakah masih ingin bermain? \n");
                    printf("ketik Ya / Tidak\n");
                    printf("pilihan: ");
                    scanf("%s", pilihan_quit);
                    if(strncmp(pilihan_quit,"Ya",2)== 0){
                        fclose(fptr);
                        quit = 1;
                    }else{
                        fclose(fptr);
                        printf("\nTerima kasih telah bermain.\n");
                        quit = 1;
                        start = 1;
                    }
                    break;
                }
            }
        }
    }

    return 0;
}