/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 – TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Minggu, 12 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : game_of_life_lib.h
*   Deskripsi : Library untuk game of life
*
*   Catatan : game_of_life_lib.h versi branch convertseedtoarray hanya untuk fungsi konversi seed file ke seed
*             array dan fungsi untuk mengosongkan memory yang sudah dialokasikan ke seed array
*           
*/

#ifndef GAME_OF_LIFE_LIB_H
#define GAME_OF_LIFE_LIB_H

/* Fungsi getSeedData
    I.S. terdapat parameter file_pointer dari seedfile dan dimensi sumbu x, dimensi sumbu y
            dalam bentuk pointer to integer untuk menyimpan jumlah baris dan kolom
    F.S. mengembalikan data berupa array 2D dynamic yang berisi data seed
*/
char** getSeedData();

/* Fungsi destroyArray untuk membebaskan alokasi memori yang diberikan kepada array 2D
    I.S. terdapat array 2D (seedData) yang memiliki alokasi memori sebagai parameter 
            fungsi
    F.S. array 2D tersebut sudah tidak bisa digunakan karena memori dibebaskan
*/
void destroyArray();


#endif