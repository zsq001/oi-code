#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n,ans;
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		if(n==1){
			printf("2\n");
			continue;
		}
		if(n>=2&&n<=6){
			printf("1\n");
			continue;
		}
		if(n>=7&&n<=11){
			printf("2\n");
			continue;
		}
		if(n>=12&&n<=16){
			printf("3\n");
			continue;
		}
		if(n>=17&&n<=20){
			printf("4\n");
			continue;
		}
		ans=(n-2)/5+1;
		printf("%d\n",ans);
	}
	return 0;
}
