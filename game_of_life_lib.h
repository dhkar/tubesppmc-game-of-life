/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 – TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Selasa, 7 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : game_of_life_lib.h
*   Deskripsi : file library untuk conway's game_of_life
*   Catatan : Second Commit, penambahan fungsi getSeedData dan destroyArray
*           
*/
#include <stdio.h>
#include <stdlib.h>
#ifndef GAME_OF_LIFE_LIB_H
#define GAME_OF_LIFE_LIB_H

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
        I.S. terdapat array 2D (seedData) yang memiliki alokasi memori sebagai parameter 
             fungsi
        F.S. array 2D tersebut sudah tidak bisa digunakan karena memori dibebaskan
    */
    void destroyArray(char** arr)
    {
        free(*arr);
        free(arr);
    }


    /* Fungsi tick untuk menyimpan 1 generasi setelah generasi yang menjadi parameter
        I.S. terdapat array 2D (seedData) yang memiliki alokasi memori sebagai parameter 
             fungsi, panjang dan lebar array seedData
        F.S. mengembalikan data berupa array 2D dynamic yang berisi data seed 1 generasi setelah generasi yang menjadi parameter
    */
    char **tick(char **seedData, int *x_dim, int *y_dim)
    {
        int neighbors;
        int x, y;
        int rows;
        int cols;
        int i, j;

        x = *x_dim;
        y = *y_dim;

        // alokasi memori array dinamis 2D newseedTemp (sesuai dengan ukuran)
        char **newseedTemp;
        newseedTemp = malloc(x * sizeof(*newseedTemp));
        for (int i = 0; i < x; i++) {
            newseedTemp[i] = malloc(y * sizeof(newseedTemp[0]));
        }

        //Hitung jumlah tetangga lalu ganti nilai seedData ke generasi selanjutnya
        for (rows = 1; rows < y-1; rows++)
        {
            for (cols = 1; cols < x-1; cols ++)
            {
                neighbors = 0;
                newseedTemp[rows][cols] = seedData[rows][cols];

                for (i = -1; i <= 1; i++)
                {
                    for (j = -1; j <= 1; j++){
                        if ((seedData[rows +i][cols +j] == '-')){
                            neighbors += 0;}
                        if ((seedData[rows +i][cols +j] == 'X')){
                            neighbors++;}
                    }
                }

                if ((seedData[rows][cols] == 'X')){
                    neighbors -= 1;
                }

                if ((neighbors == 2) || (neighbors == 3)){
                    newseedTemp[rows][cols] = 'X';} 
                else if ((neighbors < 2) || (neighbors > 3)){
                    newseedTemp[rows][cols] = '-';}
            }
        }
        return newseedTemp;
    }


#endif
