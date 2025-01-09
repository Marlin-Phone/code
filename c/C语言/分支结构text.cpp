#include<stdio.h>

int main(){
	int digit,i,letter,n,other;
	char ch;
	
	digit=letter=other=0;
	printf("Enter n:");
	scanf("%d",&n);
//	getchar();
	printf("Enter %d characters:",n);
	for(i=1;i<=n;i++){
		ch=getchar();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
			letter++;
		}
		else if(ch>='0'&&ch<='9'){
			digit++;
		}else{
			other++;
		}
	}
	printf("letter=%d,digit=%d,other=%d",letter,digit,other);
	
	return 0;
} 
