#include<bits/stdc++.h>
using namespace std;
long long int i,j,countt,a[100010],sum,l,r;
int pd,n,m;
int main () {
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(i=1;i<=m;i++){
		cin>>pd>>l>>r;
		if(pd==0){
			for(j=l;j<=r;j++){
				a[j]=(int)sqrt(a[j]);
			}
		}
		if(pd==1){
			for(j=l;j<=r;j++){
				sum+=a[j];
			}
			cout<<sum<<endl;
			sum=0;
		}
	}
}
