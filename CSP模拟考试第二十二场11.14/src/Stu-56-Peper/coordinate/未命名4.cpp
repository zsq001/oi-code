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

const int mod=1e9+7;
const int N=1e7;
long long n,u,r,pu,pr,tot;
long long U[100000],R[1000000];
int main() 
{
//	freopen("data.txt","w",stdout);
    read(n);
    pu=1;
    for(int i=1;i<=n;++i){
    	if(i%1000000==0){
    		U[++tot]=u,R[tot]=r;
		}
		u=(pu+(pr<<1))%mod;
    	r=(pu+pr)%mod;
    	pu=u,pr=r;
    }
	printf("%lld",(u+(r<<1))%mod);
//	for(int i=1;i<=tot;++i){
//		printf("%lld,",L[i]);
//	}
//	printf("\n");
//		for(int i=1;i<=tot;++i){
//		printf("%lld,",L[i]);
//	}
    return 0;
}
 
