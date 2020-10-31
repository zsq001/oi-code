#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
template<class T>void read(T &x){
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9')  {f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
}

int C, L, sum;
char a[30], c[30];

inline void dfs(int now,int num){
	if(sum==25000) return;
	if (num==L){
		int yy=0,fy=0;
		for(int i=1;i<=L;++i){
			if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u') ++yy; 
			else 													  ++fy;
		}
		if(yy&&fy>1){
			for(int i=1;i<=L;++i)
			    putchar(a[i]);
			putchar('\n');
			++sum;
		}
		return;
	}
	for(int i=now+1;i<=C;++i){
		a[num+1]=c[i];
		dfs(i,num+1);
	}
}

int main() {
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	read(L),read(C);
	for(int i=1;i<=C;++i) cin>>c[i];
	sort(c+1,c+C+1);
	int n=C-L+1;
	for(int i=1;i<=n;++i){
		a[1]=c[i];
		dfs(i,1);
	}
	return 0;
}
