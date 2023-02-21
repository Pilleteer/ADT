
#include<stdio.h>
typedef struct datetime{
    int date;       //1-31
    int month;      //1-12
    int year;       //1970++
    int dayOfWeek;  //0-6
    int hour;       //0-23
    int minute;     //0-59
    int second;     //0-59
} datetime_t;
datetime_t createDate(long int time){
    datetime_t temp;
    long int day=86400,hours=60*60,minutes=60; //second
    int oy=365,ycnt=1970,mcnt=1; //day
    char atig='f';
    temp.dayOfWeek=(time/day)%7;
    temp.hour=0;
    temp.minute=0;
    temp.second=0;
    for(time;time/day>=oy;){
        if(oy==365&&atig=='t'){oy+=1;}
        if(oy==366&&atig=='f'){oy-=1;}
        if((ycnt+1)%4==0){
            if((ycnt+1)%400==0){
                atig='t';
            } else if((ycnt+1)%100==0){
                atig='f';
            } else{atig='t';}
        }else{atig='f';}
        ycnt+=1;
        printf("%d %c\n",oy,atig);
        time-=day*oy;
    }
    int mtemp;
    for(mcnt;mcnt<=12;mcnt++){
    //printf("enter\n");
        switch(mcnt){
            case 1: mtemp=31;break;
            case 2: if(atig=='t'){
                mtemp=29;
               }else if(atig=='f'){
                 mtemp=28;
               }break;
            case 3: mtemp=31;break;
            case 4: mtemp=30;break;
            case 5: mtemp=31;break;
            case 6: mtemp=30;break;
            case 7: mtemp=31;break;
            case 8: mtemp=31;break;
            case 9: mtemp=30;break;
            case 10: mtemp=31;break;
            case 11: mtemp=30;break;
            case 12: mtemp=31;break;
        }
        if((time/day)<mtemp){
            break;
        }
        else{time-=day*mtemp;}
    }
    printf("%ld %d %d\n",time,time/day,mcnt);
    temp.date=(time/day)+1;
    temp.month=mcnt;
    temp.year=ycnt;
    temp.hour=(time%day)/hours;
    temp.minute=(time%hours)/minutes;
    temp.second=time%minutes;
    return temp;
}
datetime_t printDate(datetime_t wantprint){
    switch(wantprint.dayOfWeek){
        case 0:printf("Thu ");break;
        case 1:printf("Fri ");break;
        case 2:printf("Sat ");break;
        case 3:printf("Sun ");break;
        case 4:printf("Mon ");break;
        case 5:printf("Tue ");break;
        case 6:printf("Wed ");break;
    }
    printf("%d ",wantprint.date);
    switch(wantprint.month){
        case 1: printf("Jan ");break;
        case 2: printf("Feb ");break;
        case 3: printf("Mar ");break;
        case 4: printf("Apr ");break;
        case 5: printf("May ");break;
        case 6: printf("Jun ");break;
        case 7: printf("Jul ");break;
        case 8: printf("Aug ");break;
        case 9: printf("Sep ");break;
        case 10:printf("Oct ");break;
        case 11:printf("Nov ");break;
        case 12:printf("Dec ");break;
    }
    printf("%ld %.2ld:%.2ld:%.2ld", wantprint.year,wantprint.hour,wantprint.minute,wantprint.second);
}
int main(void){
    datetime_t inputDate;
    long int timestamp;
    scanf("%ld", &timestamp);
    inputDate = createDate(timestamp);
    printDate(inputDate);
    return 0;
}
//1528374628
//1597436869