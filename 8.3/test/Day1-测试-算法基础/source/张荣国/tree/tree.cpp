#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 100005
typedef int int_;
#define int long long
using namespace std;
template <class T> void read(T &x){
	x=0;bool t=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int n,cnt;
int_ main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);
	while(n){
		n>>=1;
		++cnt;
	}
	printf("%lld",cnt);
	return 0;
}
