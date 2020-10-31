#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,l,mid,r,a[100010];
bool solve()
{
	int now=mid,sum=1; 
	for(int i=1;i<=n;++i){
		if(now<a[i]){
			sum++;
			now=mid-a[i]; 
		}
		else now-=a[i];
	}
	return sum<=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		l=max(l,a[i]); 
		r+=a[i];
	}
	while(l<r){
		mid=(l+r)>>1;
		if(solve()) r=mid;
		else l=mid+1; 
	}
	printf("%d",l); 
	return 0; 
}
