#include <stdio.h> //printf
#include <stdlib.h> //EXIT_SUCESS
#include <stdbool.h> //bool
#include <stdint.h> //uint8_t, uint64_t, ...

int sumOfTheSquares(int N){

    int sum=0;
    for(int i=1; i<N+1; i++){
        sum += i*i;
    }  
    return sum; 
}

int squareOfTheSum(int N){
    int sum=0;
    for(int i=1; i<N+1; i++){
        sum += i;
    }
    return sum*sum;
}

int main(){
    int n;
    printf("Inputive positive number : ");
    scanf("%d", &n);

    int diff= squareOfTheSum(n)-sumOfTheSquares(n);
    printf("DifferenceOfSquares = %d \n", diff);
    
}