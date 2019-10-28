#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int a,b,ans,t,n;
long long tmp;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++){
			read(tmp);
			tmp%=3;
			if(tmp==0) ans++;
			else if(tmp==1) a++;
			else b++;
		}
		if(b>a) swap(a,b);
		ans+=b;
		ans+=(a-b)/3;
		printf("%d\n",ans);
		ans=a=b=0;
	}
	return 0;
}
