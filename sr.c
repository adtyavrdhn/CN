#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n = 0, w = 0;
    printf("Enter the size of total data to be sent: \n");
    scanf(" %i", &n);


    printf("Enter the window size \n");
    scanf(" %i",&w);


    int i =0;

    while(i<=n){

        for(int p=i;p<w+i;p++){
            printf("Sending packet %i",p);
        }

        int nac = i + rand() % w;

        if(nac==i){
            printf("No NACK recieved, All frames sent successfully\n");
            i+= w;
            continue;;
        }

        printf("NACK: %d\n",nac);
        printf("Sending Packet: %d\n",nac);
        printf("ACK recieved for: %d\n",nac);
        printf("All packets sent successfully %d\n",nac);
        i+=w;
    }
}