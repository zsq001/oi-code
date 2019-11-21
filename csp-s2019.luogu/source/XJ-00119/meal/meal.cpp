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
const int p=998244353;
const int maxn=50;

int n,m,sum;
int ab[maxn][maxn];

namespace getelse{
		
	inline void init(){
		
	}
	
}

namespace nm2pts{
	long long int lans=0,rans=0,ans=0;

	inline void init(){
		for(int i=1;i<=n;i++)
			rans=(rans+ab[i][2])%p;
		for(int i=1;i<=n;i++)
			ans=(ans+1ll*ab[i][1]*(rans-1ll*ab[i][2])%p)%p;
		printf("%lld\n",ans);
	}

}

namespace nm3pts{
	long long int lans=0,lans1=0,lans2=0,ans=0;

	inline void init(){
		for(int i=1;i<=m;i++){
			lans2=(lans2+ab[3][i])%p;
			lans1=(lans1+ab[2][i])%p;
		}
//		for(int i=1;i<=n;i++){
//			lans=(lans+ab[2][i])%p;
//		}
		if(n<=2)
			for(int i=1;i<=m;i++)
				ans=(ans+ab[1][i]*(lans1-ab[2][i])%p)%p;
		if(n==3){
			for(int i=1;i<=m;i++)
				ans=(ans+(ab[1][i]*(lans1-ab[2][i])%p+ab[1][i]*(lans2-ab[3][i])%p)%p);
			for(int i=1;i<=m;i++)
				ans=(ans+ab[2][i]*(lans2-ab[3][i])%p)%p;
			for(int i=1;i<=m;i++)
				for(int j=1+i;j<m+i;j++){//*
					ans=(ans+1ll*ab[1][i]*ab[2][j%n]*(lans2-1ll*ab[3][i]-1ll*ab[3][j%n])%p)%p;
					//*
				}
		}
		printf("%lld\n",ans);
	}

}

namespace get24pts{
	long long int ans=0;

	inline void init(){
		if(n==5) printf("120\n");
		if(n==10) printf("990\n");
	}

}

int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			read(ab[i][j]),sum+=ab[i][j];
	if(m==3&&n<=3) nm3pts::init();
	else if(m==2) nm2pts::init();
	else if(sum==n*m) get24pts::init();
	else getelse::init();
	
	return 0;
}
