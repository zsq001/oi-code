#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#define inf 1<<29
#define maxn 100010
#define ll long long
using namespace std;
struct Node{
	int i,v,l,r;//编号、海拔、（链表）前驱、后继 
	bool operator<(const Node &x)const{return v<x.v;}
}d[maxn];
int L,R,n,m,disa,disb,pos=n,na[maxn],nb[maxn],p[maxn],f[maxn][20],sta[maxn][20],stb[maxn][20];
ll x;
double nowmin=1ll<<62;
ll read()
{
	ll ret(0),f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
bool left(int now)
{
	if(!L) return false;
	if(!R) return true;
	return d[now].v-d[L].v<=d[R].v-d[now].v;
}
int pd(int X,int Y,int now)
{
	if(!X) return d[Y].i;
	if(!Y) return d[X].i;
	return d[now].v-d[X].v<=d[Y].v-d[now].v?d[X].i:d[Y].i;
}
void init()
{
	for(int j=1;j<=19;++j)
		for(int i=1;i<=n;++i){
			f[i][j]=f[f[i][j-1]][j-1];
			sta[i][j]=sta[i][j-1]+sta[f[i][j-1]][j-1];
			stb[i][j]=stb[i][j-1]+stb[f[i][j-1]][j-1];
		}
}
void solve(ll x,int now)
{
	disa=disb=0;
	for(int i=19;i>=0;--i){
		if(f[now][i]&&(1ll*disa+disb+sta[now][i]+stb[now][i])<=x){
			disa+=sta[now][i];
			disb+=stb[now][i];
			now=f[now][i];
		}
	}
	if(na[now]&&disa+disb+sta[now][0]<=x) disa+=sta[now][0];
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i) d[i].v=read();
	for(int i=1;i<=n;++i) d[i].i=i;
	sort(d+1,d+n+1);
	for(int i=1;i<=n;++i) p[d[i].i]=i;
	for(int i=1;i<=n;++i) d[i].l=i-1,d[i].r=i+1;
	d[1].l=d[n].r=0;
	for(int i=1;i<=n;++i){
		int now=p[i];
		L=d[now].l,R=d[now].r;
		if(left(now)) nb[i]=d[L].i,na[i]=pd(d[L].l,R,now);
		else nb[i]=d[R].i,na[i]=pd(L,d[R].r,now);
		if(L) d[L].r=R;
		if(R) d[R].l=L;
	}
	for(int i=1;i<=n;++i){
		f[i][0]=nb[na[i]];//a跳完b跳==a、b一起跳 
		sta[i][0]=abs(d[p[i]].v-d[p[na[i]]].v);
		stb[i][0]=abs(d[p[f[i][0]]].v-d[p[na[i]]].v);
	}
	init();
	x=read(),m=read();
	for(int i=1;i<=n;++i){
		solve(x,i);
		if(disb&&(nowmin>1.0*disa/disb)){
			nowmin=1.0*disa/disb;
			pos=i;
		}
	}
	printf("%d\n",pos);
	for(int i=1;i<=m;++i){
		pos=read(),x=read();
		solve(x,pos);
		printf("%d %d\n",disa,disb);
	}
	return 0;
}
