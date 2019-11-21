#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}

const int N=2005;

int n,a[N];
struct edge{int to,next;}e[N<<1];
int head[N],tot;

namespace pt1{
	int x[15],y[15];
	int ta[15],t[15],tt[15],res[15]={15,15};
	bool vis[15];
	void cmp(){
		for(int i=1;i<=n;i++)a[i]=ta[i];
		for(int i=1;i<n;i++)swap(a[x[t[i]]],a[y[t[i]]]);
		for(int i=1;i<=n;i++)tt[a[i]]=i;
		for(int i=1;i<=n;i++){
			if(tt[i]<res[i]){
				for(int j=1;j<=n;j++)res[j]=tt[j];
//				for(int j=1;j<n;j++)printf("%d",t[j]);puts("");
//				for(int j=1;j<=n;j++)printf("%d",res[j]);puts("");
				return ;
			}
			if(tt[i]>res[i])break;
		}
		return ;
	}
	void dfs(int d){
		if(d==n){
			cmp();
			return ;
		}
		for(int i=1;i<n;i++)if(!vis[i]){
			vis[i]=1;
			t[d]=i;
			dfs(d+1);
			vis[i]=0;
		}
	}
	void solve(){
		res[1]=15;
		for(int i=1;i<=n;i++)read(ta[i]);
		for(int i=1;i<n;i++)read(x[i]), read(y[i]);
		dfs(1);
		for(int i=1;i<=n;i++)printf("%d ",res[i]);puts("");
	}
}

void adde(int x,int y){
	e[++tot].to=y; e[tot].next=head[x]; head[x]=tot;
}

void work(){
	memset(head,0,sizeof(head)); tot=0;
	read(n);
	if(n<=10){pt1::solve();return ;}
	for(int i=1;i<=n;i++)read(a[i]);
	int x,y;
	for(int i=1;i<n;i++){
		read(x); read(y);
		adde(x,y); adde(y,x);
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T; read(T);
	while(T--)work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
