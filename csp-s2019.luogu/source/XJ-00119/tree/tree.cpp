#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std ;
template<class T>void read(T &x){
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return ;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;read(T);
	for(int i=1;i<=T;i++){
		int n;read(n);
		for(int i=1;i<=n;i++)
			printf("%d ",i);
		puts("");
	}
	return 0;
}
