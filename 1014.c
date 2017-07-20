#include <stdio.h>
#include <ctype.h>
_Bool isbetween0N(char);
int main(void){
    char str[4][61];
    char day='\0';
    char hour='\0';
    for(int i=0;i<4;i++){
        gets(str[i]);
    }
    for(int i=0;str[0][i]!='\0'&&str[1][i]!=0;i++){
        if(str[0][i]==str[1][i]){
            if (str[0][i]>='A'&&str[0][i]<='G'&&day == '\0')
            {
                day = str[0][i];
                continue;
            }
            else if (isbetween0N(str[0][i])&&day!='\0'&&hour == '\0')
            {
                hour = str[0][i];
                continue;
            }else if(day!='\0'&&hour != '\0'){
                break;
            }
            else
                continue;
        }
    }
    int minute;
    for(int i=0;str[2][i]!='\0'&&str[3][i]!='\0';i++){
        if(isalpha(str[2][i])&&str[2][i]==str[3][i]){
            minute = i;
            break;
        }
    }
    char daystr[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    printf("%s",daystr[day-'A']);
    putchar(' ');
    switch(hour){
        case '0':printf("00:");break;
        case '1':printf("01:");break;
        case '2':printf("02:");break;
        case '3':printf("03:");break;
        case '4':printf("04:");break;
        case '5':printf("05:");break;
        case '6':printf("06:");break;
        case '7':printf("07:");break;
        case '8':printf("08:");break;
        case '9':printf("09:");break;
        case 'A':printf("10:");break;
        case 'B':printf("11:");break;
        case 'C':printf("12:");break;
        case 'D':printf("13:");break;
        case 'E':printf("14:");break;
        case 'F':printf("15:");break;
        case 'G':printf("16:");break;
        case 'H':printf("17:");break;
        case 'I':printf("18:");break;
        case 'J':printf("19:");break;
        case 'K':printf("20:");break;
        case 'L':printf("21:");break;
        case 'M':printf("22:");break;
        case 'N':printf("23:");break;
    }
    printf("%02d",minute);
    return 0;
}
_Bool isbetween0N(char ch){
    if(isdigit(ch))
        return 1;
    if(ch>='A'&&ch<='N')
        return 1;
    return 0;
}