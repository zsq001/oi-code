#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=500005;
template<class T>void read(T &x)
{
	bool f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){f|=(s=='-');s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,root,in[N],v[N],w[N],cnt;
long long ans;
int head[N],ver[N],nxt[N],tot;
char s[N];
void addedge(int x,int y){ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;}
void dfs(int x)
{
	w[++cnt]=v[x];
	for(int i=head[x];i;i=nxt[i])
	{
		int y=ver[i];
		dfs(y);
	}
}
int check(int x,int y)
{
	if(x>y) return 1;
	if((y-x+1)%2) return 0;
	int cnt1=0,cnt2=0;
	for(int i=x;i<=y;++i)
	{
		if(w[i]) cnt2++;
		else cnt1++;
		if(cnt2>cnt1) return 0;
	}
	if(cnt1!=cnt2) return 0;
	return 1;
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	read(n);
	scanf("%s",s+1);
	if(s[1]==')') v[1]=1;
	for(int i=2;i<=n;++i)
	{
		int x;
		if(s[i]==')') v[i]=1;
		read(x);
		addedge(x,i),++in[i];
	}
	for(int i=1;i<=n;++i)
		if(in[i]==0)
		{
			root=i;
			break;
		}
	dfs(root),cnt=0;
	for(int i=1;i<=n;++i)
	{
		for(int j=i-1;j&&w[i];--j)
			if(w[j]==0) cnt+=check(j,i);
		ans^=i*cnt;
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
