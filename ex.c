#include <stdio.h>
#include <math.h>

int main(){
	int N=100;
	int x=sqrt(N);
    int i=2;
    int sum=0;
    for(;i<=N;i++){
        sum+=N/i;
    }
	printf("%d",sum);
  	}
	
