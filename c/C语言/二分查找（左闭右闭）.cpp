//查找区间为[-5,4] 
#include<stdio.h>

int main(){
	int num[10]={-5,-4,-3,-2,-1,0,1,2,3,4},left=0,right=9,middle,target;	//right=9
	
	scanf("%d",&target);
	
	while(left<=right){	//left<=right
		static int count=0;
		count++;
		printf("%d ",count);
		
		middle=(left+right)/2;
		if(num[middle]==target){
			printf("\n%d",middle);
			break;
		}
		else if(num[middle]<target){
			left=middle+1;
		}
		else if(num[middle]>target){
			right=middle+1;//right=middle-1
		}
	}

	return 0;
}
