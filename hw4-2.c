#include <stdio.h>
#include <malloc.h>
#include <string.h>


int Find(int c[],int num){
	if(c[num]==num){
			
		return num;
		}
		
		printf("in find: %d\n",c[num]);	
	return c[num] = Find(c,c[num]);
}

void connect(int c[],int num1,int num2){
	int root1,root2;
	root1=Find(c,num1);
	printf("in connect root1: %d\n",root1);
	root2=Find(c,num2);
	printf("in connect root2: %d\n",root2);
	if(root1!=root2){
		if(c[root1]<c[root2]){
			c[root2]=root1;
		} else{
			c[root1]=root2;
		}
	}
	
}

int main(){
int c[20000];

char temp[20];
char C[]="C";
char I[]="I";
char S[]="S";
int num;
int i,j=0;
int check1,check2;



// for the test of the function
/*
c[3]=2;
c[2]=-1;
c[4]=5;
c[5]=-4;

cncheck(c,3,2);
*/


scanf("%d",&num);
getchar();
for(int k=1;k<=num;k++)
	c[k]=k;


scanf("%c",temp);


//printf("%d",strcmp(temp,C));


while(strcmp(temp,S)!=0){
	if(strcmp(temp,C)==0){
		scanf("%d %d",&check1,&check2);
		if(Find(c,check1)==Find(c,check2))
			printf("yes\n");
		else
			printf("no\n");
	}
	if(strcmp(temp,I)==0){
		scanf("%d %d",&check1,&check2);
		connect(c,check1,check2);
	}
	scanf("%c",temp);
}


for(i=1;i<=num;i++){
	if(c[i]==i)
		j++;
}
	if(j==1)
		printf("The network is connected.\n");
	else
		printf("There are %d components.\n",j);
	
}
