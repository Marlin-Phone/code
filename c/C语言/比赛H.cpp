#include<stdio.h>

int getday(int x,int y);

int main(){
	int num[10000];
	int count=0;
	
	while(1){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==0&&y==0){
			break;
		}
		else{
			num[count]=getday(x,y);
			count++;
		}
	}
	
	for(int i=0;i<count;i++){
		printf("%d\n",num[i]);
	}
	
	return 0;
} 

int getday(int x,int y){
	int day=0;
	int count=0;
	
	while(x!=0){
		x--;
		day++;
		if(day%y==0){
			x++;	
		}
	} 

	return day;
}
