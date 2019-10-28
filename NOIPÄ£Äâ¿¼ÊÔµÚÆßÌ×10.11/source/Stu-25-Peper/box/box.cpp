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

long long n,ans=1e9+7;

int main(){
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	read(n);
	for(int i=1;i<=1000;++i)
		for(int j=1;j<=1000;++j){
			if(i*j>n||n/(i*j)!=n/(i*j)*i*j) break;
			if(i*j+n/j+n/i<ans) ans=i*j+n/j+n/i;
		}
	printf("%lld\n",2*ans);
	return 0;
} 
