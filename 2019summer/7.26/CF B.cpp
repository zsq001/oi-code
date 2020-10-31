#include<bits/stdc++.h>
#define maxn 500010
#define inf 1<<29
using namespace std;
typedef long long ll;
ll T,a[maxn],tot,n,k,cnt;
int main()
{
	cin>>T;
	while(T--){
		cin>>n>>k;
		cnt=tot=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			tot+=a[i];
			if(a[i]&1) cnt++; 
		}
		if(((tot&1)+(k&1))%2){
			cout<<"NO"<<endl;
			continue;
		}
		if(cnt<k){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		for(int i=1;i<=n;++i){
			if(k==1) break;
			if(a[i]&1){
				cout<<i<<" ";
				k--;
			}
		}
		cout<<n<<endl;
	}
	return 0;
}
