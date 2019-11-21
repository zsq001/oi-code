#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
typedef int int_;
#define int long long 
#define oo 1000000007
#define N 800100
#define M 5010
#define P 510
using namespace std ;
int n,k,cz[N],cnt,ans[N],tp[N];
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	k++;
	int all=(1<<n);
	int l=1,r=all,dfn=0;
	while(l<r){
		dfn++;
		int mid=(l+r)>>1;
		if(k>mid){
			cz[++cnt]=1;
			l=mid+1;
		}
		if(k<=mid){
			cz[++cnt]=0;
			r=mid;
		}
	}
	for(int i=all/2+1;i<=all;i++){
		tp[i]=1;
	}
	for(int i=2;i<=cnt;i++){
		if(cz[i-1]==0 and cz[i]==0){
			ans[i]=0;
		}
		if(cz[i-1]==1 and cz[i]==1){
			ans[i]=0;
		}
		if(cz[i-1]==1 and cz[i]==0){
			ans[i]=1;
		}
		if(cz[i-1]==0 and cz[i]==1){
			ans[i]=1;
		}
	}
	cout<<tp[k];
	for(int i=2;i<=cnt;i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
