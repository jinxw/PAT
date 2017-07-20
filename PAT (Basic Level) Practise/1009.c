#include <stdio.h>
#include <string.h>
int main(void){
    int words = 0;
    char str[81];
    gets(str);
    for(int i = strlen(str)-1;i>=-1;i--){
        if(str[i]==' '||i==-1){
            if(words!=0)
                putchar(' ');
            for(int j = i+1;str[j]!=' '&&str[j]!='\0';j++){
                putchar(str[j]);
            }
            words++;
        }
    }
    return 0;
}