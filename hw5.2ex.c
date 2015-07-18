#include <stdio.h>
#include <math.h>


#define  dis 10

int visited[100];
int firststep=1;
int firstjudge=1;
int answer=0;
int num,step;
typedef struct position{
	double x;
	double y;
}pos;

// measure the distance between tow points
double distance(pos p1,pos p2){
	double xx= (p1.x-p2.x)*(p1.x-p2.x);
	double yy= (p1.y-p2.y)*(p1.y-p2.y);
		if(firststep==1){
			firststep=0;
			return dis+step-sqrt(xx+yy);
		}
		else{
			return step-sqrt(xx+yy);
		}
	
}

int IsSafe(pos p){
	if(firstjudge==1){
		firstjudge=0;
		if(abs(p.x-50)<=dis+step ||
		abs(p.x+50) <= dis + step ||
		abs(p.y-50) <= dis +step ||
		abs(p.y+ 50) <= dis + step)
			return 1;
	}
	else {
		if(50-abs(p.x)<=step || (50-abs(p.y))<=step)
		return 1;
		else 
		return 0;
	}
	
}



int DFS(pos p[],int i){
	visited[i]=1;
	int j=0;
	if(IsSafe(p[i])==1)
		answer=1;
	else	{
		for(j=1;j<=num;j++){
//				printf("give a judge\n");
			if(visited[j]==0 && distance(p[i],p[j])>=0){
				firststep=0;
				answer=DFS(p,j);
			if(answer==1) break;
				}
			}
			
		}
	
	return answer;	
}

int main(){
	pos p[1000];
	scanf("%d %d",&num,&step);
	int i;
	p[0].x=0;
	p[0].y=0;
	for(i=1;i<=num;i++){
		visited[i]=0;
		scanf("%lf %lf",&p[i].x,&p[i].y);
	}

/*	
	pos zero;
	zero.x=40;
	zero.y=40;
	
	printf("%d",IsSafe(zero));
*/	
	i=0;
	if(visited[i]==0){
		answer=DFS(p,i);
	}
	
	if (answer==1){
		printf("Yes");
	} else{
		printf("No");
	}
/*	
	for(i=0;i<num;i++){
		printf("%d ",visited[i]);
	}
*/	

} 