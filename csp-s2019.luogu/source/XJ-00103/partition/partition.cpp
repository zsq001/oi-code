#include<bits/stdc++.h>
#define MAXN 100010
#define INF 0x7fffffff
#define ull unsigned long long
using namespace std;
template <class T> void read(T &x)
{
	x=0; char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48); ch=getchar();}
}
ull a[MAXN*5],b[MAXN*5];
ull ans,n,op,sum;
int nxt[MAXN*5],la[MAXN*5];
bool check(){
	int LA=1;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==0) continue; 
		if(a[LA]>a[i]) return false; 
		LA=i;
	}
	return true;
}
int main()
{
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	read(n); read(op);
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		b[i]=a[i]; 
		nxt[i]=i+1;
		la[i]=i-1;
		sum=sum+a[i];
	}
	sum=(sum/n)*1.5;
	a[n+1]=INF;
	while(check()==false)
	{
		for(int i=1;i<=n;++i)
		{
			if(a[i]<a[la[i]]&&a[i]!=0) {
				if(a[la[i]]+a[i]<=a[nxt[i]]+a[nxt[nxt[i]]]) {
					a[la[i]]=a[la[i]]+a[i];a[i]=0;
					int TMP=i;
					while(!a[TMP]){
						int tmp=la[i];
						nxt[tmp]=nxt[TMP];
						TMP=nxt[nxt[tmp]];
						if(TMP==0) break;	
					}
					la[i]=la[la[i]];
					continue;
				}
				a[nxt[i]]=a[nxt[i]]+a[i];a[i]=0;
				int TMP=i;
				while(!a[TMP]){
					int tmp=nxt[i];
					la[tmp]=la[TMP];
					TMP=la[la[tmp]];	
					if(TMP==0) break;
				}
				nxt[i]=nxt[nxt[i]];
			}
	}
	}
	for(int i=1;i<=n;++i){
		ans=ans+(a[i]*a[i]);
	}
	printf("%lld",ans);
}
