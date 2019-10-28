#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
const int N=100050;
int n,h,b,e;
int c[N],pos[N],cnt[N];

void solve(){
	memset(pos,-1,sizeof(pos));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		read(c[i]);
		if(pos[c[i]]==-1)pos[c[i]]=i;
	}
	int now=1,next=1,remain;
	while(now<=n){
		if(c[now]>c[next+1])++next;
		else while(c[now]<c[next+1]&&next<n&&next-now<=h)++next;
		cnt[now]=next-now; 
		now=next;
	}
	for(int i=b;i<=e;i++)printf("%d ",cnt[i]);puts("");
}

int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	while(scanf("%d%d%d%d",&n,&h,&b,&e)!=EOF){
		solve();
	}
	return 0;
}
