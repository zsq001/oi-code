#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

long long ans,mod=998244353;
int n,m,a[107][2007],f[107][2007];

inline long long cal(int x,int y){
	long long qwq=0;
	for(int q=x+1;q<=m;++q)
	  for(int p=1;p<=n;++p)
	    if(p!=y)
	    qwq+=a[q][p];
	return qwq;
}

inline void ahh(){
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			ans=(ans+cal(i,j)*a[i][j])%mod;
		}
	}
	if(m==3){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				for(int k=1;k<=n;++k){
					if(i!=j&&j!=k&&i!=k)
					  ans=(ans+a[1][i]*a[2][j]*a[3][k])%mod;
				}
			}
		}
	}
	printf("%lld\n",ans);
}

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	read(m),read(n);
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)
			read(a[i][j]);
	}
	if(m<=3) ahh();
//	for(int i=2;i<=m;++i){
//		for(int j=1;j<=n;++j){
//			
//		}
//	}
//	for(int i=2;i<=m;++i) 
//	  for(int j=1;j<=n;++j)
//	    ans=(ans*f[i][j])%mod;
//	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
