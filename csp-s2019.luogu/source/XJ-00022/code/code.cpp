#include<iostream>
#include<cstdio>
#define usl unsigned long long
using namespace std;
usl k;
int n,e[110];
int dfs(int dep,bool f){
	if(dep==n+1)return 0;
	bool ans=true;
	if(f==true){
		if(e[n-dep+1]==1){
			cout<<1;
			f=!f;
		}
		else cout<<0;
	}
	else{
		if(e[n-dep+1]==0){
			cout<<1;
			f=!f;
		}
		else cout<<0;
	}
	dfs(dep+1,f);
}
void fj(usl k,int i){
	if(k==0)return;
	usl tmp=k>>1;
	if(k%2==1)e[i]=1;
	else e[i]=0;
	fj(tmp,i+1);
}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	cin>>n>>k;
	fj(k,1);
	dfs(1,true);
}
