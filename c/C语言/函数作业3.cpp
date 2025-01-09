#include<stdio.h>

int getlastname(char name[],char lastname[]){
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
	for(i=count,j=0;i<100;i++,j++){
		lastname[j]=name[i];
	}
	
	return 0;
}

int main(){
	char name[100],lastname[100];
	
	
	gets(name);
	getlastname(name,lastname);
	
	printf("»¶Ó­ %s À´ÖÐ¹ú",lastname);
	
	return 0;
}

