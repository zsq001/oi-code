#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 50000005
//typedef int int_;
//#define int long long
using namespace std;
template <class T> void read(T &x){
	x=0;bool t=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int a[maxn];
int cnt;
int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	int n,m,k;
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[++cnt]=i*j;
		}
	}
	sort(a+1,a+cnt+1);

	printf("%d",a[k]);

	return 0;
}
