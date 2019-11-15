#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stack>
#include<queue>
typedef int int_;
#define int long long
#define N 500100
#define M 5010
#define oo 10000007
using namespace std ;
inline int in(){
	char ch=getchar();
	int flag=1,ret=0;
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
int orz,lans,vis[N];
queue<int> q;
int_ main(){
	std::ios::sync_with_stdio(false);
	freopen("tea.in","r",stdin);
	freopen("tea.out","w",stdout);
	int m=in(),orz=in();
	while(m--){
		int op=in();
		if(op==1){
			int x=in();
			if(orz==1) x=x^lans;
			vis[x]=1;
		}
		if(op==2){
			int x=in();
			if(orz==1) x=x^lans;
			vis[x]=0;
			q.push(x);
		}
		if(op==3){
			int x=q.front();
			q.pop();
			vis[x]=1;
		}
		if(op==4)
			for(int i=1;i<=oo;i++)
				if(!vis[i]){
					cout<<i<<endl;
					lans=i;
					break;
				}
	}
}
