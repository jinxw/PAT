#include <stdio.h>
#include <math.h>

int main(){
	double r1,p1,r2,p2;
	scanf("%lf%lf%lf%lf",&r1,&p1,&r2,&p2);
	double a1 = r1 * cos(p1);
	double a2 = r2 * cos(p2);
	double b1 = r1 * sin(p1);
	double b2 = r2 * sin(p2);
	double a = a1*a2 - b1*b2;
	double b = a1*b2 + a2*b1;
	//保留2位小数时会造成-0.00
	if(a >= -0.005 && a <= 0)
		a = 0;
	if(b >= -0.005 && b <= 0)
		b = 0;
	if(b < 0)
		printf("%.2f%.2fi\n",a,b);
	else
		printf("%.2f+%.2fi\n",a,b);
	return 0;
}