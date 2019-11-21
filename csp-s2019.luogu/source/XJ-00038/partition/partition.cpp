#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
typedef int int_;
#define int unsigned long long 
using namespace std;
int n,type,a[5005],ans;
int_ main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<n;i++){
		if(a[i]<a[i-1]&&a[i]<a[i+1]){
			if(a[i-1]<a[i+1])a[i-1]+=a[i];
			else             a[i+1]+=a[i];
			a[i]=0;
		}
	}
	if(a[n]<a[n-1])a[n-1]+=a[n],a[n]=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=0)ans+=a[i]*a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
