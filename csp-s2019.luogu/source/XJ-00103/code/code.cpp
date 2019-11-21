#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
template<class T>void read(T &x)
{
	x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
}
long long int tmp,flag,n,k,cnt;
int ans[1010];
void dfs(long long int f,int now){
	if(f==n){
		tmp++;
		if(tmp==k) {
			flag=1;
			ans[++cnt]=now;
		}
		return ;
	}
	if(now==0){
		dfs(f+1,0);
		if(flag==1) {
			ans[++cnt]=now;
			return ;
		}  
		dfs(f+1,1);
		if(flag==1) {
			ans[++cnt]=now;
			return ;
		}  
	}
	if(now==1){
		dfs(f+1,1);
		if(flag==1) {
			ans[++cnt]=now;
			return ;
		}  
		dfs(f+1,0);
		if(flag==1) {
			ans[++cnt]=now;
			return ;
		}  
	}
	
}
int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	read(n); read(k); k++;
	dfs(0,0);
	for(int i=n;i>=1;--i)
	{
		printf("%d",ans[i]);
	}
}
