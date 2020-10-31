#include<bits/stdc++.h>
using namespace std;
int n,m,a[50010],l,r,len;
int main()
{
	cin>>len>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	a[++n]=len;
	l=0,r=len+1;
	while(l<r){
		int mid=(l+r+1)>>1;
		int sum=0;
		for(int i=0,j;i<=n;i=j){
			j=i+1;
			while(a[j]-a[i]<mid&&j<=n) j++;
			sum+=j-i-1;
		}
		if(sum>m) r=mid-1;
		else l=mid;
	}
	cout<<l<<endl;
	return 0;
}
