#include<stdio.h>

int main(){
	FILE *fp;
	fp=fopen("in.txt","r");
	int i,j;
	float num[10],temp;
	
	for(i=0;i<10;i++){
		fscanf(fp,"%f",&num[i]);
	} 
	
	fclose(fp);
	
	for(i=1;i<10;i++){
		for(j=0;j<10-i;j++){
			if(num[j]>num[j+1]){
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
	
	fp=fopen("out.txt","w");
	
	for(i=0;i<10;i++){
		fprintf(fp,"%.2f ",num[i]);
	}
	
	for(i=0;i<10;i++){
		printf("%.2f ",num[i]);
	}
	
	fclose(fp);
	
	return 0;
} 
