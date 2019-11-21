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
const int maxn=100010;

int n;
int f[maxn],a[maxn],head[maxn];

char str[maxn];


namespace get20pts{
	int ans=0;
	
	inline void query(int l,int r){
		int sum=0;bool fl=0;
		for(int i=l;i<=r;i++)
			sum+=a[i],fl=1;
		if(!sum&&fl) ans++;
	}
	
	inline void work(){
		for(int i=1;i<=n;i++){
			if(a[i]==1) continue;
			for(int j=i;j<=n;j++)
				query(i,j);
		}
		printf("%d\n",ans);
	}
	
	inline void init(){
		int len=strlen(str+1);
		for(int i=1;i<=len;i++) 
			if(str[i]=='(') a[i]=-1;
			else if(str[i]==')') a[i]=1;
		work();
	}
}

namespace get35pts{
	int ans=0;
	int tr[maxn];
	
	inline int lowbit(int x){
		return x&(-x);
	}
	
	inline int query(int pos,int ans=0){
		for(;pos;pos-=lowbit(pos)) ans+=tr[pos];
		return ans;
	}
	
	inline void add(int pos,int x){
		for(;pos<=n;pos+=lowbit(pos)) tr[pos]+=x;
	}
	
	inline bool check(int l,int r){
		return query(r)-query(l-1)==0;
	}
	
	inline void init(){
		int len=strlen(str+1);
		for(int i=1;i<=len;i++) 
			if(str[i]=='(') add(i,-1);
			else if(str[i]==')') add(i,1);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				if(query(i)-query(i-1)==1) continue;
				if(check(i,j)) ans++;
			}
		printf("%d\n",ans);
	}
}

namespace work{
	int ecnt;
	int num[maxn];
	bool vis[maxn];
	
	struct edge{
		int u,v,next;
	}E[maxn<<1];
	
	inline void addedge(int u,int v){
		E[++ecnt].u=u;E[ecnt].v=v;
		E[ecnt].next=head[u];head[u]=ecnt;
	}

	void dfs(int x,int cnt){
		if(x==n) {num[x]=cnt;return ;}
		for(int i=head[x];~i;i=E[i].next){
			int v=E[i].v;
			if(!vis[v]) dfs(v,++cnt);
			vis[v]=1;
		}
	}

	inline void init(){
		dfs(1,1);
	//	for(int i=1;i<=n;++i)	printf("%d ",num[i]);
	}
}

namespace get55pts{
	int ans=0,cnt=0,lcnt=0,lans=0;
	int pos[maxn],lpos[maxn],skp[maxn];
	
	inline bool able (int x){
		return str[x]==')'||str[x]=='(';
	}
	
	inline void init(){
		int len=strlen(str+1);
		for(int i=1;i<=len;i++) 
			if(str[i]=='(') lpos[i]=1;
		for(int i=1;i<=len;i++)
			if(str[i]==')'&&str[i-1]=='(') pos[++cnt]=i;
		int l,r;
		for(int i=1;i<=cnt;i++,ans+=lans){
			if(i!=1) if(lpos[r]) lans++;
			r=pos[i];l=r-1;
			while(str[l]=='('&&str[r]==')'&&able(l)&&able(r)) 
				ans++,l--,r++;
			for(int i=1;i<=l;i++) a[i]=1;
			for(int j=l+1;j<=r;j++) a[j]=-1;
		}
		printf("%d\n",ans);
	}
	
	inline void init1(){
		int len=strlen(str+1);
		for(int i=1;i<=len;i++) 
			if(str[i]=='(') lpos[i]=1;
		for(int i=1;i<=len;i++)
			if(str[i]==')'&&str[i-1]=='(') pos[++cnt]=i;
		for(int i=1,sum=0;i<=len;i++){
			sum+=str[i]=='('?1:-1;
			if(sum<0) skp[i]=1;
		}
		for(int i=len,sum=0;i;i--){
			sum+=str[i]=='('?1:-1;
			if(sum>0) skp[i]=1;
		}
		int mmx=0;
		for(int i=1,sum=0;i<=len;i++){
			if(skp[i]) continue;
			sum+=str[i]=='('?1:-1;
			mmx=max(mmx,abs(sum));
			if(sum==0) ans+=mmx,mmx=0,lans++;
		}
		ans+=lans*(lans-1)/2;
		printf("%d\n",ans);
	}
}

int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	
	read(n);bool fla=1;
	scanf(" %s",str+1);
	memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++){
		read(f[i+1]);
		if(f[i+1]!=i) fla=0;
		work::addedge(f[i+1],i+1);
		work::addedge(i+1,f[i+1]);
	}
	if(fla) get55pts::init1();
	else work::init();
	return 0;
}
