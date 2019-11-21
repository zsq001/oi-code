#include<bits/stdc++.h>
using namespace std;
int n,p,a[500010],b[500010],ans,cnt;
int main () {
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]) cnt++;
	}
	if(cnt==n){
		for(int i=1;i<=n;i++){
			ans+=pow(a[i],2);
		}
	}
	cout<<ans<<endl;
	return 0;
}
