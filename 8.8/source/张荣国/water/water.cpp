#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
//typedef int int_;
//#define int long long
#define maxn 10000005
#define manm 100005
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1; s=getchar();}
	while(s>='0'&&s<='9') { x=(x<<3)+(x<<1)+(s^48); s=getchar();}
	x=t?-x:x;
}
const int mod=1e9+7;
bool vis[maxn];
int pri[maxn],a[maxn],num[maxn],ans=1,cnt=0,n;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=2;i<=n;i++){
		if(vis[i]==0){
			pri[++cnt]=i;
			num[i]++;
			for(int j=i;j<=n;j+=i)
				{
					a[j]/=i;	
					vis[j]=1;
				}
		}
		else if(a[i]>1){
			int tmp=a[i];
			for(int j=i;j<=n;j+=i)
				a[j]/=tmp;
			num[tmp]++;
		}
	}
	for(int i=1;i<=cnt;i++)
		ans=(((((long long)pow(pri[i],num[pri[i]]))%mod)*ans)%mod);
	printf("%d",ans);
	return 0;
}
