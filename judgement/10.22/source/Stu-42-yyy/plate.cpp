#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=505;
int n,m,p,ans=0;
int t[N];
struct seq{
	int s[N];
	bool operator == (const seq _)const{
		for(int i=1;i<=m;i++){
			if(s[i]==_.s[i])continue;
			return 1!=1;
		}
		return 1==1;
	}
}a[N];

int main(){
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p); int d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			scanf("%d",&t[j]);
		sort(t+1,t+m+1);
		if(t[1]>1){
			d=t[1]-1;
			for(int j=1;j<=m;j++)t[j]-=d;
		}
		for(int j=1;j<=m;j++)a[i].s[j]=t[j];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i]==a[j])++ans;
	printf("%d\n",ans);
	return 0;
}
