#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
const int inf=1e18;
int n;
ll c[maxn],a[maxn],ans,sum;
char ch;
void ball(){
	c[0]=0;
	for(int k=1;k<=n;++k){
		if(ans>inf){cout<<"-1"<<endl;exit(0);}
		if(c[n]==n){cout<<ans<<endl;exit(0);}
		while(a[k]==2){
			int id=k;
			for(int j=1;j<=id;++j){
				a[j]^=3;
			}ans++;
			for(int j=1;j<=n;++j) c[j]=c[j-1]+a[j];
			k=1;
		}			
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n;
	memset(c,0,sizeof(c));
	for(int j=1;j<=n;++j){
		cin>>ch;
		if(ch=='R') a[j]=1;
		else a[j]=2;
	}
	ball();
	return 0;
}
/*
3
RBR
4
RRBB
*/
