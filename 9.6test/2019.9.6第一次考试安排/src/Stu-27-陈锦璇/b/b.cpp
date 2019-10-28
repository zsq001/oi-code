#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define maxn 1000010
#define mod 1000000007

int n,shuzi[maxn],biao[maxn],len,ans;
int s[7]={0,1,1,2,2,3,4};

int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	if(n<=6) cout<<s[n]<<endl;
	else{
		for(int i=1;i<=n;++i){
			shuzi[i]=i;
		}
		biao[0]=0;
		for(int i=1;i<=n;++i){
			biao[i]=biao[i-1]+shuzi[i];
			if(n>=biao[i]) len=i;
		}
		for(int i=2;i<=len;++i){
			if(n-biao[i]<=0||n-biao[i]<len) break;
			if((n-biao[i]-1)%2==0) ans+=(n-biao[i])/2;
			else ans+=(n-biao[i])/2-1;
		}
		cout<<(ans+(n-1)/2+1)%mod<<endl;	
	}
	return 0;
}
