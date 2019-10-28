#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
void read(int &x)
{
	int f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
void llread(long long &x)
{
	int f=0;x=0;char s=getchar();
	while(s>'9'||s<'0'){if(s=='-')f=1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<1)+(x<<3)+(s^48);s=getchar();}
	x=f?-x:x;
}
int n,m,pos[100005],block,tag[100005];
long long sum[100005],v[100005];
void update(int l,int r)
{
	int t;
	if(pos[l]==pos[r])
	{
		for(int i=l;i<=r;++i)
			t=v[i],v[i]=(long long)floor(sqrt(v[i])),sum[pos[l]]-=(t-v[i]);
		return;
	}
	for(int i=(pos[l]-1)*m+1;i<=l;++i)
		t=v[i],v[i]=(long long)floor(sqrt(v[i])),sum[pos[l]]-=(t-v[i]);
	for(int i=r;i<=min(n,pos[r]*m);++i)
		t=v[i],v[i]=(long long)floor(sqrt(v[i])),sum[pos[r]]-=(t-v[i]);
	for(int i=pos[l]+1;i<pos[r];++i) tag[i]=1;
}
void change(int k)
{
	int t;
	while(tag[k]--)
	{
		for(int i=(k-1)*m+1;i<=min(k*m,n);++i)
			t=v[i],v[i]=(long long)floor(sqrt(v[i])),sum[k]-=(t-v[i]);
	}
}
long long query(int l,int r)
{
	int ans=0,t;
	if(pos[l]==pos[r])
	{
		for(int i=l;i<=r;++i)
		{
			t=v[i];
			if(tag[pos[l]])
				for(int k=1;k<=tag[pos[l]];++k)
					t=(long long)floor(sqrt(t));
			ans+=t;
		}
		return ans;
	}
	for(int i=(pos[l]-1)*m+1;i<=l;++i)
	{
		t=v[i];
		if(tag[pos[l]])
			for(int k=1;k<=tag[pos[l]];++k)
				t=(long long)floor(sqrt(t));
		ans+=t;
	}
	for(int i=r;i<=min(n,pos[r]*m);++i)
	{
		t=v[i];
		if(tag[pos[l]])
			for(int k=1;k<=tag[pos[l]];++k)
				t=(long long)floor(sqrt(t));
		ans+=t;
	}
	for(int i=pos[l]+1;i<pos[r];++i)
	{
		if(tag[i]) change(i);
		ans+=sum[i];
	}
	return ans;
}
int main()
{
	freopen("sculpture.in","r",stdin);
	freopen("sculpture.out","w",stdout);
	read(n);
	block=sqrt(n);
	for(int i=1;i<=n;++i)
		llread(v[i]),pos[i]=(i-1)/block+1,sum[pos[i]]+=v[i];
	read(m);
	while(m--)
	{
		int op,l,r;
		read(op),read(l),read(r);
		if(op==0) update(l,r);
		else printf("%lld\n",query(l,r));
	}
	return 0;
}
