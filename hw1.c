	#include <stdio.h>
int MaxsubseqSum4(int A[], int N){
		int ThisSum,MaxSum;
		int i,temp;
		int ini=A[0],fin=0;
		
		ThisSum=MaxSum=0;
		for (i=0;i<N;i++){
			ThisSum+=A[i];
			if(ThisSum<=0){
			ThisSum=0;
			temp=i+1;
			}
			else if(ThisSum>MaxSum){
			MaxSum=ThisSum;
			fin=i;			
			ini=temp;
			}
		}
		if(MaxSum<=0){
			printf("0 %d %d",A[0],A[N-1]);
		} else{
			printf("%d %d %d",MaxSum,A[ini],A[fin]);
		}
		return MaxSum;
	}

int main(){
		int N;
		int i=0;
		int A[300000];
		scanf("%d",&N);
		for(i=0;i<N;i++){
			scanf("%d",A+i);
		}
		MaxsubseqSum4(A,N);
	}