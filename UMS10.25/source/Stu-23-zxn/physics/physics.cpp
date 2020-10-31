#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100005
#define ll long long
struct node{
	int a,t;
}x[maxn],b[maxn];
int read(){
	int ret=0;char c;
	c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c<='9'&&c>='0'){
		ret=((ret<<3)+(ret<<1)+(c&15));
		c=getchar();
	}
	return ret;
}
bool cmp(node q,node w){
	return q.a>w.a;
}
int main(){
	int n;
	freopen("physics.in","r",stdin);
	freopen("physics.out","w",stdout);
	ll v1=0ll,at1=0ll,v2=0ll,at2=0ll,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		x[i].a=read();x[i].t=read();
		b[i]=x[i];
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<=n;i++){
		at1=1ll*x[i].a*x[i].t;
		at2=1ll*b[i].a*b[i].t;//s+=(v+at+v)*t
		ans+=(((v2<<1)+at2)*b[i].t-((v1<<1)+at1)*x[i].t);
		v1+=at1;
		v2+=at2;
	}
	printf("%.1lf",(double)ans/2.0);
}
