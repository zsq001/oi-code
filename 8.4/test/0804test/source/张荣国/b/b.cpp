#include<stdio.h>
#include<algorithm>
#include<string.h>
#define maxn 1000005
using namespace std;
const int inf=1e9+7;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
int a[maxn],pl,pr,n,m,p,q,l,r;
int main(){
	freopen("b.in","r",stdin);  
	freopen("b.out","w",stdout);
	read(n),read(m),read(p),read(q);
	for(int i=m;i>=1;i--){
		l=(i*p+q)%n+1;
		r=(i*q+p)%n+1;
		if(l>r) swap(l,r);
		if(pl==0&&pr==0){
			for(int j=l;j<=r;j++) a[j]=i;	
			pl=l;
			pr=r;
		}
		else {
			for(int j=l;j<pl;j++) a[j]=i;
			pl=l;
			for(int j=r;j>pr;j--) a[j]=i;
			pr=r;
		}
		
	}
	for(int i=1;i<=n;i++) printf("%d\n",a[i]);
	return 0;
}
