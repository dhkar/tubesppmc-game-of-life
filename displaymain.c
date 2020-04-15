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
#include "display.h"

int main()
{
    char filename[40];
    int game_over = 0;
    int x_dim, y_dim;
    char **seedData;
    int pilihan_menu;
    int start = 0;
    int quit = 0;
    char pilihan_quit[10];

    displayInterface();
    //displaySeed(seedData, &x_dim, &y_dim);

    while (start == 0){
        printf("\nMasukkan nama file seed : ");
        gets(filename);
        FILE *fptr;
        fptr = fopen(filename, "r");
        if(fptr == NULL){
            printf("\nmohon maaf tidak terdapat file %s, coba lagi..\n", filename);
            start = 0;
        }else{
            pilihan_menu = displayMenu();
            switch(pilihan_menu)
            {
            case 1:
                //fungsi Animate();
                printf("Animate()\n");
                break;
            case 2:
                //fungsi Tick();
                printf("Tick()\n");
                break;
            case 3:
                printf("Apakah masih ingin bermain? \n");
                printf("ketik Ya / Tidak\n");
                printf("pilihan: ");
                scanf("%s ", pilihan_quit);
                if(strcmp(pilihan_quit,"Ya")== 0){
                    start = 0;
                }else{
                    start = 1;
                }
                break;
            default:
                printf("Terima kasih telah bermain.");
            break;
            }
        }
    }

    return 0;
}

