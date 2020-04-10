/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 3
* Hari dan Tanggal : Jumat, 10 April 2020
* Asisten (NIM) : Arief H. (13217076)
* Nama File : tick_new.c
* Deskripsi : 
* Fungsi tick untuk menyimpan 1 generasi setelah generasi yang menjadi parameter
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
