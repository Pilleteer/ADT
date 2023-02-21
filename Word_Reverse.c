#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int printword(char ls[],int mark){
    for(int i=mark;i<strlen(ls);i++){
        if(ls[i]==' '){
            break;
        }
        printf("%c", ls[i]);
    }
}
int main(void){
    char longstr[100000];
    char temp;
    for(int i=0;i<100000;i++){
        temp=getchar();
        if(temp=='\n'){
            break;
        }
        longstr[i]=temp;
    }
    for(int i=strlen(longstr)-1;i>=0;i--){
        if(longstr[i]==' '){
            printword(longstr,i+1);
            printf(" ");
        }
        if(i==0){
            printword(longstr,0);
        }
    }
}