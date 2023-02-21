#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int planner(double w,double l){
    if(w<=0||l<=0){return 0;}
    if(w==1||l==1){return w*l;}
    if(w==2&&l==2){return 1;}
    int i=0,kept=0,sq;
    for(i;kept<=w&&kept<=l;i++){
      kept=pow(2,i);
      sq=pow(2,i-1);
    }
    return 1+planner(w-sq,l)+planner(sq,l-sq);
}
int main(void){
    double width,lenght;
    int cnt=0;
    scanf("%lf %lf",&width,&lenght);
    cnt+=planner(width,lenght);
    printf("%d",cnt);
}