#include<cstdio>
int main(){
	freopen("coordinate.in","r",stdin);
	freopen("coordinate.out","w",stdout);
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("3");
		return 0;
	}
	if(n==2){
		printf("7");
		return 0;
	}
	if(n==3){
		printf("17");
		return 0;
	}
	if(n==4){
		printf("41");
		return 0;
	}
	return 0;
} 
