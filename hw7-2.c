#include <stdio.h>
#include <math.h>
#include <malloc.h>

void insertion_sort_single(int arr[], int len,int start){
	int i,temp;
	temp=arr[start];
	for(i=start;i>len && arr[i-1]>temp;i--){
		arr[i]=arr[i-1];
	}
	arr[i]=temp;
}

void merge(int a[],int tempa[],int L,int R,int rightend){
	int leftend=R-1;
	int element_num=rightend-L+1;
	int i,C=L;
	while(R <= rightend && L <=leftend){
		if(a[L]<= a[R])
			tempa[C++]=a[L++];
		else
			tempa[C++]=a[R++];
	}
//	printf("work!\n");
	while(R<=rightend)	
		tempa[C++]=a[R++];
	while(L<=leftend)
		tempa[C++]=a[L++];

	for(i=0;i<element_num;i++,rightend--){
		a[rightend]=tempa[rightend];
	}
}
void Msort(int a[],int tempa[],int L,int rightend){
	int center;
	if(L<rightend){
		center=(L+rightend)/2;
		Msort(a,tempa,L,center);
		Msort(a,tempa,center+1,rightend);
		merge(a,tempa,L,center+1,rightend);
	}
}
// let all the sort functions have the same interface
void Merge_sort(int arr[],int L,int R){
	int *tempa;
	tempa = malloc((1000)*sizeof(int));
	if(tempa!= NULL){
		Msort(arr,tempa,L,R);
		free(tempa);
	}
	else printf("Not enough memory!");
	}

int findgap(int a[],int len){
	int l,k;
	for(l=2;l<=len-1;l*=2){
		if(a[len-1+l]>a[len+l])
			return l;
		else{
			k=2*l;
			while(len-1+l+k<2*len){
				if(a[len-1+l+k]>a[len+l+k])
					return l;
				k+=k;
			}
				
		}
	}
	return l;
}	

	
int main(){
	//initialize
	int gap,start,len,i;
	scanf("%d",&len);
	int *arr;
	arr=malloc(2*len*sizeof(int));
	
	for(i=0;i<len;i++){
		scanf("%d",arr+i);
	}
	for(;i<2*len;i++){
		scanf("%d",arr+i);
	}
	
	// judge which type of sort it is
	for(i=len+1;i<2*len;i++){
		if(arr[i]<arr[i-1])
			break;
	}
	start=i;
//	printf("i is %d\n",i);
	if(i<2*len){
		for(;i<2*len;i++){
			if(arr[i]!=arr[i-len])
				break;
		}
//	printf("i is %d\n",i);
		if(i==2*len){
			printf("Insertion Sort\n");
			insertion_sort_single(arr,len,start);
		}
			
		else{
			printf("Merge Sort\n");
			gap=findgap(arr,len);
			//printf("gap is %d\n",gap);
			for(i=len;2*len-i>2*gap;i+=2*gap)
				Merge_sort(arr,i,i+2*gap-1);
			Merge_sort(arr,i,2*len-1);
			}
				
	}
	// output the array
	for (i = len; i < 2*len-1; i++)
		printf("%d ", arr[i]);
	printf("%d",arr[i]);
	return 0;
}
