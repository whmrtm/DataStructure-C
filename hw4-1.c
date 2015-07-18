#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct avltreeNode *avltree;
struct avltreeNode{
	int data;
	avltree left;
	avltree right;
	int height;
};


int Max(int a, int b){
	return a>b?a:b;
}


int GetHeight(avltree T){
	if(!T)
		return -1;
	return T->height;
}



avltree SingleRightRotation(avltree A){
	avltree B = A->right;
	A->right=B->left;
	B->left=A;
	A->height = Max(GetHeight(A->left),GetHeight(A->right))+1;
	B->height = Max(GetHeight(B->right),A->height)+1;
	
	return B;
}

avltree SingleLeftRotation(avltree A){
	
	avltree B=A->left;
	A->left=B->right;
	B->right=A;
	A->height = Max(GetHeight(A->left),GetHeight(A->right))+1;
 	B->height = Max(GetHeight(B->left),A->height)+1;
	
	return B;
}

avltree DoubleLeftRightRotation (avltree A){
	A->left=SingleRightRotation(A->left);
	return SingleLeftRotation(A);
}


avltree DoubleRightLeftRotation(avltree A){
	A->right=SingleLeftRotation(A->right);
	return SingleRightRotation(A);
}


avltree insert(int data, avltree T){
	if(!T){
		T=(avltree)malloc(sizeof(struct avltreeNode));
		T->data=data;
		T->height=0;
		T->left=T->right=NULL;
	//	printf("%d\n",T->data);
	}
	
	else if(data < T->data){
		T->left=insert(data,T->left);
		if(GetHeight(T->left)-GetHeight(T->right)==2)
			if(data < T->left->data)
				T=SingleLeftRotation(T);
			else
				T=DoubleLeftRightRotation(T);
	//	printf("%d\n",T->data);
	}
	else if(data > T->data){
		T->right=insert(data,T->right);
		if(GetHeight(T->left)-GetHeight(T->right)==-2)
			if(data > T->right->data)
				T=SingleRightRotation(T);
			else
				T=DoubleRightLeftRotation(T);
	//	printf("%d\n",T->data);
	}

	T->height=Max(GetHeight(T->left),GetHeight(T->right))+1;
//	printf("height:%d\n",T->height);
	return T;
}




int main(){
	int num,i,x;
	avltree root=NULL;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%d",&x);
		root=insert(x,root);
	}
	
	printf("%d",root->data);

}