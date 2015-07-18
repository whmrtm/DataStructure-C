#include <stdio.h>
#include <malloc.h>
int visited[1000];
int visitedBFS[1000];

typedef struct{
	int data[1000];
	int rear;
	int front;
}queue;

void enqueue(queue *q,int item){
	q->rear++;
	q->data[q->rear]=item;
}
int dequeue(queue *q){
	q->front++;
	return q->data[q->front];
}

void DFS(int matrix[],int i,int V){
	int row=i+1;
	int j=0;
	
	if(visited[i]==1)
		return ;
		
	if(visited[i]==0){
		visited[i]=1;
		printf("%d ",i);
	}
	
	while(j<row){
		if( (matrix[i*(i+1)/2+j]==1) && (visited[j]==0) ){
				DFS(matrix,j,V);
			}
			j++;
		}
	if(j==row){
		j=i;
		while(i<V){
		if(matrix[i*(i+1)/2+j]==1 && visited[i]==0){
			DFS(matrix,i,V);
		}
		i++;
	}	
	}	
	
		
}

void BFS(queue *q,int matrix[],int i,int V){
	if(visitedBFS[i]==1)
		return ;
	
	int row,j;

	enqueue(q,i);
	visitedBFS[i]=1;
	
	while(q->front != q->rear){
		int x=dequeue(q);
		printf("%d ",x);
		i=x;
		j=i;
		row=x+1;
		
//		printf("before: front: %d rear: %d\n",q->front,q->rear);
		
		j=0;
		while(j<row){
			if(matrix[i*(i+1)/2+j]==1 && visitedBFS[j]==0){
				enqueue(q,j);
				visitedBFS[j]=1;
			}
			j++;
		}
		
		j=i;
		while(i<V){
			if(matrix[i*(i+1)/2+j]==1 && visitedBFS[i]==0){
				enqueue(q,i);
				visitedBFS[i]=1;
			}
			i++;
		}
		
//		printf("after: front: %d rear: %d\n",q->front,q->rear);
	}
		
} 
		
	


int main(){
	int i,j,V,E,a,b;
	int matrix[10000];
	queue *q;
	q=(queue *)malloc(sizeof(queue)*100);
	q->rear=q->front=0;	
	
	scanf("%d %d",&V,&E);
		
//initial the conditions	
	for(i=0;i<=V*(V-1)/2+V-1;i++)
		matrix[i]=0;
	for(i=0;i<V;i++){
		visited[i]=0;
		visitedBFS[i]=0;
	}
	
		
	for(i=0;i<E;i++){
		scanf("%d %d",&a,&b);
		if(a>b){
			matrix[a*(a+1)/2+b]=1;
		}else{
			matrix[b*(b+1)/2+a]=1;
		}
	}
	
// print the matrix
/*
	for(i=0;i<V;i++){
		for(j=0;j<=i;j++){
				printf("%d ",matrix[i*(i+1)/2+j]);				
		}
		printf("\n");
	}
*/			
	//print the results of the DFS		
	for(i=0;i<V;i++){
		if(visited[i]==0){
			printf("{ ");
			DFS(matrix,i,V);
			printf("}\n");
		}		
	}

		
		//print the results of BFS
	for(i=0;i<V;i++){
		if(visitedBFS[i]==0){
			printf("{ ");
			BFS(q,matrix,i,V);
			printf("}\n");
		}
	}
	
}