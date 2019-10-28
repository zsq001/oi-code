#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 1000010

int T,n,b[maxn],a[maxn];

int main(){
	cin>>T;
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	while(T--){
		int sum=0,sum1=0,sum2=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			b[i]=a[i]%3;
			if(b[i]==0) sum++;
			else if(b[i]==1) sum1++;
			else if(b[i]==2) sum2++;
			if(sum1>sum2){
				ans=sum2;
				if((sum1-sum2)%3==0) ans+=(sum1-sum2)/3;
			}
			else if(sum1<=sum2) ans=sum1;
		}
		cout<<ans+sum<<endl;
	}
	return 0;
}
