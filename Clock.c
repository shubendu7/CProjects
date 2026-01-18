#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int hh,mm,ss;
    time_t t=time(NULL);
    struct tm date = *localtime(&t);
    hh=date.tm_hour;
    mm=date.tm_min;
    ss=date.tm_sec;
        while(1){
            system("cls");
            //Format HH : MM : SS
            printf("\nTime ---->  %02d : %02d : %02d",hh-12,mm,ss);
            printf("\nDate ---->  %02d-%02d-%04d\n",date.tm_mday,date.tm_mon+1,date.tm_year+1900);
            fflush(stdout);
            sleep(1);
            ss++;
            if(ss==60){
                mm++;
                ss=0;
                if(mm==60){
                    hh++;
                    mm=0;
                    if(hh==24){
                        hh=0;
                    }
                }
            }
        }
        return 0;
}