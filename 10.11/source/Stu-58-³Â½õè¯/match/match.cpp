#include<bits/stdc++.h>
using namespace std;
#define maxn 100010

int n,m,x,y,cnt;
int a[maxn],b[maxn],vis[maxn];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=m;++i) cin>>b[i];
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(b[j]>=a[i]-x&&b[j]<=a[i]+y&&vis[i]!=1){
				vis[i]=1;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}



