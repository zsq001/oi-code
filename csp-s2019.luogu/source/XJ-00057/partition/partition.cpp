#include <bits/stdc++.h>
using namespace std;
int a[500005];
int maxn=0;
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	ios::sync_with_stdio(false);
	int sum=0,n,type;
	cin>>n>>type;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(maxn<a[i])maxn=a[i];
		sum+=a[i];
	}
	int l=sum/maxn,r=n;
	while(l<r){
		int mid=(l+r)/2;
		int sume=sum/mid;
		int cnt=0,s=0,k=1;
		for(int i=1;i<=n;i++){
			if(a[i]>sume){k=0;break;}
			s+=a[i];
			if(s+a[i+1]>sume){
				cnt++;
				s=0;
			}
		}
		if(k==0)l=mid+1;
		if(cnt>mid)r=mid;
		}
		l--;
		int ans1=0,ans=0;
		for(int i=1;i<=n;i++){
		if(ans1+a[i]>sum/l){
			ans+=ans1*ans1;
			ans1=0;
			ans1+=a[i];
		}
		else ans1+=a[i];
		}
		ans+=ans1*ans1;
		cout<<ans;
		return 0;
	}
		 
		
		
