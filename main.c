/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 3
* Rombongan : A
* Hari dan Tanggal : Jumat, 3 April 2020
* Asisten (NIM) : Arief Hirmanto (13217076)
* Nama File : main.c
* Deskripsi : Program utama dari implementasi Game Of Life
* Catatan : First commit of main.c, yaitu hanya sebatas algoritma kasar program utama, 
*           belum implementasi fungsi secara mendetail
*           
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    /* ====== ALGORITMA PROGRAM UTAMA =========*/

    /*  1. Input dari user : char namafile[]

    */

    /*  2. Panggil procedure getSeedData()
    
        I.S. Nama file adalah input dari user
        F.S. Terdapat x dan y yang merupakan ukuran dari array
        dan array yang berisi dari seed data

    */
    void getSeedData(FILE* fptr, int x, int y, char seeddata[]);

    /*  3. Membuat array char seeddata[] menjadi toroidal

        Ide saran implementasi : kalo misalkan suatu variabel i buat traverse udah lebih
        dari x atau y, maka akan ngulang dari 0, atau kurang dari x atau y, maka akan 
        berubah ke x atau y

    */

    /* 4. Panggil Procedure displaySeed()

        Untuk menampilkan seed awal yang sudah diproses dari file eksternal
    
    */
    void displaySeed(char seeddata[]);

    /* 5. Panggil Procedure displayMenu()

        Untuk menampilkan menu interface dengan user. Terdapat menu:
        a. Animate
        b. Tick
        c. Quit

        Ide : pake switch case biasa harusnya. alternatifnya setiap pilihan 
        terdapat fungsi masing masing untuk memproses misal:
        Animate()
        Tick()
    */

   void displayMenu();
   void Animate(char seedData[], int num_of_ticks);
   void Tick(char seedData[]);

   /* 6. 
        Semua fungsi diatas berada di dalam while loop dengan menggunakan sentinel,
        sampai user menekan quit dan tidak mau memasukan filename lagi

        jika user tidak mau memasukkan filename, maka program berhenti
    */


}