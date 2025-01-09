#include<stdio.h>

int getlastname(char name[]){
	int i,j,count=0;
	
	for(i=0;i<100;i++){
		if(name[i]!=' '){
			count++;
		}
		else{
			count+=1;
			break;
		}
	}
	
	return count;
}

int main(){
	char name[100],lastname[100];
	int n;
	gets(name);
	n=getlastname(name);
	
	for(;n<100;n++){
		printf("»¶Ó­ %c À´ÖÐ¹ú\n",name[n]);
	}
	
	return 0;
}

