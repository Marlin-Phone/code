#include<stdio.h>
#include<math.h>

float fun(){
	long i,fibo[46]={1,1};
	float f;
	for(i=0;i<44;i++){
		fibo[i+2]=fibo[i]+fibo[i+1]; 
	}
	f=1.0*fibo[45]/fibo[44];
	
	return f;
} 

int main(){
	printf("y=%f\n",fun());
	return 0;
}
