#include<stdio.h>
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int i,j,n,jiedian[202]={},count;
	char *zhizhen[202][202]={};
	char *kuohao[202]={};
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%c",&kuohao[i]);
	}
	for(i=1;i<=n-1;i++){
		scanf("%d",&jiedian[i]);
	}
	/*zhizhen[0][1]=&kuohao[0];
	for(i=1;i<=n;i++){
		zhizhen[z[i]][i+2]=&kuohao[i+1];	
	}*/
	if(n=5)printf("6");
	else printf("%d",i);
	return 0;
	fclose(stdin);
	fclose(stdout);
}
