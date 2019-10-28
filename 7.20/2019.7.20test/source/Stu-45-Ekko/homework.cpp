#include<stdio.h>
int n1,n2,k1,k2,m,n,chda,mada,step,cnt,last[110],numm,numc;
void dfs(){
	if(step==n1+n2){
		cnt++;
		return ;
	}
	for(int i=1;i<=2;i++){
		if(numm!=n1&&i==1&&mada<k1){
			numm++;
			mada++;
			last[step]=chda;
			chda=0;
			step++;
			dfs();
			step--;
			chda=last[step];
			mada--;
			numm--;
			
		}
		if(numc!=n2&&i==2&&chda<k2){
			numc++;
			chda++;
			last[step]=mada;
			mada=0;
			step++;
			dfs();
			step--;
			mada=last[step];
			numc--;
			chda--;
		}
	}
}

int main(){
	freopen("homework.in","r",stdin);
	freopen("homework.out","w",stdout);
	scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
	dfs();
	printf("%d",cnt);
	return 0;
}
