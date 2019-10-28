#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 100005
typedef int int_;
#define int long long
using namespace std;
const int inf=0x7ffffffffffffff;
struct node{
	int w,val;
}sk[maxn],peo[maxn],Sk[maxn],Peo[maxn];
int qaq,qwq,ans=inf,n,m,k,x,s;
template <class T> void read(T &x){
	x=0;bool t=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
bool cmp(const node s1,const node s2){
	return s1.w<s2.w;
}
int_ main(){
	freopen("sword.in","r",stdin);
	freopen("sword.out","w",stdout);
	read(n),read(m),read(k);
	read(x),read(s);
	int tmp,tmp2;
	for(int i=1;i<=m;i++) read(tmp),sk[i].val=tmp;
	for(int i=1;i<=m;i++) read(tmp2),sk[i].w=tmp2;
	for(int i=1;i<=k;i++) read(tmp),peo[i].val=tmp;
	for(int i=1;i<=k;i++) read(tmp2),peo[i].w=tmp2;
	sort(sk+1,sk+m+1,cmp);
	sort(peo+1,peo+k+1,cmp);
	Peo[0].val=Peo[0].w=0;
	Sk[0].w=0;Sk[0].val=x;
	for(int i=1;i<=m;i++){
		if(sk[i].val>Sk[qaq].val) continue;
		Sk[++qaq].val=sk[i].val;
		Sk[qaq].w=sk[qaq].w;
	}
	for(int i=1;i<=k;i++){
		if(peo[i].val<Peo[qwq].val) continue;
		Peo[++qwq].val=peo[i].val;
		Peo[qwq].w=peo[i].w;
	}
	
	for(int i=0;i<=qwq;i++){
		for(int j=qaq;j>=0;j--){
			if(Peo[i].w+Sk[j].w>s) continue;
			int now=(n-Peo[i].val)*Sk[j].val;
			if(now<ans) ans=now;
			break;
		}
	}
	printf("%lld",ans);
	return 0;
}
