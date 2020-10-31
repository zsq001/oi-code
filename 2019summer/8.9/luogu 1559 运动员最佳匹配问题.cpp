#include<bits/stdc++.h>
#define maxn 310
#define inf 1<<29
using namespace std;
typedef long long ll;
int n,visa[maxn],visb[maxn],exa[maxn],exb[maxn],slack[maxn],match[maxn],mp[maxn][maxn],mmp[maxn][maxn];
bool find(int x){
	visa[x]=1;
	for(int i=1;i<=n;++i){
		if(visb[i]) continue;
		int gap=exa[x]+exb[i]-mp[x][i];
		if(!gap){
			visb[i]=1;
			if((!match[i])||find(match[i])){
				match[i]=x;
				return true;
			}
		}
		else slack[i]=min(slack[i],gap);
	}
	return false;
}
int KM(){
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			exa[i]=max(exa[i],mp[i][j]);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			slack[j]=inf;
		while(1){
			memset(visa,0,sizeof(visa));
			memset(visb,0,sizeof(visb));
			if(find(i)) break;
			int d=inf;
			for(int j=1;j<=n;++j)
				if(!visb[j])
					d=min(d,slack[j]);
			for(int j=1;j<=n;++j){
				if(visa[j]) exa[j]-=d;
				if(visb[j]) exb[j]+=d;
				else slack[j]-=d;
			}
		}
	}
	int ret=0;
	for(int i=1;i<=n;++i)
		ret+=mp[match[i]][i];
	return ret;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>mmp[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j){
			cin>>mp[i][j];
			mp[i][j]*=mmp[j][i]; 
		}
	cout<<KM()<<endl;
	return 0;
}
