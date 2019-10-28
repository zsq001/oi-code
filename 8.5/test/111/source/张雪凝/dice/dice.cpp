#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int T;
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		int n,ans;
		scanf("%d",&n);
		if(n%10<=5)ans=(n/10)*2+1;
		else ans=(n/10+1)*2;
		printf("%d\n",ans);
	}
}
