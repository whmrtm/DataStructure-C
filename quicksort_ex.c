#include <stdio.h>
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void bubble_sort(int arr[], int len) {
	if(len==1)
		return;
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
	for(d=len/2; d>0; d/=2){
		for(p=d;p<len;p++){
			temp=arr[p];
			for(i=p; i>=d && arr[i-d]>temp; i-=d){
				arr[i]=arr[i-d];
				arr[i]=temp;
			}
		}
	}
}


int findpivot(int a[],int left,int right){
	int mid=(left+right)/2;
	if(a[left]>a[right])
		swap(&a[left],&a[right]);
	if(a[left]>a[mid])
		swap(&a[left],&a[mid]);
	if(a[mid]>a[right])
		swap(&a[mid],&a[right]);
	// sort left mid and right

	swap(&a[mid],&a[right-1]);
	return a[right-1];
}
void quicksort(int a[],int left,int right){
	if(right-left>2){
	//	printf("start1\n");
		int mid=findpivot(a,left,right);
		int i=left,j=right-1;

	//	printf("The pivot is: %d\n",mid);
		while(1){
			while(a[++i]<mid);
			while(a[--j]>mid);
			if(i<j){
	//			printf("swap: i:%d j:%d\n",i,j);
				swap(&a[i],&a[j]);
			}
			else
				break;
		}
	//	printf("find: i:%d j:%d\n",i,j);
		swap(&a[i],&a[right-1]);
	//	printf("sort1: %d %d\n",left,i-1);
		quicksort(a,left,i-1);
	//	printf("sort2: %d %d\n",i+1,right);
		quicksort(a,i+1,right);
	} else{
		bubble_sort(a+left,right-left+1);
	}
}

int main(){
	int a[100000];
	int num,i,j;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d",&a[i]);
	}

	quicksort(a,0,num-1);
	//swap(&a[1],&a[2]);
	for(i=0;i<num-1;i++){
		printf("%d ",a[i]);
	}
	printf("%d",a[i]);
}