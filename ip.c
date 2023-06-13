#include <stdio.h>
#include <string.h>

char class(char s[]){
    int i = 0;
    while(s[i]!='.'){
        i++;
    }
    i--;
    int num = 0, mul = 1;
    while(i>=0){
        num = num + (s[i--]-'0')*mul;
        mul*= 10;
    }

    if(num>=0 && num<=127){
        return 'A';
    } else if(num>=128 && num<= 191){
        return 'B';
    } else if(num>=192 && num<= 223){
        return 'C';
    } else if(num>=223 && num<=239){
        return 'D';
    } else if(num>=240 && num<=255){
        return 'E';
    }
}
void f(char s[], char c){
    char net[12], host[12];
    int i=0,j=0;
    if(c=='A'){
        while(s[j]!='.'){
            net[i++] = s[j++];
        }
        net[i] = '\0';
        i = 0;
        j++;
        while(s[j]!='\0'){
            host[i++] = s[j++];
        }

        host[i] = '\0';

        printf("Network ID: %s\nHost ID: %s\n",net,host);
    } else if(c=='B' || c=='C'){
        int dots = c-'A' + 1;
        int count = 0;

        while(count < dots){
            net[i++] = s[j++];
            if(s[j]=='.')
                count++;
        }
        j++;
        net[i] = '\0';
        i = 0;
        while(j < strlen(s)){
            host[i++] = s[j++];
        }
        host[i] = '\0';
        printf("Network ID: %s\nHost ID: %s\n",net,host);
    } else printf("No seperation of Network ID and Host ID");
}
int main(void){

    while(1){
        char ip[20];
        printf("Enter IP address: \n");

        scanf(" %s",&ip);

        char c = class(ip);

        printf("Class of IP: %c\n",c);
        f(ip,c);
    }
}