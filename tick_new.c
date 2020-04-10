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
