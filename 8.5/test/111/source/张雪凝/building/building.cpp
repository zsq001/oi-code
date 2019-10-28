#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
int main(){
	int n,m,x,y;
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		a[x]=y;
		double k=0.0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i])
				if(k<1.0*a[i]/i){
					cnt++;
					k=1.0*a[i]/i;
				}
		}
		printf("%d\n",cnt);
	}
}
