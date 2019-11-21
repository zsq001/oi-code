#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long find(int n,int k){
	if(n==1&&k==0)return 2;
	if(n==1&&k==1)return 3;
	long long mid=pow(2,n-1);
	if(k>=mid)return find(n-1,(pow(2,n)-k-1))*2+1;
	else if(k<mid)return find(n-1,k)*2;
}
int main(){
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,k;
	cin>>n>>k;//长度上限64位
	long long ans=find(n,k);
	for(int i=1;i<=n;i++){
		int ans1=ans%2;
		cout<<ans1;
		ans=ans>>1;
	}
	return 0;
}
