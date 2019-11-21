#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
typedef long long ll;
int n,tp;

namespace pt1{// 36pts
	const int N=405;
	ll a[N],f[N][N];
	void cmin(ll &x,ll y){if(x>y)x=y;}
	ll cal(int l,int r){return a[r]-a[l-1];}
	ll cal2(int l,int r){return (a[r]-a[l-1])*(a[r]-a[l-1]);}
	void solve(){
		memset(f,0x3f,sizeof(f));
		ll inf=f[0][0];
		for(int i=1;i<=n;i++){
			read(a[i]);
			a[i]+=a[i-1];
		}
		f[0][1]=0; f[1][1]=a[1]*a[1];
		for(int i=2,j,k;i<=n;i++){
			for(int iln=1;iln<=i;iln++){
				j=i-iln+1;
				for(int jln=1;jln<=j;jln++){
					k=j-jln;
					if(cal(k,j-1)>cal(j,i))continue;
					if(f[j-1][jln]>=inf)continue;
					cmin(f[i][iln],f[j-1][jln]+cal2(j,i));
				}
			} 
		}
		ll res=inf;
		for(int i=1;i<=n;i++)res=min(res,f[n][i]);
		printf("%lld\n",res);
		return ;
	}
}

int main(){
	freopen("partition.in","r",stdin);
	freopen("partition.out","w",stdout);
	read(n); read(tp);
	if(n<=400)pt1::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
