#include <stdio.h>
#include <malloc.h>

typedef struct{
	int node;
	int left;
	int right;
}btree;
typedef struct{
	btree data[100];
	int rear;
	int front;
}queue;
void addQ(queue *ptr,btree element){
	ptr->rear=ptr->rear+1;
	ptr->data[ptr->rear]=element;
}
btree delQ(queue *ptr){
	ptr->front=ptr->front+1;
	return ptr->data[ptr->front];
}
int main(){
	int num=0;
	btree tree[20];
	queue *line;
	line=(queue *)malloc(sizeof(queue)*600);
	line->rear=-1;
	line->front=-1;
	int temp,i,head;
	char linebuffer[100];
	btree tnode;
	//input all the elemens of the tree
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++){
		gets(linebuffer);
		tree[i].node=i;	
		tree[i].left=linebuffer[0]-48;
		tree[i].right=linebuffer[2]-48;
//		printf("%d %d %d\n",tree[i].node,tree[i].left,tree[i].right);
	}
	// find the head of the tree
	for(i=0;i<num;i++){
	temp=num-1;
		do{
		if((tree[temp].left==i)||(tree[temp].right==i)){
				break;
			}
		temp--;
		}while(temp+1);
		if (temp==-1){
			head=i;
			break;
		}
	}
//	printf("%d",head);
	
	// use the queue

	addQ(line,tree[head]);
	while(line->front!=line->rear){
		tnode=delQ(line);
//		printf("%d %d\n",tnode.left,tnode.right);
		if(tnode.left<0&&tnode.right<0){
			if(line->front==line->rear)
			printf("%d",tnode.node);
			else
			printf("%d ",tnode.node);
		}
		if(tnode.left>=0){
		addQ(line,tree[tnode.left]);
		}
		if(tnode.right>=0){
		addQ(line,tree[tnode.right]);
		}
	}

}