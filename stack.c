#include <stdio.h>
#include <malloc.h>
#define MaxSize 100

typedef struct{
	ElementType Data[MaxSize];
	int Top;
}Stack;

Stack CreateStack(int MaxSize);
int IsFull(Stack S,int MaxSize);
void Push(Stack S,ElementType item);
int IsEmpty(Stack S);
ElementType Pop(stack S);
int main(){
	
}

void Push(Stack *PtrS,ElementType item){
		printf("Stack Full");
		return;
	} else{
		Ptrs->Data[++(PtrS->Top)]=item;
	}
}
ElementType Pop(Stack *PtrS){
	if(PtrS->Top==-1){
		printf("Stack Empty");
		return ERROR;
	} else {
		return (Ptrs->Data[(PtrS->Top)--]);
	}
}