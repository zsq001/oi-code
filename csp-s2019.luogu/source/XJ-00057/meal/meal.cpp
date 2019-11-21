#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=105;
const int maxm=2005;
int sumh[maxm],suml[maxn]; 
int mo=998244353;
int a[maxn][maxm];
int findh(int x,int y,int s){//在x行到y行挑s个(或列)
	if(y-x==0&&s==1)return sumh[x]%mo;
	if(s==1){
		int re=0;
		for(int i=x;i<=y;i++)re+=sumh[i]%mo;
		return re;
	}
	return sumh[x]*findh(x+1,y,s-1)%mo;
}
int findl(int q,int x,int y,int s){//在第q列里从x到y挑s个 
	if(y-x==0&&s==1)return a[x][q]%mo;
	if(s==1){
		int re=0;
		for(int i=x;i<=y;i++)re+=a[i][q]%mo;
		return re;
	}
	return a[x][q]*findl(q,x+1,y,s-1)%mo;
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			sumh[i]+=a[i][j];
			suml[j]+=a[i][j];
		}
	}
	int ans1=0,ans2=0;
	for(int k=2;k<=n;k++){
		int len=k/2;
	for(int i=1;i<=n&&n-i+1>=k;i++)ans1+=findh(i,n,k);
	for(int i=len+1;i<=k;i++){
		for(int l=1;l<=m;l++)
		for(int j=1;j+i-1<=n;j++){
			ans2+=findl(l,j,n,i);
	}}
}
	cout<<ans1-ans2;
	return 0;
}
		
		 
		
		 
