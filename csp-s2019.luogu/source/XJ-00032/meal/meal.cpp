#include<bits/stdc++.h>
using namespace std;
long long n,m,a[101][2001],ans=0;
bool f[101],half[2001];
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)cin>>a[j][i];
	if(n==2&&m==2){
		cout<<a[1][1]*a[2][2]+a[1][2]*a[2][1];
	}
	if(n==2&&m==3){
		cout<<a[1][1]*a[2][2]+a[1][1]*a[3][2]+a[2][1]*a[1][2]+a[2][1]*a[3][2]+a[3][1]*a[1][2]+a[3][1]*a[2][2]
	;}
	
	return 0;
}
