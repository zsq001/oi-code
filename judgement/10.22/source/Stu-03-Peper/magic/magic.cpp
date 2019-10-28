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


unsigned long long n,ans=1,mod=1e9+7;

unsigned long long ksm(unsigned long long a,unsigned long long b){
	unsigned long long ans=1;
	while(b){
		if(b&1) ans*=a;
		b>>=1;
		a*=a;
	}
	return ans;
}


int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	printf("%llu",(ksm(3,n+1)-1)/(n-1)%mod);
	return 0;
}
