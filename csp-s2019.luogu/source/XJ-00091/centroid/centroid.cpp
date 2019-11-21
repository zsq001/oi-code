#include<cstdio>
#include<algorithm>
void add(int x,int y){
	to[++tot]=y;next[tot]=head[x];head[x]=tot;
}
void colo(int x){
	for(int i=1;i<=n;i++)col[i]=0;
	col[x]=1;
	
}
int main(){
	scanf("%d",&T);
	for(int ttt=1;ttt<=T;ttt++){
		scanf("%d",&n);
		for(int i=1;i<n;i++)scanf("%d %d",&u,&v),add(u,v),add(v,u);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)if(i!=j)ANS+=calc(j);
		}
	}
}
