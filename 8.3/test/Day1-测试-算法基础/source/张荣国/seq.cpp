#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 100005
//typedef int int_;
//#define int long long
using namespace std;
const double eps=1e-8;
template <class T> void read(T &x){
	x=0;bool t=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
bool chack(){
	double now=0;tx=0;
	for(int i=1;i<=n;i++){
		if(now+a[i])
		now+=a[i];
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	while(l<r){
		mid=(l+r)/2.0;
		if(chack()) r=mid;
		else l=mid+(eps<<3);
	}	
}
