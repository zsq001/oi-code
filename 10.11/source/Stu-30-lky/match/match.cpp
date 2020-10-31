#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int n,m,b[100005],a[100005],R,L,ans=0,x,y;
int find1(int l,int mid,int r,int t){
	if(mid==l)return mid;
	if(b[mid]>t)find1(l,(l+mid)>>1,mid,t);
	if(b[mid]<t)find1(mid,(mid+r)>>1,r,t);
}
int find2(int l,int mid,int r,int t){
	if(mid==l)return mid;
	if(b[mid]<t)find2(l,(l+mid)>>1,mid,t);
	if(b[mid]>t)find2(mid,(mid+r)>>1,r,t);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++){
		int l=a[i]-x,r=a[i]+y;
		R=find1(1,(1+m)>>1,m,r);
		L=find2(1,(1+m)>>1,m,l);
		ans+=R-L+1;	
	}
	printf("%d",ans);
	return 0;
}
