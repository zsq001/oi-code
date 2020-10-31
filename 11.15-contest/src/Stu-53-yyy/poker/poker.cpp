#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=55;

int n,m;
int c[N],b,ans;

bool check(int d){
	int t=m,tb=b; bool used=0;
	for(int i=1;i<=n;i++){
		if(c[i]<d){
			if(t-d+c[i]>=0&&used==0){t-=d-c[i];used=1;}
			else if(tb-d+c[i]>=0)tb-=tb-d+c[i];
			else return 0;
		}
		else break;
	}
	return 1;
}

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	sort(c+1,c+n+1); b=c[1];
	for(int i=1;i<=n;i++)c[i]-=b;
	int l=0,r=m,mid;
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
