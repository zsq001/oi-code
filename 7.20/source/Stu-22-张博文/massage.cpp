#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#define ll long long
#define maxn 100010
using namespace std;

int main(){
	freopen("massage.in","r",stdin);
	freopen("massage.out","w",stdout);
	int t,q;
	scanf("%d%d",&t,&q);
	while(t--){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u==v){
			printf("0");
			if(q==1) printf("%d",u);
			return 0;
		}
	}
}
