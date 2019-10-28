#include<cstdio>
#include<algorithm>
using namespace std;
int add[1010][1010];
int main(){
	int n,m;
	freopen("carpet.in","r",stdin);
	freopen("carpet.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x1,x2,y1,y2;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
		for(int j=y1;j<=y2;j++){
			add[x1][j]++;
			add[x2+1][j]--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			add[j][i]+=add[j-1][i];
			printf("%d ",add[j][i]);
		}
		puts("");	
	}
	return 0;
}
