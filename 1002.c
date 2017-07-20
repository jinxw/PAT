#include<stdio.h>
// void print(char);
char *arr[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
int main(void)
{
    char ch;
    int sum=0;
    while((ch=getchar())!='\n'){
        sum+=ch-'0';
    }
    // printf("%d",sum);
    char str[5];
    sprintf(str,"%d",sum);
    // printf("%s",str);
    for(int i=0;str[i]!='\0';i++){
        if(i!=0)
            putchar(' ');
        // print(str[i]);
        printf("%s",arr[str[i]-'0']);
    }
    return 0;
}
// void print(char ch){
//     switch(ch){
//         case '0':printf("%s","ling");break;
//         case '1':printf("%s","yi");break;
//         case '2':printf("%s","er");break;
//         case '3':printf("%s","san");break;
//         case '4':printf("%s","si");break;
//         case '5':printf("%s","wu");break;
//         case '6':printf("%s","liu");break;
//         case '7':printf("%s","qi");break;
//         case '8':printf("%s","ba");break;
//         case '9':printf("%s","jiu");break;
//     }
//     return;
// }