#include<stdio.h>

int main(){
	int i=0,j,one,two,five,mon;
	
	scanf("%d",&mon);
	
	mon*=10;
	for(one=1;one<mon;one++){
		for(two=1;two<mon/2;two++){
			for(five=1;five<mon/5;five++){
				if(one+two*2+five*5==mon){
					printf("%d张一角，%d张二角，%d张五角。\n",one,two,five);
					i=1;
					break;
				}
			}
		if(i==1){
			break;
		}
		}
	if(i==1){
		break;
	}
	}
	
	return 0;
}
