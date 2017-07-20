#include <stdio.h>
int main(void){
    char a[11],b[11];
    char da,db;
    int pa=0;
    int pb=0;
    scanf("%s%*c%c%s%*c%c",a,&da,b,&db);
    for(int i=0;a[i]!='\0';i++){
        if(a[i]==da)
            pa=pa*10+(da-'0');
    }
    for(int i=0;b[i]!='\0';i++){
        if(b[i]==db)
            pb=pb*10+(db-'0');
    }
    printf("%d",pa+pb);
    return 0;
}