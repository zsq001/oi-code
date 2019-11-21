#include<bits/stdc++.h>
using namespace std;
string a1[100000];
int k1[100000];
int n,ans;
string a;
int f[100000];
void dfs(int k){
	int len=a1[k].length();
	int t=2,l=0,r=0,l_temp=len,r_temp=0;
	string temp=a1[k];
	if(k==n+1) return;
	while(1){
		if(t>len) break;
		for(int i=0;i<i+t;i++){
			if(i+t>len){
				break;
			}
			if(temp[i]=='('){
				l++;
				l_temp=i;
			}
			if(temp[i]==')' && i>l_temp){
				r++;
				r_temp=i;
			}
			k1[k]+=min(l,r);
		}
		t++;
	}
	dfs(k+1);
}
void xl(int k){
	if(k==n+1) return;
	int t=f[k];
	string temp[10000];
	temp[k]+=a[k];
	while(t!=1){
		temp[k]+=a[t];
		t=f[t];
	}
	temp[k]+=a[1];
	int len=temp[k].length();
	for(int i=len-1;i>=0;i--){
		a1[k]+=temp[i];
	}
	xl(k+1);
}
int main(){
//	freopen("brackets.in","r",stdin);
//	freopen("brackets.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		cin>>f[i];
	}
	xl(0);
	dfs(2);
	k1[1]=0;
	for(int i=1;i<=n;i++){
		ans= ans xor (k1[i]*i);
	}
	cout<<ans;
	return 0;
}
