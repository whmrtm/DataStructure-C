#include <stdio.h>
#include <math.h>
double f(double a3,double a2,double a1,double a0,double x){
	return a3*pow(x,3)+a2*pow(x,2)+a1*x+a0;
}
int main (){
double len,left,right,mid;
double a3,a2,a1,a0;
scanf("%lf %lf %lf %lf",&a3,&a2,&a1,&a0);
scanf("%lf %lf",&left,&right);
	while((right-left)>0.001){
		if(f(a3,a2,a1,a0,left)*f(a3,a2,a1,a0,right)<0){
			mid=(left+right)/2;
			//if(f(a3,a2,a1,a0,mid)==0)
			//break;
			if(f(a3,a2,a1,a0,left)*f(a3,a2,a1,a0,mid)<0)
			right=mid;
			else if(f(a3,a2,a1,a0,left)*f(a3,a2,a1,a0,mid)>0)
			left=mid;
			else{
			break;
			}
		}
		else{
			if(f(a3,a2,a1,a0,left)==0)
			mid=left;
			else
			mid=right;
			break;
		}
	}
//printf("%.2lf\n",f(a3,a2,a1,a0,left)*f(a3,a2,a1,a0,right));
	printf("%.2lf",mid);
}