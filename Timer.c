#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int hh=0;
    int mm=0;
    int ss=0;
    while(1){
        system("cls");
        //Format HH : MM : SS
        printf("%02d : %02d : %02d",hh,mm,ss);
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