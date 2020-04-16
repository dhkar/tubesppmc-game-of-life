/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 - TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Kamis, 16 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : game_of_life_lib.h
*   Deskripsi : implementasi fungsi animate, tick, getSeedData
*   Catatan : ada tambahan fungsi delay dan destroyArray
*/

char** getSeedData(FILE **file_pointer, int *x_dim, int *y_dim);
void destroyArray(char** arr);
char **tick(char **seedData, int *x_dim, int *y_dim);
void delay(int milli_seconds);
char **Animate(char **seedData, int* x_dim, int* y_dim, int num_of_ticks);


