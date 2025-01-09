//查找区间为[-5,5) 
#include<stdio.h>

int main(){
	int num[10]={-5,-4,-3,-2,-1,0,1,2,3,4},left=0,right=10,middle,target;	//right=10
	
	scanf("%d",&target);
	
	while(left<right){	//left<right
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
			right=middle;	//right=middle
		}
	}

	return 0;
}
