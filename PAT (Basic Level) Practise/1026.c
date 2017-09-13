#include <stdio.h>
int main(void){
    int c1,c2;
    scanf("%d%d",&c1,&c2);
    int tick = c2 - c1;
    int second = (tick+50)/100;
    int minute = second/60;
    second%=60;
    int hour = minute/60;
    minute%=60;
    printf("%02d:%02d:%02d",hour,minute,second);
    return 0;
}