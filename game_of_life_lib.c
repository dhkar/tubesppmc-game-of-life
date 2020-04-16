/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 - TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Kamis, 16 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : game_of_life_lib.c
*   Deskripsi : fungsi animate, tick, getSeedData
*   Catatan : ada tambahan fungsi delay dan destroyArray
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "display.h"

/* Fungsi getSeedData
        I.S. terdapat parameter file_pointer dari seedfile dan dimensi sumbu x, dimensi sumbu y
             dalam bentuk pointer to integer untuk menyimpan jumlah baris dan kolom
        F.S. mengembalikan data berupa array 2D dynamic yang berisi data seed
*/
char** getSeedData(FILE **file_pointer, int *x_dim, int *y_dim){

    // Mengambil data ukuran world dari file external
    // M : Jumlah Baris, N : Jumlah Kolom (disesuaikan dg sifat array)
    char c;
    char M_temp[5];
    char N_temp[5];
    int M,N;
    fgets(M_temp,5,*file_pointer);
    fgets(N_temp,5,*file_pointer);
    M = atoi(M_temp);
    N = atoi(N_temp);

    // alokasi memori array dinamis 2D seedTemp (sesuai dengan ukuran)
    char **seedTemp;
    seedTemp = malloc(M * sizeof(*seedTemp));
    for (int i = 0; i < M; i++) {
        seedTemp[i] = malloc(N * sizeof(seedTemp[0]));
    }
    // Proses traversal file eksternal dan menyimpan setiap character ke array seedTemp[][]
    int i = 0; int j = 0;
    while((i != M-1) || (j != N-1)) {
        c = fgetc(*file_pointer);
        seedTemp[i][j] = c;
        ++j;
        if(j>N-1) {
            c = fgetc(*file_pointer);
            j = 0;
            ++i;
        }
        if((i == M-1) && (j==N-1)){
            c = fgetc(*file_pointer);
            seedTemp[i][j] = c;
        }
    }

    // Menyimpan dimensi world dari seed pada pointer x_dim dan y_dim
    *x_dim = N;
    *y_dim = M;
    return seedTemp;
    }

/* Fungsi destroyArray untuk membebaskan alokasi memori yang diberikan kepada array 2D
    I.S. terdapat array 2D (seedData) yang memiliki alokasi memori sebagai parameter fungsi
    F.S. array 2D tersebut sudah tidak bisa digunakan karena memori dibebaskan
*/
void destroyArray(char** arr)
{
    free(*arr);
    free(arr);
}

/* Fungsi tick untuk menyimpan 1 generasi setelah generasi yang menjadi parameter
    * I.S. terdapat array 2D (seedData) yang memiliki alokasi memori sebagai parameter
    * fungsi, panjang dan lebar array seedData
    * F.S. mengembalikan data berupa array 2D dynamic yang berisi data seed 1 generasi setelah generasi yang menjadi parameter
*/
char **tick(char **seedData, int *x_dim, int *y_dim)
{
    int neighbors;
    int x, y;
    int rows;
    int cols;
    int i, j;
    int rows_temp,cols_temp;
    x = *x_dim;
    y = *y_dim;

    // alokasi memori array dinamis 2D newseedTemp (sesuai dengan ukuran)
    char **newseedTemp;
    newseedTemp = malloc(x * sizeof(*newseedTemp));
    for (int i = 0; i < x; i++) {
        newseedTemp[i] = malloc(y * sizeof(newseedTemp[0]));
    }

    // Hitung jumlah tetangga lalu ganti nilai seedData ke generasi selanjutnya
    for (rows = 0; rows < y; rows++){
        rows_temp = 0;cols_temp = 0;
        neighbors = 0;
        for (cols = 0; cols < x; cols ++){
            rows_temp = 0;cols_temp = 0;
            neighbors = 0;
            newseedTemp[rows][cols] = seedData[rows][cols];

            if (seedData[rows][cols] == 'X'){
                for (i = -1; i <= 1; i++){
                    for (j = -1; j <= 1; j++){
                        rows_temp = rows +i;
                        cols_temp = cols +j;
                        if (rows_temp < 0){rows_temp = y-1;}
                        if (cols_temp < 0){cols_temp = x-1;}
                        if (rows_temp > y-1){rows_temp = 0;}
                        if (cols_temp > x-1){cols_temp = 0;}

                        if ((seedData[rows_temp][cols_temp] == 'X')){
                            neighbors++;
                        }
                    }
                }
                neighbors -= 1;

                if ((neighbors == 2) || (neighbors == 3)){
                    newseedTemp[rows][cols] = 'X';
                }else if ((neighbors < 2) || (neighbors > 3)){
                    newseedTemp[rows][cols] = '-';
                }
            }

            if (seedData[rows][cols] == '-'){
                for (i = -1; i <= 1; i++){
                    for (j = -1; j <= 1; j++){
                        rows_temp = rows +i;
                        cols_temp = cols +j;
                        if (rows_temp < 0){rows_temp = y-1;}
                        if (cols_temp < 0){cols_temp = x-1;}
                        if (rows_temp > y-1){rows_temp = 0;}
                        if (cols_temp > x-1){cols_temp = 0;}

                        if ((seedData[rows_temp][cols_temp] == 'X')){
                            neighbors++;
                        }
                    }
                }

                if (neighbors == 3){
                    newseedTemp[rows][cols] = 'X';
                }else if ((neighbors < 2) || (neighbors > 3)){
                    newseedTemp[rows][cols] = '-';
                }
            }
        }
    }
    return newseedTemp;
}

/* Fungsi delay()
        I.S. terdapat parameter milli_seconds dari input user yang merupakan waktu dalam
        satuan ms
        F.S. mengembalikan data berupa delay selama input
*/
void delay(int milli_seconds)
{
    int ms =  milli_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + ms);
}

/* Fungsi Animate
        I.S. terdapat parameter file_pointer dari seedfile dan dimensi sumbu x, dimensi sumbu y
             dalam bentuk pointer to integer untuk menyimpan jumlah baris dan kolom, serta
             num_of_ticks untuk mengetahui jumlah iterasi tick
        F.S. mencetak generasi selanjutnya dari seed berulang kali sebanyak num_of_ticks
*/
char **Animate(char **seedData, int* x_dim, int* y_dim, int num_of_ticks){
    char **newseedData;
    int k=0, x = *x_dim, y = *y_dim;

    newseedData = malloc(x * sizeof(*newseedData));
    for (int i = 0; i < x; i++) {
        newseedData[i] = malloc(y * sizeof(newseedData[0]));
    }

    newseedData = tick(seedData,&x,&y);

    while (k<num_of_ticks){
        displaySeed(newseedData,&x,&y);
        delay(250);
        newseedData = tick(newseedData,&x,&y);
        system("@cls||clear");
        k++;
    }
    return newseedData;
}
