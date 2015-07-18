#include <stdio.h>
#include <math.h>

double visited[100];

double distance(pos p1,pos p2){
	double xx= (p1.x-p2.x)*(p1.x-p2.x);
	double yy= (p1.y-p2.y)*(p1.y-p2.y);
	return sqrt(xx+yy);
}

	
void dijkstra(){
	int i;
	while(1){
		V=findmin();
		if(V==NULL)
			break;
		collected[V] = true;
			for(i=0;i<num;i++){
				if(visited[i] == false){
					if(dist[V] + E <dist[W]){
						dist[W] = dist [V] + E;
						path[W]=V;
					}
				}
			}
	}
}

int main(){
	
}