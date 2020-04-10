/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 – TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Sabtu, 11 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : displaymain.c
*   Deskripsi : main untuk display
*   Catatan : masih terdapat bug pada case, masih ada beberapa testcase yang salah jika input saat quit
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <display.h>

int main()
{
    char filename[40];
    int game_over = 0;
    int x_dim, y_dim;
    char **seedData;
    int pilihan_menu;
    int start = 0;
    int quit = 0;
    int pilihan_quit;

    displayInterface();
    //displaySeed(seedData, &x_dim, &y_dim);

    while(start == 0){
        printf("Masukkan nama file seed: ");
        gets(filename);
        FILE *fptr;
        fptr = fopen(filename , "r");
        if(fptr == NULL){
            printf("tidak terdapat file %s , coba lagi..\n", filename);
            start = 0;
        }else{
            start = 1;
        }
    }

    while(game_over == 0){
        pilihan_menu = displayMenu();
        switch(pilihan_menu)
        {
            case 1:
                //Animate();
                printf("Animate()\n");
                break;
            case 2:
                //Tick();
                printf("Tick()\n");
                break;
            case 3:
                printf("Apakah masih ingin bermain?\n");
                printf("1. Iya dong\n");
                printf("2. Ngga ah capek\n");
                printf("sok mangga : ");
                scanf("%d", &pilihan_quit);
                if(pilihan_quit == 1){
                    start = 0;
                }else{
                    game_over = 1;
                }
                break;
            default:
                printf("masukkan angka tidak sesuai, coba lagi..");
            break;
        }
    }
    return 0;
}

