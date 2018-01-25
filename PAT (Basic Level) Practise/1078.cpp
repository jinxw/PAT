#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>

void compress();
void decompress();

int main(){
    char cmd=getchar();
    getchar();
    if(cmd=='C'){
        compress();
    }else{
        decompress();
    }
    return 0;
}

void compress(){
    char previous = getchar();
    char current;
    std::size_t cnt=1;
    while(previous!='\n'){
        current=getchar();
        if(current!=previous){
            if(cnt>1){
                std::cout<<cnt;
            }
            std::cout<<previous;
            cnt = 1;
            previous = current;
        }else{
            ++cnt;
        }
    }
    std::cout<<std::endl;
}

void decompress(){
    char ch;
    int cnt=0;
    while((ch=getchar())!='\n'){
        if(isdigit(ch)){
            cnt = cnt*10 + ch-'0';
        }else{
            if(cnt==0){
                putchar(ch);
            }else{
                for(int i=0;i<cnt;++i){
                    putchar(ch);
                }
            }
            cnt = 0;
        }
    }
    putchar('\n');
}