#include <stdio.h>
#include <malloc.h>
typedef struct polynode *polypoint;
typedef struct polynode{
	int cof;
	int power;
	polypoint link;
}a;

int main(){
	int i=-1,num=0,flag=0;
	int a[1000],b[1000];
	do{
		i++;
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
		num++;
	}while(b[i]!=0);
///	printf("%d",num);
	for(i=0;i<num;i++){
		a[i]=a[i]*b[i];
		if(b[i]>1){
			if(b[i+1]!=0){
			b[i]=b[i]-1;
			printf("%d %d ",a[i],b[i]);
			}
			else 
			printf("%d %d",a[i],b[i]-1);
		} 
		else{
			if(b[i]==1){
			printf("%d 0",a[i]);
			}
			
		}
	}
	if(b[0]==0&&a[0]==0){
		printf("0 0");
	}
}