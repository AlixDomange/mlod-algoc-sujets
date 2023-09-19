#include <stdio.h> //printf
#include <stdlib.h> //EXIT_SUCESS
#include <stdbool.h> //bool
#include <stdint.h> //uint8_t, uint64_t, ...


bool isParfait(int nombre){
    int n = 0;
    int m=0;
    for(int i=1; i<nombre; i++){
        if(nombre%i==0){
            n=n+i;
        }
    }
    if (n==nombre){
        m=1;
    }
    return m;
}

int main(void) {
    int nombre = 30;
    for(int i=1; i<nombre; i++){
        if(isParfait(i)==1){
            printf("%d \n", i);
        }
    }

}