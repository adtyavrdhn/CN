#include <stdio.h>

int main(void){
    int a[10],b[10];

    printf("Enter 4 data bits to be sent: \n");
    scanf(" %i %i %i %i",&a[3],&a[5],&a[6],&a[7]);

    a[1] = a[3] ^ a[5] ^ a[7];
    a[2] = a[3] ^ a[6] & a[7];
    a[4] = a[5] ^ a[6] ^ a[7];

    printf("Data Bits Sent: \n");

    for(int i=1;i<=7;i++)
        printf("%i ",a[i]);

    printf("\nEnter 7 data bits recieved: \n");

    for(int i=1;i<=7;i++){
        scanf(" %i",&b[i]);
    }
    printf("Data bits recieved\n");

    for(int i=1;i<8;i++){
        printf(" %i",b[i]);
    }

    int c1 = b[1] ^ b[3] ^ b[5] ^ b[7];
    int c2 = b[2] ^ b[3] ^ b[6] & b[7];
    int c3 = b[4] ^ b[5] ^ b[6] ^ b[7];

    int c = 4*c3 + 2*c2 + c1;

    if(c==0){
        printf("\nNo Error\n");
    }else{
        printf("\nError in position %i",c);
        b[c] = !b[c];
    }

    printf("\nData bits: \n");
    for(int i=1;i<=7;i++)
        printf("%i ",b[i]);
}