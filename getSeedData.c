/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 – TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Selasa, 7 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : getSeedData.c
*   Deskripsi : Fitur mengubah seedfile menjadi seedarray (untuk testcase)
*   Catatan : Third commit getSeedData.c, fitur untuk mengubah seedfile menjadi seedarray
*           sudah berhasil dijalankan, second commit karena lupa tambah header ini. Third commit
*           mengubah glider-gun.txt menjadi input user filename
*           
*/
#include <stdio.h>
#include <stdlib.h>
// Bismillahirrahmanirrahim

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

void destroyArray(char** arr)
{
    free(*arr);
    free(arr);
}

int main() {
    FILE *fptr;
    
    int c;
    int n = 0;
    int x_dimension,y_dimension;
    char filename[50];
    printf("Masukkan filename: ");
    scanf("%s",filename);
    fptr = fopen(filename,"r");
    char **seedData;
    
    // testing print seedData
    seedData = getSeedData(&fptr,&x_dimension,&y_dimension);
    for (int i = 0; i < y_dimension; i++) {
        for(int j = 0; j < x_dimension; j++){
            printf("%c",seedData[i][j]);
        }
        printf("\n");
    }

    printf("Dimensi -> Kolom = %d , Baris = %d\n",x_dimension,y_dimension);
    destroyArray(seedData);


    fclose(fptr);
    return(0);

}
