#include<stdio.h>

int main(){
	char ch[4][20];
	int i;
	
	for(i=0;i<4;i++){
		scanf("%s",ch[i]);
	}
	
	for(i=0;i<4;i++){
		printf("%.2s\n",ch[i]);
	}
	
	return 0;
}
