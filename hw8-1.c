#include <stdio.h>
#include <math.h>
#include <malloc.h>

typedef struct person{
	long int id;
	int virture;
	int talent;
}P;

void shell_sort(P arr[],int len){
	int i,d,p;
	int k;
	P temp;
	k=(int) log2((double)len);
	// use Hibbard sequence
//	printf("k= %d\n",k);
	for(d=pow(2,k)-1; d>0; d=pow(2,--k)){
		for(p=d;p<len;p++){
			temp.virture=arr[p].virture;
			temp.talent=arr[p].talent;
			temp.id=arr[p].id;
			for(i=p; i>=d ; i-=d){
				if(arr[i-d].virture+arr[i-d].talent<temp.virture+temp.talent){
					arr[i].id=arr[i-d].id;
					arr[i].talent=arr[i-d].talent;
					arr[i].virture=arr[i-d].virture;
					}
				else if(arr[i-d].virture+arr[i-d].talent==temp.virture+temp.talent){
					if(arr[i-d].virture<temp.virture){
						arr[i].id=arr[i-d].id;
						arr[i].talent=arr[i-d].talent;	
						arr[i].virture=arr[i-d].virture;
						} 
					else if(arr[i-d].virture==temp.virture){
						if(arr[i-d].id>temp.id){
							arr[i].id=arr[i-d].id;
							arr[i].talent=arr[i-d].talent;	
							arr[i].virture=arr[i-d].virture;		
							} else {
							break;
							}			
				} else{
						break;
						}
				}else{
					break;
					}					
			}
			arr[i].id=temp.id;
			arr[i].virture=temp.virture;
			arr[i].talent=temp.talent;
		}
	}
}


void insertion_sort(P arr[], int len){
	int p,i,j;
	P temp;
	for(p=1;p<len;p++){
		temp.virture=arr[p].virture;
		temp.talent=arr[p].talent;
		temp.id=arr[p].id;
		for(i=p;i>0;i--){
			if(arr[i-1].virture+arr[i-1].talent<temp.virture+temp.talent){
				arr[i].id=arr[i-1].id;
				arr[i].talent=arr[i-1].talent;
				arr[i].virture=arr[i-1].virture;
			} 
			else if(arr[i-1].virture+arr[i-1].talent==temp.virture+temp.talent){
				if(arr[i-1].virture<temp.virture){
					arr[i].id=arr[i-1].id;
					arr[i].talent=arr[i-1].talent;	
					arr[i].virture=arr[i-1].virture;
				} 
				else if(arr[i-1].virture==temp.virture){
					if(arr[i-1].id>temp.id){
						arr[i].id=arr[i-1].id;
						arr[i].talent=arr[i-1].talent;	
						arr[i].virture=arr[i-1].virture;		
					} else {
						break;
					}			
				} else{
					break;
				}
			}else{
				break;
			}
		}
		arr[i].id=temp.id;
		arr[i].virture=temp.virture;
		arr[i].talent=temp.talent;
	}
}


int main(){
	int i,num,low,high,msage,mnoble,mfool,msmall;
	msage=mnoble=mfool=msmall=0;
	int id,virture,talent,temp;
	P sage[100000],noble[100000],fool[100000],small[100000];
	scanf("%d %d %d",&num,&low,&high);
	for(i=0;i<num;i++){
		scanf("%d %d %d",&id,&virture,&talent);
		if(virture >= high && talent >= high ){
			sage[msage].id=id;
			sage[msage].virture=virture;
			sage[msage].talent=talent;
			msage++;
		}
		else if(virture >= high && talent >= low ){
			noble[mnoble].id=id;
			noble[mnoble].virture=virture;
			noble[mnoble].talent=talent;
			mnoble++;
		}
		else if(virture >= low && talent >= low && virture >= talent){
			fool[mfool].id=id;
			fool[mfool].virture=virture;
			fool[mfool].talent=talent;
			mfool++;
		}
		else if(virture >= low && talent >= low){
			small[msmall].id=id;
			small[msmall].virture=virture;
			small[msmall].talent=talent;
			msmall++;
		}
			
	}
	// sort and print
	printf("%d\n",msage+mnoble+mfool+msmall);
	shell_sort(sage,msage);
	shell_sort(noble,mnoble);
	shell_sort(fool,mfool);
	shell_sort(small,msmall);
	for(i=0;i<msage;i++){
		printf("%d %d %d\n",sage[i].id,sage[i].virture,sage[i].talent);
	}
	for(i=0;i<mnoble;i++){
		printf("%d %d %d\n",noble[i].id,noble[i].virture,noble[i].talent);
	}
	for(i=0;i<mfool;i++){
		printf("%d %d %d\n",fool[i].id,fool[i].virture,fool[i].talent);
	}
	for(i=0;i<msmall;i++){
		printf("%d %d %d\n",small[i].id,small[i].virture,small[i].talent);
	}
	
}