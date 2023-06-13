#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n = 0;
    printf("Enter number of packets: \n");
    scanf(" %i",&n);

    for(int i=1;i<=n;i++){
        int r = rand() % 2;

        if(r==0){
            int ack = rand() % 2;

            if(ack == 0){
                printf("Ack Number %i\n",i);
            }else{
                printf("No ack number\n");
                i--;
            }
        }
        else{
            printf("Timer expired \n");
            i--;
        }
    }
}