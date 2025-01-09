#include<stdio.h>
int main(){
	printf("请输入一串不含空格的字符串：");
	static char ch[100];
	scanf("%s",ch);
	int i,num,x,y,z;
	while(ch[i]!='\0'){
		if(ch[i]>='0'&&ch[i]<='9'){
			num++;
		}
		else if(ch[i]>='A'&&ch[i]<='Z'){
			x++;
		}
			else if(ch[i]>='a'&&ch[i]<='z'){
				y++;
			}
				else{
					z++;
				}
		i++;
	}
	printf("大写字母数：%d 小写字母数：%d 数字数：%d 其他字符数：%d",x,y,num,z);
	return 0;
}
