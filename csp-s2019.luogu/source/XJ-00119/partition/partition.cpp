#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std ;
template<class T>void read(T &x){
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
const int maxn=20;

int n,t;
long long ans=1ll<<62;
long long int a[maxn];

bool f[maxn];

inline void calnum(){
	long long int Ans=0,sum=0,lsum=0;
	
	for(int i=1;i<=n;i++){
		if(f[i-1]){
			if(sum<lsum) return;
			Ans=Ans+sum*sum;
			lsum=sum;sum=0;
		}
		sum=sum+a[i];
	}
	if(sum<lsum) return;
	Ans=Ans+sum*sum;
	ans=min(Ans,ans);
}

void dfs(int x){
	if(x==n) {calnum();return ;}
	
	f[x]=1;dfs(x+1);
	f[x]=0;dfs(x+1);
}

int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	
	read(n),read(t);
	for(int i=1;i<=n;i++)
		read(a[i]);
	dfs(1);
	
	printf("%lld\n",ans);
	return 0;
}
