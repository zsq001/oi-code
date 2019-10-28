#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef long long ll;
const int N=305;

int n;
int sum[N*N],a[N],now[N*N],cnt;
ll tot,ttt;
bool vis[N*N];

struct arr{
	int c[N];
	bool operator==(const arr _)const{
		for(int i=1;i<=n;i++){
			if(c[i]==_.c[i])continue;
			return 0;
		}
		return 1;
	}
}t;
vector<arr>f,e;

bool cmp(){
	for(int i=n*(n-1)/2;i;i--)
		if(sum[i]==now[i])continue;
		else return 0;
	return 1;
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	read(n); int tmp=n*(n-1)/2,lim=1e8;
	for(int i=tmp;i;i--)read(sum[i]),tot+=sum[i];
	sort(sum+1,sum+tmp+1);
	vis[1]=vis[2]=1; tot/=n;
	for(int i=3;i<=tmp;i++){
		if((sum[1]+sum[2]-sum[i])&1)continue;
		a[1]=(sum[1]+sum[2]-sum[i])/2;
		a[2]=sum[1]-a[1];
		a[3]=sum[2]-a[1];
		vis[i]=1; cnt=3;
		ttt=(sum[1]+sum[2]+sum[i])/2;
		if((sum[1]+sum[2]+sum[i])&1)continue;
		for(int j=3;j<=tmp&&cnt<n;j++){
			if(vis[j])continue;
			a[++cnt]=sum[j]-a[1];
			ttt+=a[cnt];
		}
		cnt=vis[i]=0;
		for(int j=1;j<=n;j++)for(int k=1;k<j;k++)now[++cnt]=a[j]+a[k];
		sort(now+1,now+tmp+1);
		if(cmp()==0)continue;
		for(int j=1;j<=n;j++)t.c[j]=a[j];
		if(f.size()) if(t==f[f.size()-1])continue;
		f.push_back(t);
	}
	printf("%d\n",f.size());
	for(int i=0;i<f.size();i++){
		for(int j=1;j<=n;j++)printf("%d ",f[i].c[j]);
		puts("");
	}
	return 0;
}
