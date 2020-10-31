#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}
const int N=1005;

int n,m,q;
struct opt{
	int x,y,z,t;
	bool operator < (const opt _)const{
		return t<_.t;
	}
}a[N],b[N],d[N<<1];
int cnt,res[N][N];

int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n); read(m); read(q);
	int x,y,z;
	for(int i=1;i<=q;i++){
		read(x); read(y); read(z);
		if(x==1)a[y]=(opt){x,y,z,i};
		else b[y]=(opt){x,y,z,i};
	}
	for(int i=1;i<=n;i++)if(a[i].t)d[++cnt]=a[i];
	for(int i=1;i<=m;i++)if(b[i].t)d[++cnt]=b[i];
	sort(d+1,d+cnt+1);
	for(int i=1;i<=cnt;i++){
		x=d[i].x; y=d[i].y; z=d[i].z;
		if(d[i].x==1)
			for(int j=1;j<=n;j++)res[y][j]=z;
		else 
			for(int j=1;j<=n;j++)res[j][y]=z;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d ",res[i][j]);
		puts("");
	}
	return 0;
}
