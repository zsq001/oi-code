#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
typedef int int_;
#define int long long
#define N 500100
#define M 5010
#define oo 1000000007
using namespace std ;
inline int read(){
	char ch=getchar();
	int ret=0,flag=1;
	while(ch<'0' or '9'<ch){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*flag;
}
int base[N],pos[N],cnt;
char s[M];
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	int n = read();
	if(n>=59){
		cout<<"-1"<<endl;
		return 0;
	}
	cin>>(s+1);
	base[0]=1;
	for(int i=1;i<=n;i++)
		base[i]=base[i-1]<<1;
	int ans=base[n]-1;
	for(int i=1;i<=n;i++)
		if(s[i]=='R')
			pos[++cnt]=i;
	for(int i=1;i<=cnt;i++)
		ans-=base[pos[i]-1];
	cout<<ans<<endl;
	return 0;
}
