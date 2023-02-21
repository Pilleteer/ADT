#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int textfind(char text[],char src[],int pgr,int sl){
    int cnt=0,ag=0;
    for(int i=pgr;i<=strlen(text)-3;i++){
        if(src[ag]==text[i]){
            cnt+=1;
        }
        ag+=1;
        if(ag>=sl){
            break;
        }
    }
    return cnt;
}
int main(void){
    //printf("test");
    int m,p,n,i;
    scanf("%d %d %d\n", &m, &p, &n);
    char text[m+1];
    char srch[p];
    int strcnt=0,bl=0,cnt=0;
    for(i=0;i<m+1;i++){
        text[i]=getchar();
    }
    for(i=0;i<p;i++){
        srch[i]=getchar();
    }
    int test=strlen(text);
    for(i=0;i<m;i++){
        if(i+p<=m&&textfind(text,srch,i,p)>=p-n){
            if(cnt==0){printf("[");}
            bl=1;
        }
        if(bl==1&&text[i]!=srch[cnt]){
            printf("?");
            cnt+=1;
        }else if(bl==1&&text[i]==srch[cnt]){
            printf("%c", text[i]);
            cnt++;
        }else{
            printf("%c", text[i]);
        }
        if(cnt>=p){
            printf("]");
            cnt=0;
            bl=0;
        }
    }
    //printf("\n%s", text);
    return 0;
}//acabababababcbabab
/*
acabababababcabbab
AAAGTGTGTCTGATT
*/