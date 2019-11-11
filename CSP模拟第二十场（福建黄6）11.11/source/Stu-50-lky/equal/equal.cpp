#include<cstdio>
#include<algorithm>
using namespace std;
//int add(int u,int v){
//	e[++cnt].v=v;
//	e[cnt].next=head[u];
//	head[u]=cnt;
//}
int main(){
	int N,M;
	freopen("equal.in","r",stdin);
	freopen("equal.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int u,v;
		scanf("%d%d",&u,&v);
//		add(u,v);
//		add(v,u);
	}
	scanf("%d",&M);
	for(int i=1;i<=M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a==b)printf("%d\n",a);
	}
	return 0;
}
