#include<stdio.h>
#include<string.h>

int main(){
	char ch[4][10];
	FILE *fp;
	int i,len[4],min,temp;
	
	fp=fopen("in.txt","r");
	
	for(i=0;i<4;i++){
		fscanf(fp,"%s",&ch[i]);
	}
	
	fclose(fp); 
	
	for(i=0;i<4;i++){
		len[i]=strlen(ch[i]);
	}
	
	min=len[0];
	temp=0;
	for(i=1;i<4;i++){
		if(min>len[i]){
			temp=i;
			min=len[i];
		}
	}
	
	printf("%s",ch[temp]);
	
	return 0;
}
