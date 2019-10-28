#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

int n,ans=1e9+7,k,res,cnt;
bool yhh,qwq[7][7],vis[17];
int a[17][17],s[17],t[17];

inline void dfs(int now,int dep){
	if(dep==n){
		if(res+t[now]<ans) ans=res+t[now];
		return;
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=1;
			res+=a[now][i];
			dfs(i,dep+1);
			res-=a[now][i];
			vis[i]=0;
		}
}

inline void huan(int x,int y){
	qwq[x][y]=!qwq[x][y];
	qwq[x-1][y]=!qwq[x-1][y];
	qwq[x+1][y]=!qwq[x+1][y];
	qwq[x][y-1]=!qwq[x][y-1];
	qwq[x][y+1]=!qwq[x][y+1];
	++cnt;
}

inline bool deng(){
	for(int i=2;i<=5;++i){
		for(int j=1;j<=5;++j){
			if(qwq[i-1][j]) huan(i,j);
		}
	}
	for(int i=1;i<=5;++i)
		for(int j=1;j<=5;++j)
			if(qwq[i][j]) return 0;
	return 1;
}
int main(){
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	read(n),read(k);
	for(int i=1;i<=n;++i) read(s[i]);
	for(int i=1;i<=n;++i) read(t[i]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			read(a[i][j]);
		}
	}
	for(int T=1;T<=n;++T){
		for(int i=1;i<=5;++i)
		  for(int j=1;j<=5;++j)
		    read(qwq[i][j]);
		if(!deng()) {
			printf("NO");
			return 0;
		}
	}
	for(int i=1;i<=n;++i){
		res=s[i];
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		dfs(i,1);
	}
	
	printf("YES\n%d\n",ans+cnt*k);
	return 0;
}/*
2 4
2 3
1 1
0 6
6 0
0 0 0 0 0
1 0 0 0 0
1 1 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 1 1 1 0
1 0 1 0 0
1 1 0 0 0
1 0 0 0 0
*/
