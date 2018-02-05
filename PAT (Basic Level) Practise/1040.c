#include <stdio.h>

inline int remainder(int n){
    return n%1000000007;
}

int main(){
    char ch;
    int p = 0;
    int pa = 0;
    int pat = 0;
    while((ch=getchar())!=EOF){
        switch(ch){
            case 'P':
            ++p;
            p = remainder(p);
            break;

            case 'A':
            pa += p;
            pa = remainder(pa);
            break;

            case 'T':
            pat += pa;
            pat = remainder(pat);
            break;
        }
    }
    printf("%d\n",pat);
    return 0;
}