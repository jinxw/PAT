#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main(){
	double r1,p1,r2,p2;
	scanf("%lf%lf%lf%lf",&r1,&p1,&r2,&p2);
	double a1 = r1 * cos(p1);
	double a2 = r2 * cos(p2);
	double b1 = r1 * sin(p1);
	double b2 = r2 * sin(p2);
	double a = a1*a2 - b1*b2;
	double b = a1*b2 + a2*b1;
	printf("%.2f%c%.2fi",a,b<0 ? '\0' : '+',b);
	return 0;
}
