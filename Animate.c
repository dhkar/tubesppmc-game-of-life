#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void delay(int number_of_seconds);                                      // Delay 250ms
char** tick(char **seedData, int* x_dim, int* y_dim);                     // Animate 1 time
void Animate(char **seedData, int* x_dim, int* y_dim, int num_of_ticks);  // Animate num_of_ticks times

void delay(int milli_seconds) 
{ 
    int ms =  milli_seconds;
    clock_t start_time = clock(); 
    while (clock() < start_time + ms);
} 

int neighbors(char **seedData, int x_dim, int y_dim ,int i, int j){  // Check number of neighbors
   
}

char** tick(char **seedData, int* x_dim, int* y_dim){

}

void Animate(char **seedData, int* x_dim, int* y_dim, int num_of_ticks){
    char **newseedData;
    int k=0, x = *x_dim, y = *y_dim;
    newseedTemp = malloc(x * sizeof(*newseedTemp));
    for (int i = 0; i < x; i++) {
        newseedTemp[i] = malloc(y * sizeof(newseedTemp[0]));
    }
    newseedData = tick(seedData,&x,&y);
    while (k<num_of_ticks)
    {
        displaySeed(newseedData,&x,&y);
        delay(250);
        newseedData = tick(newseedData,&x,&y);
        system("@cls||clear");
        k++;
    }
}


int main() {
    printf("Masukan jumlah ticks : ");                          // Masukin ke main
    int num_of_ticks;
    scanf("%d", &num_of_ticks);
    Animate(seedData, &x_dimension, &y_dimension,num_of_ticks);
}
   