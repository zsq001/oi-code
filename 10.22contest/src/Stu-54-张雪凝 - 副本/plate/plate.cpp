#include<cstdio>
#include<cmath>
using namespace std;
#define ull unsigned long long
#define maxn 505

int n,m,p;
int fa[maxn],cnt[maxn],b[maxn][maxn],a[maxn];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(int x,int y){
	for(int i=1;i<=m;i++){
		if(b[x][i]==b[y][1]){
			int j;
			for(j=1;j<m;j++){
				if(b[x][i+j]!=b[y][1+j]) continue;
			}
			if(j==m) return 1; 
		}
	}
	return 0;
}

int main(){
	freopen("plate.in","r",stdin);
	freopen("plate.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++) fa[i]=i;
	if(m==p){
		printf("%d",n*(n-1)/2);
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",a+j);
			b[i][j+m]=b[i][j]=(a[j]-a[j-1]+p)%p;
		}
		b[i][1+m]=b[i][1]=(a[1]-a[m]+p)%p;
		for(int j=1;j<i;j++){
			if(fa[i]!=i) continue;
			if(check(i,j)){
				fa[j]=i;
				cnt[i]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=cnt[i]*(cnt[i]+1)/2;
	printf("%d",ans);
}
