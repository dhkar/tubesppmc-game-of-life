#include <stdio.h>
#include <stdlib.h>
    
    
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

int main(){
    FILE *file_pointer;
    int x_dim, y_dim;
    char nama_file[50];
    char **newseedData;

    printf("Masukkan nama file: ");
    gets(nama_file);

    file_pointer = fopen(nama_file, "r");

    newseedData = tick(seedData, &x_dim, &y_dim);

    printf(" %c %c %c %c %c %c %c %c %c\n", newseedData[2][1], newseedData[2][2], newseedData[2][3], newseedData[2][4], newseedData[2][5], newseedData[2][6], newseedData[2][7], newseedData[2][8], newseedData[2][9]);
    printf(" %c %c %c %c %c %c %c %c %c\n", newseedData[2][1], newseedData[3][2], newseedData[3][3], newseedData[3][4], newseedData[3][5], newseedData[3][6], newseedData[3][7], newseedData[3][8], newseedData[3][9]);
    printf(" %c %c %c %c %c %c %c %c %c\n", newseedData[2][1], newseedData[4][2], newseedData[4][3], newseedData[4][4], newseedData[4][5], newseedData[4][6], newseedData[4][7], newseedData[4][8], newseedData[4][9]);
    printf(" %c %c %c %c %c %c %c %c %c\n", newseedData[2][1], newseedData[5][2], newseedData[5][3], newseedData[5][4], newseedData[5][5], newseedData[5][6], newseedData[5][7], newseedData[5][8], newseedData[5][9]);
    printf(" %c %c %c %c %c %c %c %c %c\n", newseedData[2][1], newseedData[6][2], newseedData[6][3], newseedData[6][4], newseedData[6][5], newseedData[6][6], newseedData[6][7], newseedData[6][8], newseedData[6][9]);
}

