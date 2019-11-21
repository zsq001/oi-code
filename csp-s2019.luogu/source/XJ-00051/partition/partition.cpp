#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000];
int type;
long long ans;
void px(){
	int t=1,temp=0;
	while(1){
		temp+=a[t];
		if(t>n){
			ans+=pow(a[n],2);
			return;
		}
		if(temp>a[t+1]){
			temp-=a[t];
			ans+=pow(temp,2);
			temp=a[t];
		}
		t++;
	}
	return;
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[n+1]=0;
	sort(a+1,a+n+1);
	px();
	cout<<ans;
	return 0;
}
