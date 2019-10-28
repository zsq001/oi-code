#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define mod 100003
#define inf 1<<29 
using namespace std;
int n,m,cnt,hl[mod];
struct Hash{
	int val,ne;
}hash[mod];
void insert(int x)
{
	int y=x%mod;
	hash[++cnt].val=x;
	hash[cnt].ne=hl[y];
	hl[y]=cnt;
}
bool query(int x)
{
	int y=x%mod;
	for(int i=hl[y];i;i=hash[i].ne) if(hash[i].val==x) return true;
	return false;
}
int main()
{
	int x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		insert(x);
	}
	for(int i=1;i<=m;++i){
		scanf("%d",&x);
		query(x)?puts("YES"):puts("NO");
	}
	return 0;
}
