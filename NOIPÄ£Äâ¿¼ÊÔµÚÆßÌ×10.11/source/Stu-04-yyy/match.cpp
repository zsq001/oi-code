#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}

const int N=100050;

int n,m,u,v,ans=0;
int a[N],b,cnt;
bool vis[N];
struct seg{
	int l,r,len;
	bool operator > (const seg _)const{
		return l==_.l?len<_.len:l<_.l;
	}
	bool operator < (const seg _)const{
		return l==_.l?len>_.len:l>_.l;
	}
};
priority_queue<seg>q;

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	read(n); read(m); read(u); read(v);
	for(int i=1;i<=n;i++)read(a[i]);
	a[0]=-1; a[n+1]=2147483647;
	int l,r;
	seg t;
	for(int i=1;i<=m;i++){
		read(b);
		l=lower_bound(a+1,a+n+1,b-v)-a;
		r=upper_bound(a+1,a+n+1,b+u)-a-1;
		if(l<1||l>n||r<1||r>n||l>r)continue;
//		printf("(%d %d)\n%d %d  %d %d\n",l,r,b-v,a[l],b+u,a[r]);
		t.l=l; t.r=r; t.len=r-l+1;
		q.push(t);
	}
	while(!q.empty()){
		t=q.top(); q.pop();
		l=t.l; r=t.r;
		while(l<=r&&vis[l])++l;
		if(l<=r)++ans,vis[l]=1;
	}
	printf("%d\n",ans);
	return 0;
}

/*
5 3 0 0
1 2 3 3 4
1 3 5
*/
