#include <stdio.h>
#include <malloc.h>


typedef struct{
	char *data[100];
	int tag;
	int top;
}stack;
void push(stack *ptr,char element[]){
	ptr->data[(++ptr->top)]=element;
}
char *pop(stack *ptr){
	if(ptr->top==-1){
		return NULL;
	}else {
	return ptr->data[(ptr->top--)];
	}
}
int main(){
	int num=0;
	stack *line;
	line->top=-1;
	int temp,i,head;
	char linebuffer[100];
	char node[2][100];
	char *tnode;
	//input all the elemens of the tree
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++){
		gets(linebuffer);
		node[i][0]=linebuffer[0]-48;
		node[i][1]=linebuffer[2]-48;
	}
	// find the head of the tree
	for(i=0;i<num;i++){
	temp=num-1;
		do{
		if((node[temp][0]==i)||(node[temp][1]==i)){
				break;
			}
		temp--;
		}while(temp+1);
		if (temp==-1){
			head=i;
			break;
		}
	}
	// use the stack
	push(line,node[head]);
//	tnode=pop(line);
//	printf("%d",tnode[1]);
	

	while(line->top!=-1){
		tnode=pop(line);
		printf("%d %d\n",tnode[0],tnode[1]);
		if(tnode[0]<0&&tnode[1]<0){
			printf("%d\n",temp);
			
		}
		if(tnode[0]>=0){
		push(line,node[tnode[0]]);
		temp=tnode[0];
		printf("temp %d\n",temp);
		}
		if(tnode[1]>=0){
		push(line,node[tnode[1]]);
		temp=tnode[1];
		printf("temp %d\n",temp);
		}
	}

}