#include<bits/stdc++.h>
using namespace std;
long long type,n,a[4*10000000+1],b[4*10000000+1],num=0,ans=0;
bool f[4*10000000+1];
int max(long long  a,long long b){
	if(a>b)return 1;
	return 0;
}
int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	cin>>n>>type;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]>a[i+1]){
			if(a[i+2]>a[i]+a[i+1]){
				b[num]=a[i]+a[i+1];num++;
				f[i]=1;
				f[i+1]=1;
			}
			else{
				b[num]=a[i];
				b[num+1]=a[i+1]+a[i+2];
				num+=2;
				f[i]=1;f[i+1]=1;f[i+2]=1;
			}
		}
		else{if(f[i]==0){
			b[num]=a[i];
			num++;
		}
		}
	}
	for(int i=0;i<=num;i++)ans+=b[i]*b[i];
	cout<<ans;
	return 0;
}
