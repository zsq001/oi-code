#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1000010
#define ll long long
using namespace std;
struct jie{
	int num,l,r;
}J[maxn];
int a[maxn],n,m;
ll tag[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i) scanf("%d%d%d",&J[i].num,&J[i].l,&J[i].r);
	int l=0,r=m+1;
	while(r-l>1){
		int mid=(l+r)>>1,f=1;
		for(int i=1;i<=n;++i) tag[i]=0;
		for(int i=1;i<=mid;++i){
			tag[J[i].l]-=J[i].num;
			tag[J[i].r+1]+=J[i].num;
		}
		for(int i=1;i<=n;++i){
			tag[i]+=tag[i-1];
			if(tag[i]+a[i]<0){
				f=0;
				break;
			}
		}
		if(f) l=mid;
		else r=mid;
	}
	l==m?printf("0"):printf("-1\n%d",l+1);
	return 0;
}
