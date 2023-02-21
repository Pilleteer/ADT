#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int possav(char **mz,int i,int j,int n){
    //printf("%c",mz[i][j]);
    if( i>=0 && j>=0 && i<n && j<n && mz[i][j]!='#'){
        return 1;
    }
    return 0;
}
int traverseMaze(char **mz,int i,int j,int n,char tid){
    if(mz[i][j]=='G'){
        //path find
        return 1;
    }
    if(possav(mz,i,j,n)==1){
        //find path
        mz[i][j]='.';
        if(tid!='W' && traverseMaze(mz,i+1,j,n,'S')==1){
            return 1;
        }
        if(tid!='S' && traverseMaze(mz,i-1,j,n,'W')==1  ){
            return 1;
        }
        if(tid!='A' && traverseMaze(mz,i,j+1,n,'D')==1){
            return 1;
        }
        if(tid!='D' && traverseMaze(mz,i,j-1,n,'A')==1){
            return 1;
        }
        //not found
        mz[i][j]=' ';
        return 0;
    }
    return 0;
}
int main(void){
    int n,si,sj;
    int sen[2]={0,0};
    scanf("%d\n", &n);
    char **maze;
    maze=(char **)malloc(sizeof(char *)*n);
    for (int i = 0; i < n; i++)
    {
        maze[i]=(char *)malloc(sizeof(char)*n);
        for(int j=0;j<n;j++){
            maze[i][j]=getchar();
            if(maze[i][j]=='S'){
                si=i;
                sj=j;
            }
            if(maze[i][j]=='G'){
                sen[0]+=i;
                sen[1]+=j;
            }
        }
        if(i!=n-1){scanf("\n");}
    }
    traverseMaze(maze,si,sj,n,' ');
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}/*
############
#   #      #
S # # #### #
### #    # #
#    ### # G
#### # # # #
#  # # # # #
## # # # # #
#        # #
###### ### #
#      #   #
############
*/