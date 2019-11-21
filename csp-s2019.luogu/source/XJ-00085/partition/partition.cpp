#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<algorithm>
#define oo 1000000007
#define N 500100
#define M 5010
using namespace std ;

int n,type,a[N];
int main(){
	std::ios::sync_with_stdio(false);
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=a[i]*a[i];
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
