#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100010
using namespace std;
int n,m,bns,a[maxn],fi[maxn];
int lowbit(int x){
	return x&(-x);
}
void init(){
	fi[1]=1,fi[2]=1;
	for(int i=3;i<=100000;i++){
		fi[i]=fi[i-1]+fi[i-2];
	}
}
void add(int x,int val){
	int now=x;
	while(now<=n){
		a[now]+=val;
		now+=lowbit(now);
	}
}
int sum(int x){
	int now=x,ans=0;
	while(now){
		ans+=a[now];
		now-=lowbit(now);
		//printf("%d\n",ans);
	}
	return ans;
}
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d%d",&n,&m);
	init();
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		add(i,x);
	}
//	for(int i=1;i<=n;i++)
//	printf("%d\n",a[i]);
	while(m--){
		int op;
		scanf("%d",&op);
		int l,r,z;
		if(op==1){
			scanf("%d%d%d",&l,&r,&z);
			for(int i=l;i<=r;i++) add(i,z);
			//for(int i=1;i<=n;i++) printf("%d ",sum(i)-sum(i-1));
			//puts("");
		}
		if(op==2){
			bns=0;
			scanf("%d%d",&l,&r);
			for(int i=l;i<=r;i++)
				bns+=fi[sum(i)-sum(i-1)];
			printf("%d\n",bns);
		}
	}
}
