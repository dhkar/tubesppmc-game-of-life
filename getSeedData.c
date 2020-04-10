/*  EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*   MODUL 9 – TUGAS BESAR
*   Kelompok : 3
*   Rombongan : A
*   Hari dan Tanggal : Jumat, 10 April 2020
*   Asisten (NIM) : Arief Hirmanto (13217076)
*   Nama File : getSeedData.c
*   Deskripsi : Fitur mengubah seedfile menjadi seedarray (untuk file test)
*               + bisa menjalankan tick untuk sekali iterasi
*
*   Catatan : Bantu melia memperbaiki dan improvement fungsi tick()
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
    for (rows = 0; rows < y; rows++)
    {
        rows_temp = 0;cols_temp = 0;
        neighbors = 0;

        for (cols = 0; cols < x; cols ++)
        {
            rows_temp = 0;cols_temp = 0;
            neighbors = 0;
            newseedTemp[rows][cols] = seedData[rows][cols];

            if (seedData[rows][cols] == 'X')
            {

                for (i = -1; i <= 1; i++)
                {
                    for (j = -1; j <= 1; j++)
                    {

                        rows_temp = rows +i;
                        cols_temp = cols +j;
                        if (rows_temp < 0){rows_temp = y-1;}
                        if (cols_temp < 0){cols_temp = x-1;}
                        if (rows_temp > y-1){rows_temp = 0;}
                        if (cols_temp > x-1){cols_temp = 0;}
             
                        if ((seedData[rows_temp][cols_temp] == 'X')){
                            neighbors++;}

                    }
                }

                neighbors -= 1;

                if ((neighbors == 2) || (neighbors == 3)){
                    newseedTemp[rows][cols] = 'X';} 
                else if ((neighbors < 2) || (neighbors > 3)){
                    newseedTemp[rows][cols] = '-';}
                    
            }

            if (seedData[rows][cols] == '-')
            {
                for (i = -1; i <= 1; i++)
                {
                    for (j = -1; j <= 1; j++){
                        rows_temp = rows +i;
                        cols_temp = cols +j;
                        if (rows_temp < 0){rows_temp = y-1;}
                        if (cols_temp < 0){cols_temp = x-1;}
                        if (rows_temp > y-1){rows_temp = 0;}
                        if (cols_temp > x-1){cols_temp = 0;}

                        if ((seedData[rows_temp][cols_temp] == 'X')){
                            neighbors++;}
                    }
                }

                if (neighbors == 3){
                    newseedTemp[rows][cols] = 'X';} 
                else if ((neighbors < 2) || (neighbors > 3)){
                    newseedTemp[rows][cols] = '-';}

                    
            }
        
        }
    }
    return newseedTemp;
}

int main() {
    FILE *fptr;
    
    int c;
    int n = 0;
    int x_dimension,y_dimension;
    char filename[50];

    // printf("Masukkan filename: ");
    // scanf("%s",filename);
    fptr = fopen("glider-gun.txt","r");
    char **seedData,**newseedData;
    seedData = getSeedData(&fptr,&x_dimension,&y_dimension);

    // alokasi variabel baru newseedData
    newseedData = malloc(y_dimension * sizeof(*newseedData));
    for (int i = 0; i < y_dimension; i++) {
        newseedData[i] = malloc(x_dimension * sizeof(newseedData[0]));
    }
    

    newseedData = tick(seedData,&x_dimension,&y_dimension);

    for (int i = 0; i < y_dimension; i++) {
        for(int j = 0; j < x_dimension; j++){
            printf("%c",seedData[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < y_dimension; i++) {
        for(int j = 0; j < x_dimension; j++){
            printf("%c",newseedData[i][j]);
        }
        printf("\n");
    }

    printf("Dimensi -> Kolom = %d , Baris = %d\n",x_dimension,y_dimension);
    destroyArray(seedData);
    destroyArray(newseedData);


    fclose(fptr);
    return(0);

}