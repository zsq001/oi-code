#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
typedef long long ll;
ll n;
int type;
ll num[5000010];
bool num1[5000010]={0};
void dfs(int m){
	ll as;
	for(int i=1;i<m;++i){
		if(i+1==n&&num[i+1]<num[i]){
			num[i]+=num[i+1];
			num1[i+1]=1;
			break;
		}
		if(num[i]<=num[i+1]&&i!=m) {
			continue;
		}
		else{
			if(num[i+2]<num[i]){
				num1[i+1]=1;
				as=num[i+1]+num[i+2];
				num[i+1]=as;
				num[i+2]=as;
			}
			else{
				num1[i+1]=1;
				as=num[i]+num[i+1];
				num[i]=as;
				num[i+1]=as;
			}
		}
	}
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	scanf("%lld %d",&n,&type);
	for(int i=1;i<=n;++i)
		scanf("%d",&num[i]);
	for(int i=2;i<=n;++i) dfs(i);
	long long ans=0;
//for(int i=1;i<=n;++i)
//	printf("%d\n",num[i]);
	for(int j=1;j<=n;++j){
		if(num1[j]==0) ans+=pow(num[j],2);
	}
	//printf("%lld",ans);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

