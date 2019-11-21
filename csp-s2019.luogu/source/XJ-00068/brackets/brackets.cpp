#include <cstdio>
#include <iostream>
using namespace std;

const int maxn=5e5+5;

long long n,ans=0;
long long fa[maxn],k[maxn];
char s[maxn];

int main(){
	ios::sync_with_stdio(false);
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>n;
	cin>>s;
	fa[1]=1;
	for(register long long i=2;i<=n;i++) cin>>fa[i];
	k[1]=0;
	k[2]=1;
	for(register int i=3;i<=n;i++){
		if(i&1) k[i]=k[i-1];
		else k[i]=k[i-1]+i/2;
	}
	for(register int i=1;i<=n;i++) ans=ans^(i*k[i]);
	cout<<ans;
	return 0;
}
