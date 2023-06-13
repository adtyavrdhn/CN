#include <stdio.h>
#include <string.h>
void f(char c, char s[]){
    char net[20], host[20];

    if(c>='D'){
        printf("No sepeartion of network and host id\n");
        return;
    }

    int dots = c-'A' + 1;

    int count = 0;
    int i=0,j=0;
    while(count < dots){
        net[i++] = s[j++];

        if(s[j]=='.')
            count++;
    }
    net[i] = '\0';
    i = 0;
    j++;
    while(j<strlen(s)){
        host[i++] = s[j++];
    }

    host[i] = '\0';

    printf("Network ID: %s\nHost ID: %s\n", host,net);
}
char class(char s[]){
    int n = strlen(s);


    int i = 0;
    int mul = 1;
    while(s[i]!='.'){
        i++;
    }

    i--;

    int num = 0;
    while(i>=0){
        num = num + (s[i--]-'0') * mul;
        mul*= 10;
    }

    if(num>=0 && num<=127){
        return 'A';
    } else if(num>=128 && num<=191){
        return 'B';
    } else if(num>=192 && num<= 223){
        return 'C';
    } else if(num>= 224 && num<= 239){
        return 'D';
    } else return 'E';
}
int main(void){
    char ip[20];
    printf("Enter IP: \n");
    scanf(" %s",ip);


    char c = class(ip);

    printf("Class is %c\n", c);

    f(c,ip);
}