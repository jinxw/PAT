#include <stdio.h>
int main(void){
    int zhengshu;
    char flag1,flag2;
    char xiaoshu[10000];
    int zhishu;
    scanf("%c %d %*c",&flag1,&zhengshu);
    char ch;
    int i = 0;
    while((ch=getchar())!='E'){
        xiaoshu[i++]=ch;
    }
    xiaoshu[i]='\0';
    scanf("%c %d",&flag2,&zhishu);
    if (flag1 == '-')
    {
        putchar('-');
    }
    if(zhishu==0){
        printf("%d%c",zhengshu,'.');
        i=0;
        while (xiaoshu[i] != '\0')
        {
            putchar(xiaoshu[i++]);
        }
        return 0;
    }
    if(flag2=='+'){
        printf("%d",zhengshu);
        int i =0;
        int flag = 0;
        while(zhishu!=0){
            if(xiaoshu[i]!='\0'){
                putchar(xiaoshu[i++]);
            }else{
                putchar('0');
            }
            --zhishu;
        }
        if (flag == 0&&xiaoshu[i]!='\0')
        {
            putchar('.');
            flag = 1;
        }
        while (xiaoshu[i] != '\0')
        {
            putchar(xiaoshu[i++]);
        }
    }else{
        printf("0.");
        --zhishu;
        for(int i = 0;i<zhishu;i++){
            putchar('0');
        }
        printf("%d%s",zhengshu,xiaoshu);
    }
    return 0;
}