#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include<cmath>
using namespace std;
const int N=3010;
const int yql=1e9+7;
using namespace std;
int a[N],dp[N][N],n,m,s[N];
char p[N];
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
int main(){
	freopen("university.in","r",stdin);
	freopen("university.out","w",stdout);
	n=read();m=read();
	scanf("%s",p+1);
	for(int i=1;i<=n;i++){a[i]=i;s[i]=s[i-1];if(p[i]=='1')s[i]++;}
	//for(int i=1;i<=n;i++)printf("%d%c",s[i],i==n?'\n':' ');
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		for(int j=l;j<=r;j++)a[j]=max(a[j],r);
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j>s[a[i]])continue;
			if(i-j>a[i]-s[a[i]])continue;
			dp[i][j]=dp[i-1][j];
			if(j)dp[i][j]=(dp[i][j]+dp[i-1][j-1])%yql;
		}
	}
	printf("%d\n",dp[n][s[n]]);
}
