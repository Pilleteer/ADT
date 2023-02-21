#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct numkept{
    int value;
    int temp;
}nk;
int main(void){
    char numw1[1000],numw2[1000];
    nk *num1=NULL;
    nk *num2=NULL;
    char end1='f',end2='f';
    scanf("%s", &numw1);
    scanf("%s", &numw2);
    //printf("%s %d",numw1,sizeof(numw1)/sizeof(numw1[0]));
    num1=(nk *)malloc(sizeof(nk)*1000);
    num2=(nk *)malloc(sizeof(nk)*1000);
    //printf("%d %d",strlen(numw1),strlen(numw2));
    int l=(strlen(numw1)>strlen(numw2))? strlen(numw1):strlen(numw2);
    int s1=strlen(numw1),s2=strlen(numw2);
    for(int i=0;i<l;i++){
        //printf("%d\n",i);
        num1[i].temp=0;
        if(i==l-1){
            //printf("enter");
            num1[i+1].value=0;
            num1[i+1].temp=0;
            num2[i+1].value=0;
        }
        if(numw1[i]==0||end1=='t'){
            //printf("enter2");
            end1='t';
            num1[i].value=0;
            num2[i].value=numw2[i]-48;
        }else if(numw2[i]==0||end2=='t'){
            //printf("enter3");
            end2='t';
            num2[i].value=0;
            num1[i].value=numw1[i]-48;
        }else{
            //printf("enter4");
            num1[i].value=numw1[i]-48;
            num2[i].value=numw2[i]-48;
        }
    }
    int t;
    for(int k=0;k<s1/2;k++){ //reverse num1
        t=num1[k].value;
        //printf("%d %d %d\n",num1[k],num1[s1-1-k],t);
        num1[k].value=num1[s1-1-k].value;
        num1[s1-1-k].value=t;
        t=0;
    }
    for(int m=0;m<s2/2;m++){ //reverse num2
        t=num2[m].value;
        //printf("%d %d\n",num2[m],num2[s2-1-m]);
        num2[m].value=num2[s2-1-m].value;
        num2[s2-1-m].value=t;
        //printf("%d %d\n",num2[m],num2[s2-1-m]);
    }
    //printf("%d",(strlen(numw1)>strlen(numw2))? strlen(numw1):strlen(numw2));
    for(int j=0;j<l+1;j++){
        //printf("%d %d %d\n",num1[j].value,num1[j].temp,num2[j].value);
        if((num1[j].value+num2[j].value+num1[j].temp)/10>=1){
            num1[j+1].temp+=1;
        }
        num1[j].value=(num1[j].value+num1[j].temp+num2[j].value)%10;
        //printf("%-1d",num1[i].value+num2[i].value+num1[i].temp);
    }
    for(int i=l;i>=0;i--){
        if(i==l&&num1[i].value==0){continue;}
        printf("%d",num1[i].value);
    }
    return 0;
}