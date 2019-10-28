#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#define inf 1<<29
using namespace std;
typedef long long ll;
inline int read()
{
	int ret(0);
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret;
}
struct Query{
	int l,r,id,ans;
}q[200010];
int n,m,pre[1000010],l,r,cnt=1,jp[50010],tree[50010],x;
bool cmp1(Query x,Query y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
bool cmp2(Query x,Query y){return x.id<y.id;}
void insert(int x,int val)
{
	for(;x<=n;x+=x&-x) tree[x]+=val;
}
int query(int x)
{
	int ret(0);
	for(;x;x-=x&-x) ret+=tree[x];
	return ret;
}
int main()
{
    n=read();
	for(int i=1;i<=n;++i){
		jp[i]=inf;
		x=read();
		if(pre[x]) jp[pre[x]]=i;
		else insert(i,1);
		pre[x]=i;
	}
	m=read();
	for(int i=1;i<=m;++i) q[i].l=read(),q[i].r=read(),q[i].id=i;
	sort(q+1,q+m+1,cmp1);
	for(int i=1;i<=n;++i){
		while(q[cnt].l==i){
			q[cnt].ans=query(q[cnt].r)-query(q[cnt].l-1);
			cnt++;
		}
		if(jp[i]!=inf) insert(jp[i],1);
		if(cnt>m) break;
	}
	sort(q+1,q+m+1,cmp2);
	for(int i=1;i<=m;++i) printf("%d\n",q[i].ans);
	return 0;
}
