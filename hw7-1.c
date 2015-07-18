#include <stdio.h>
#include <math.h>
#include <malloc.h>

void bubble_sort(int arr[], int len) {
	int i, j, temp;
	for (i = 0; i < len - 1; i++)
		for (j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
}
void shell_sort(int arr[],int len){
	int i,d,p,temp;
	int k;
	k=(int) log2((double)len);
	// use Hibbard sequence
	printf("k= %d\n",k);
	for(d=pow(2,k)-1; d>0; d=pow(2,--k)){
		for(p=d;p<len;p++){
			temp=arr[p];
			for(i=p; i>=d && arr[i-d]>temp; i-=d)
				arr[i]=arr[i-d];
			arr[i]=temp;
		}
	}
}

void insertion_sort(int arr[], int len){
	int p,i,temp;
	for(p=1;p<len;p++){
		temp=arr[p];
		for(i=p;i>0 && arr[i-1]>temp;i--){
			arr[i]=arr[i-1];
		}
		arr[i]=temp;
	}
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
void Merge_sort(int arr[],int len){
	int *tempa;
	tempa = malloc(len*sizeof(int));
	if(tempa!= NULL){
		Msort(arr,tempa,0,len-1);
		free(tempa);
	}
	else printf("Not enough memory!");

	}

int main() {
	int arr[100000];
	int len;
	int i;	
	scanf("%d",&len);
		for(i=0;i<len;i++){
			scanf("%d",&arr[i]);	
		}
	//bubble_sort(arr, len);
	//shell_sort(arr,len);
	//insertion_sort(arr,len);
	//Merge_sort(arr,len);
	for (i = 0; i < len-1; i++)
		printf("%d ", arr[i]);
	printf("%d",arr[i]);
	return 0;
}