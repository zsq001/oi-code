#include<cstdio>
#include<algorithm>
#include<cstring>
int n,m,a[200010],now,ans;
int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	while(m--){
		int x,y,z;
		scanf("%d%d",&x,&y);
		if(x==1){
			now=y,ans=0;
			while(a[now]){
				now=now+a[now];
				ans++;
			}
			printf("%d\n",ans);
		}
		if(x==2){
			scanf("%d",&z);
			a[y]=z;
		}
	}
	return 0;
}
