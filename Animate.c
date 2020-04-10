#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void delay(int number_of_seconds);                                      //Delay 250ms
void Tick(char **seedData, int x_dim, int y_dim);                       //Animate 1 time
int neighbors(char **seedData, int x_dim, int y_dim ,int i, int j);                          //Check cell condition
void Animate(char **seedData, int x_dim, int y_dim, int num_of_ticks);  //Animate num_of_ticks times

void delay(int number_of_seconds) 
{ 
    int milli_seconds = 1000 * number_of_seconds; 
    clock_t start_time = clock(); 
    while (clock() < start_time + milli_seconds);
} 

int neighbors(char **seedData, int x_dim, int y_dim ,int i, int j){           //Check number of neighbors
    int count, k, l;
    if (i == 0 && j == 0){                  //Corner Cell
        
    }else if (i == 0 && j != 0){            //Top or Bottom Row

    }else if (i != 0 && j == 0){            //Left or Right Column

    }else{

    }

}

void Tick(char **seedData, int x_dim, int y_dim){
    int i, j; // x = kolom, y = baris
    for (i=0; i<=y_dim; i++){
        for (j=0; j<=x_dim; j++){
            switch (neighbors(seedData, x_dim, y_dim, i, j))
            {
            case 1:             //underpopulation
                seedData[i][j] = '-';
                break;

            case 2:             //next generation
                seedData[i][j] = 'X';
                break;

            case 3:             //overpopulation
                seedData[i][j] = '-';
                break;

            case 4:             //reproduction
                seedData[i][j] = 'X';
                break;
            
            default:
                break;
            }
        }
    }
}


void Animate(char **seedData, int x_dim, int y_dim, int num_of_ticks){
    system("@cls||clear");
    int i=0;
    while (i<=num_of_ticks)
    {
        Tick(seedData, x_dim, y_dim);
        delay(250);
        i++;
    }
    
}

int main(){
    char **seedData;
    int num_of_ticks, x_dim, y_dim;
    Animate(seedData, x_dim, y_dim, num_of_ticks);
}


