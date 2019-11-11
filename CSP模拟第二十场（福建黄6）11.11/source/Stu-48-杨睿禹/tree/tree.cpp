#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
#define N 500100
#define M 5010
#define oo 214748364
typedef int int_;
#define int long long
using namespace std ;
inline int in(){
	char ch=getchar();
	int ret=0,flag=1;
	while(ch<'0' or ch>'9'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while('0'<=ch and ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*flag;
}
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("tree.in","r",stdin);
	freopen("tree.tou","w".stdout);
	int T=in();
	while(T--){
		int n=in(),k=in();
		for(int i=1;i<=n-1;i++) int a=in();
		if(k%2==0) cout<<k/2<<endl;
		else cout<<k/2+1<<endl;
	}
	return 0;
}
