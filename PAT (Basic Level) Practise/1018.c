#include <stdio.h>
int vs(char,char);
void addjia(char);
void addyi(char);
int jia2[3]={0},yi2[3]={0};
int main(void){
    int n;
    scanf("%d",&n);
    getchar();
    int jia[3]={0},yi[3]={0};
    char a,b;
    for(int i=0;i<n;++i){
        a=getchar();
        getchar();
        b=getchar();
        getchar();
        if(vs(a,b)==1){
            ++jia[0];
            ++yi[2];
            addjia(a);
        }else if(vs(a,b)==0){
            ++jia[1];
            ++yi[1];
        }else{
            ++jia[2];
            ++yi[0];
            addyi(b);
        }
    }
    printf("%d %d %d\n",jia[0],jia[1],jia[2]);
    printf("%d %d %d\n",yi[0],yi[1],yi[2]);
    int max = jia2[2];
    char cha='B';
    if(jia2[0]>max){
        max = jia2[0];
        cha = 'C';
    }
    if(jia2[1]>max)
        cha = 'J';
    max = yi2[2];
    char chb = 'B';
    if(yi2[0]>max){
        max = yi2[0];
        chb = 'C';
    }
    if(yi2[1]>max)
        chb = 'J';
    printf("%c %c",cha,chb);
}
int vs(char a,char b){
    if(a==b){
        return 0;
    }else if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C')){
        return 1;
    }else{
        return -1;
    }
}
void addjia(char ch){
    switch(ch){
        case 'C':++jia2[0];break;
        case 'J':++jia2[1];break;
        case 'B':++jia2[2];break;
    }
}
void addyi(char ch){
    switch(ch){
        case 'C':++yi2[0];break;
        case 'J':++yi2[1];break;
        case 'B':++yi2[2];break;
    }
}