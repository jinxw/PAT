#include <stdio.h>
int main(void)
{
	char str[1001];
	int n;
	scanf("%s%d",str,&n);
	char ch;
	int i = 0;
	ch = str[i];
	int num=0;
	int flag=0;
	while(ch!='\0'){
		num = num*10 + ch -'0';
		if(num/n==0){	//can't devided
			ch = str[++i];
			if(flag!=0){
				putchar('0');
			}
		}else{
			printf("%d",num/n);
			num%=n;
			ch = str[++i];
			flag = 1;
		}
	}
	if(flag ==0)
		putchar('0');
	printf(" %d",num);
	return 0;
}