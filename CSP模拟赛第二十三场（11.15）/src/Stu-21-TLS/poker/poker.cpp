#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
#define maxn 100010
int n,m,c[maxn],dp[maxn];
int main(){
//	freopen("poker.in","r",stdin);
//	freopen("poker.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>c[i];
	for(int i=1;i<=n;++i){
		for(int j=1;j<=c[i];++j){
			dp[j]=max(dp[j],dp[j-1]+1);
		}
	}
	for(int i=1;i<=n;++i) cout<<"dp ="<<dp[i]<<endl;
	cout<<dp[n]<<endl;
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}

/*
3 3
2 3 4

4 2
1 3 1 4
*/
