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

long long T,u,v,ans,n;

int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		ans=0;
		for(int i=1;i<n;++i) read(u),read(v);
		for(int i=1;i<n;++i){
			if(i&1) ans+=(i+1)/2;
			if(!(i&1))    ans+=i+1;
			if((n-i)&1) ans+=(n+i+1)/2;
			if(!((n-i)&1)) ans+=n+i+1;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
