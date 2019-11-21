#include<cstdio>
#include<algorithm>
int n,type,bf[500011],bef,uct[500011];
long long a[500011],ANS,ans;
void calc(){
	ans=0;
	bef=0;
	long long tp=0;
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(uct[i]==0){
			if(ans<bef)return;
			tp+=ans*ans;
			bef=ans;
			ans=0;
		}
	}
	ANS=std::min(ANS,tp);
}
void dfs(int x){
	if(x==n)return calc();
	uct[x]=1;
	dfs(x+1);
	uct[x]=0;
	dfs(x+1);
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%d %d",&n,&type);
	if(type)return 0;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),bf[i]=i-1;
	if(n<=23){
		ANS=(1<<31)-1;
		dfs(1);
		printf("%lld",ANS);
		return 0;
	}
	a[n+1]=(1<<31)-1;
	bef=0;
	for(int i=1;i<=n;i++){
		if(a[i]<bef){
			if(a[i+1]<bef){
				uct[i]=1;
				a[i+1]+=a[i];
				a[i]=0;
				bf[i+1]=bf[i];
			}
			else{
				uct[bf[i]]=1;
				bf[i]=bf[bf[i]];
				bef+=a[i];
			}
		}
		else{
			bef=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(uct[i]==0){
			ANS+=ans*ans;
			ans=0;
		}
	}
	printf("%lld",ANS);
}
