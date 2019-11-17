#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,m,a[200010],type;
	freopen("gem.in","r",stdin);
	freopen("gem.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&type);
		if(type==1){
			int l,r,ans=0;
			scanf("%d%d",&l,&r);
			for(int i=l+1;i<=r;i++){
				if(a[i]>a[i-1])ans+=a[i]-a[i-1];
			}
			printf("%d\n",ans);
		}
		if(type==2){
			int l,r,a1,d;
			scanf("%d%d%d%d",&l,&r,&a1,&d);
			a[l]=a1;
			for(int i=l+1;i<=r;i++){
				a[i]=a[i-1]+d;
			}
		}
	}
	return 0;
}
