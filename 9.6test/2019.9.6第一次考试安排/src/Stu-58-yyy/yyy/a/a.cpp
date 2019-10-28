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
const int N=105;

int n;
int a[N],cnt[5],ans;

int solve(){
	read(n); ans=cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;i++){
		read(a[i]);
		a[i]=a[i]%3;
		++cnt[a[i]];
	}
	ans=cnt[0];
	if(cnt[1]>cnt[2])swap(cnt[1],cnt[2]);
	ans+=cnt[1];
	ans+=(cnt[2]-cnt[1])/3;
	printf("%d\n",ans);
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T; read(T);
	while(T--)solve();
	return 0;
}
