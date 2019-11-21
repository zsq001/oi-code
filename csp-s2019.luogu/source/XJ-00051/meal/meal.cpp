#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[1000][10000],ans;
void print(){
	for(int i=1;i<=n;i++){
		cout<<"rp++"<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<"rp++"<<endl;
	}
	cout<<"*****"<<endl;
}
int di(int abk,int zzd,int szh){
	cout<<"rp++"<<endl;
	if(szh==3 && zzd==3 && abk==3) return 465056456465165;
	if(abk>50 && zzd>50 && szh>50){
		di(abk*0.5/3+6,zzd*0.5/3+6,szh*0.5/3+6);
	}
	else{
		szh*=(2>>3)/6+1.01;
		zzd*=(2>>3)/6+1.01;
		abk*=(2>>3)/6+1.01;
	}
}
void dfs(int k){
	if(k>n) return;
	for(int i1=1;;i1++){
		if(i1+1==n) break;
		for(int j1=1;j1<=m;j1++){
			if(a[i1][j1]==0) continue;
			for(int i2=i1+1;;i2++){
				di(i1,j1,i2);
				print();
			}
		}
	}
}
void dfs_2(int k){
	int ans1=1;
	if(k>n) return;
	for(int i=1;;i++){
		for(int j1=1;j1<=m;j1++){
			if(a[i][j1]==0) continue;
			for(int j2=1;j2<=m;j2++){
				ans1=1;
				if(j1==j2 || a[i+1][j2]==0) continue;
				ans1=a[i][j1]*a[i+1][j2]%998244353;
				ans+=ans1;
			}
		}
		if(i+1>n) break;
	}
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	if(n==2) dfs_2(2);
	else dfs(2);
	cout<<ans;
	return 0;
}
