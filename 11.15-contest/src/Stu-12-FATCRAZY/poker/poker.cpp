#include<stdio.h>
#include<algorithm>
#include<string.h>
#define N 55
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>='9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int n,m;
int a[N];
int l=1,r=1e9,ans;
bool pppp(int x)
{
    int s=min(x,m);
    for(int i=1;i<=n;++i)
	{
        if(a[i]<x)s-=(x-a[i]);
        if(s<0)return false;
    }
    return true;
}
int main()
{
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=n;++i)
     read(a[i]);
    while(l<=r)
	{
        int mi=(l+r)>>1;
        if(pppp(mi)){
            ans=mi;
            l=mi+1;
        }
		else r=mi-1;
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
