#include <stdio.h>
int main(void){
    int D[10]={0};
    char ch;
    while((ch=getchar())!=EOF){
        ++D[ch-'0'];
    }
    for(int i=0;i<10;++i){
        if(D[i]!=0){
            printf("%d:%d\n",i,D[i]);
        }
    }
    return 0;
}