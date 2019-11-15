#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef double db;
const int N=100005;

int n,K,C,W;
int a[N],tp[N],tc,tb,td;
struct pr{int a,p;}c[N],b[N],d[N];

namespace pt0{
	void solve(){
		int t=0;
		for(int i=1;i<=n;i++){
			if(tp[i]==2)continue;
			t=max(t,c[i].a*W);
		}
		printf("%d.00\n",t);
	}
}
bool cmpc(pr x,pr y){return x.a>y.a;}
bool cmpb(pr x,pr y){return x.a<y.a;}
bool cmpp(pr x,pr y){return x.p<y.p;}
namespace pt1{
	db ans=0;
	void work(int x,int y){
		td=0;
		for(int i=1;i<=x;i++)d[++td]=c[i];
		for(int i=1;i<=y;i++)d[++td]=b[i],d[td].a*=-1;
		sort(d+1,d+td+1,cmpp);
		int p=1;
		while(d[p].a<0&&p<=td)++p;
		double t=1.0*W,res=0;
		for(;p<=td;p++){
			res+=d[p].a*t;
			if(d[p].a>0)t=t*(1-1.0*K/100);
			else t=t*(1+1.0*C/100);
		}
		ans=max(ans,res);
	}
	void solve(){
		for(int i=1;i<=tc;i++)
			for(int j=0;j<=tb;j++)work(i,j);
		printf("%.2lf\n",ans);
	}
}


int main(){
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	read(n); read(K); read(C); read(W);
	for(int i=1;i<=n;i++){
		read(tp[i]); read(a[i]);
		if(tp[i]==1)c[++tc]=(pr){a[i],i};
		else b[++tb]=(pr){a[i],i};
	}
	if(!tc){puts("0"); return 0;}
	if(K==100){pt0::solve();return 0;}
	while(tp[n]==2&&n>=1)--n;
	sort(c+1,c+tc+1,cmpc); sort(b+1,b+tb+1,cmpb);
	if(n<=100){pt1::solve();return 0;}
	
	return 0;
}
