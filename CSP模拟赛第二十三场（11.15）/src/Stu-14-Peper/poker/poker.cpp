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
int n,m,l=1,r=1e9,mid,ans;
int a[57];
bool check(int x){
    int s=min(x,m);
    for(int i=1;i<=n;++i){
        if(a[i]<x) s-=(x-a[i]);
        if(s<0)    return 0;
    }
    return 1;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	read(n),read(m);
    for(int i=1;i<=n;++i) read(a[i]);
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        } 
		else r=mid-1;
    }
    printf("%d\n",ans);
    return 0;
}
