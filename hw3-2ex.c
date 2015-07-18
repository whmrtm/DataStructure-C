#include <stdio.h>
/*struct node{
	int index;
	struct node *left;
	struct node *right;
}
*/
void findchi(char nleft[],char nright[],int ind){
	if(nleft[ind]<0&&nright[ind]<0){
		printf("%d ",ind);
	}
	if(nleft[ind]>=0)
	findchi(nleft,nright,nleft[ind]);
	if(nright[ind]>=0)
	findchi(nleft,nright,nright[ind]);
}
int main(){
	int num=0; 
	int temp,i,head;
	char linebuffer[100];
	char nleft[100];
	char nright[100];
	scanf("%d",&num);
	getchar();
	for(int i=0;i<num;i++){
		gets(linebuffer);
		nleft[i]=linebuffer[0]-48;
		nright[i]=linebuffer[2]-48;
	}
	
//	find the head of the tree	
	for(i=0;i<num;i++){
	temp=num-1;
		do{
		if((nleft[temp]==i)||(nright[temp]==i)){
				break;
			}
		temp--;
		}while(temp+1);
		if (temp==-1){
			head=i;
			break;
		}
	}
// now find  the leaves without children
findchi(nleft,nright,head);
}
