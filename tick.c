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
