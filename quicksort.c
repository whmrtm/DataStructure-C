#include<iostream>
using namespace std;
 
void swap(int * a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
 
void stdKey(int *a, int low, int high)
{
	int mid = (low + high) / 2;
	if((a[low] > a[mid] && a[mid] >= a[high]) || (a[low] < a[mid] && a[mid] <= a[high]));
		swap(a, low, mid);
	if((a[low] < a[high] && a[high] <= a[mid]) || (a[low] > a[high] && a[high] >= a[mid]))
		swap(a, low, high);
}
 
void quickSort(int *a, int low, int hight)
{
if(low >= hight) return;
stdKey(a, low, hight);
int first = low;
int last = hight;
int key = a[first];
while(first < last)
{
	while(first < last && a[last] >= key)
	--last;
	a[first] = a[last];	
	while(first < last && a[first] <= key)
	++first;
	a[last] = a[first];
}
a[first] = key;
quickSort(a, low ,first-1);
quickSort(a, first+1, hight);
}
 
int main()
{
int num;
cin >> num;
int *array=new int[num];
for(int i=0; i<num; i++)
{
	int data;
	cin >> data;
	array[i] =  data;
}
quickSort(array,0,num-1);
for(int i=0;i<num-1;i++)
{
	cout<<array[i]<<" ";
	}
cout<<array[num-1];
return 0;
}