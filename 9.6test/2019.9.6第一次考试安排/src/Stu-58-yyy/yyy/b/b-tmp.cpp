#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
using namespace std;

template<class T>void read(T &x){
	x=0; char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48); c=getchar();}
}

typedef long long ll;
const int M=1000000007;
int n;
void add(int &x,int y){x+=y; if(x>=M)x-=M;}

namespace pt1{
	const int N=10005;
	int f[N][N];
	int sum[N][N];
	void solve(){
		f[0][0]=1; int ans=0,tmp;
		sum[0][0]=1;// n=10000;
//		printf("{0,");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				sum[i][j]=sum[i-j][min(i-j,j-1)];
				add(sum[i][j],sum[i][j-1]);
			}
			printf("%d,",sum[i][i]);
		}
		printf("}");
		printf("%d\n",sum[n][n]);
	}
}

namespace pt2{
	map<ll,int>m;
	ll hash(int x,int y){return x*(n-1)+y;}
	void solve(){
		m[0]=1;
		
	}
}

int main(){
	freopen("b.in","r",stdin);
//	freopen("b.out","w",stdout);
	read(n);
	if(n<=2000)pt1::solve();
	
//	pt2::solve();
	
	return 0;
}
