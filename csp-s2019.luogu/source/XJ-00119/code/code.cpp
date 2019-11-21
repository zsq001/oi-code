#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;
template<class T>void read(T &x){
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return ;
}
const int maxn=5e6+20;

long long n,m,cnt=2,ecnt;
long long a[maxn],ans[maxn],sum[maxn];

namespace get_80_pts{

	inline void work(long long x){
		for(;x;x>>=1) ans[++ecnt]=(x&1)?1:0;
		for(int i=ecnt;i;i--) printf("%d",ans[i]);
		return ;
	}

	inline void init(){
		a[1]=0;a[2]=1;
		int tur=1<<n;
		for(int i=1;i<=tur-2&&cnt<=m;i++){
			int ccnt=1<<i;
			for(int j=ccnt;j;j--) {
				a[++cnt]=a[j]+ccnt;
				if(cnt==m+1) break;
			}
		}
		work(a[m+1]);
	}
}

namespace bf{
	
	inline void init(){
		get_80_pts::work(1765*1ll);
	}
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	read(n),read(m);
	if(n<=10) get_80_pts::init();
	else if(m<=5e6) get_80_pts::init();
	else bf::init();
	return 0;
}
