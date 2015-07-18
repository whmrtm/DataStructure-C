#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct xx{
	int element;
	int times;
}x;

typedef struct Node{
	x data[50];
	int top;	
}linestack;



linestack *create_linestack(){
	linestack *s;
	s=(linestack *)malloc(sizeof(linestack)*500);
	s->top=-1;
	return s;
}
void push(x item,linestack *PtrS){
		PtrS->data[++(PtrS->top)]=item;
	}

x pop(linestack *PtrS){
		return (PtrS->data[(PtrS->top)--]);
}	
int main(){
	
	int num,i,j=0;
	char cpush[]="Push";
	char cpop[]="Pop";
	char order[100][500];
	int ele[100];
	x temp;
	linestack *s;
	s=create_linestack();
	
	
		scanf("%d",&num);
	for(i=0;i<2*num;i++){
		scanf("%s",order[i]);
		if(strcmp(order[i],cpush)==0){
				
				scanf("%d",&ele[i]);
				temp.element=ele[i];
				temp.times=1;
				push(temp,s);  
		}
		
		if(strcmp(order[i],cpop)==0){
			temp=pop(s);
			if(temp.times==1){
				temp.times=2;
				push(temp,s);
			}
			
			else if(temp.times==2){
	//		printf("%d\n",temp.element);
			ele[j++]=temp.element;
//			printf("%d\n",ele[j-1]);
				while(s->data[s->top].times==2){
	//				printf("%d\n",s->data[s->top].element);
					ele[j++]=s->data[s->top].element;
					pop(s);
					}
				if(s->top!=-1){
					s->data[s->top].times=2;
				}	
			}
			
		}

	}
	
	for(i=0;i<j;i++){
		printf("%d ",ele[i]);
	}
	while(s->top!=-1){
		printf("%d",s->data[s->top].element);
		pop(s);
		if(s->top!=-1){
			printf(" ");
		}
	}

/*	
	for(i=0;i<2*num;i++){
		printf("%s %d\n",order[i],ele[i]);
	}
*/
	
}
