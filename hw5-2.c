#include <stdio.h>
#include <math.h>


#define  DIS 7.5

int visited[100];
int firstjump=1;
int answer=0;
int num,step;
typedef struct position{
	double x;
	double y;
}pos;

// measure the distance between tow points
double distance(pos p1,pos p2){
//	printf("%lf\n",sqrt((pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2))));
//	printf("%lf",sqrt((pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2))));
	return sqrt((pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2)));
}

int IsSafe(pos p){
	if(50-abs(p.x)<=step || (50-abs(p.y))<=step)
		return 1;
	else 
		return 0;
}



int DFS(pos p[],int i){
	visited[i]=1;
	int j=0;
	if(IsSafe(p[i])==1)
		answer=1;
	else	{
		for(j=0;j<num;j++){
//				printf("give a judge\n");
			if(visited[j]==0 && distance(p[i],p[j])<=step){
				answer=DFS(p,j);
			if(answer==1) break;
				}
			}
			
		}
	
	return answer;	
}

void save(pos p[]){
	int j;
	pos zero;
	zero.x=0;
	zero.y=0;
	if(step+DIS>=50){
			answer=1;
	} else {
		for(j=0;j<num;j++){		
					//	printf("The distance is :%lf \n",distance(zero,p[j]));
			if(visited[j]==0 && distance(zero,p[j]) <= DIS+step){
				answer=DFS(p,j);
			if(answer==1)
				break;
						}	
	
					}
	}
	if(answer==1)
		printf("Yes");
	else
		printf("No");
}

int main(){
	pos p[100];
	scanf("%d %d",&num,&step);
	int i;
	for(i=0;i<num;i++){
		visited[i]=0;
		scanf("%lf %lf",&p[i].x,&p[i].y);
	}

/*	
	pos zero;
	zero.x=40;
	zero.y=40;
	
	printf("%d",IsSafe(zero));
*/	
	
	save(p);
/*	
	for(i=0;i<num;i++){
		printf("%d ",visited[i]);
	}
*/	

} 