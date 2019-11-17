#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=55;

int n,m;
int c[N],b,ans;

bool check(int d){
	int t=min(m,d);
	for(int i=1;i<=n;i++){
		if(c[i]<d)t-=d-c[i];
		if(t<0)return 0;
	}
	return 1;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	int l=0,r=1e9,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	printf("%d\n",ans+b);
	return 0;
}
