#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int  n,m;
long long ans;
int s[500005];
int main(){
		freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	int sum=0;
	for(int i=1;i<=n-1;i++){
		if(s[i]>s[i+1]) {
			int a=0,p,h=i;
		for(int j=i+2;j<=n;j++){
		sum+=s[j];
		if(sum>=s[i]) {
		p=j;a=1;break;	
		}
		}
		if(a==1) {
		if(p!=i+2) {
				int sum2=0;
		 for(int j=i+1;j<=p-2;j++){
		 	sum2+=s[j];
			 s[j]=0;
		 }
		 s[p-1]+=sum2;
		}
		else {
			s[i+1]+=s[i];
			s[i]=0;
		}
		}
	 else if(a==0){
	 	int sum3=0;
	     for(int u=i+1;u<=n-1;u++){
	     	sum3+=s[u];
	     	s[u]=0;
	     }
	     s[n]+=sum3;
		}
	}
}
for(int v=1;v<=n-1;v++){
	if(s[v]>s[v+1]){
	s[v+1]+=s[v];s[v]=0;
	} 
}
	for(int i=1;i<=n;i++){
	ans+=s[i]*s[i];
	}
	cout<<ans;
	return 0;
}
