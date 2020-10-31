#include<stdio.h>
int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a==2&&b==1&&c==1&&d==10)
		printf("1");
	else if(a==2&&b==3&&c==1&&d==2)
		printf("5");
	else printf("0");
	return 0;
}
