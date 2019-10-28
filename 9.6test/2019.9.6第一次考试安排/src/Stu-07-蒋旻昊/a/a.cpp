#include<cstdio>
#include<algorithm>
using namespace std;

int n,t;
int cnt1,cnt2,cnt3;

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			int tp;
			scanf("%d",&tp);
			if(tp%3 == 0) cnt3++;
			else if(tp%3 == 1) cnt1++;
			else cnt2++;
		}
		int ans=cnt3;
		if(cnt1 < cnt2) swap(cnt1,cnt2);
		ans+=cnt2;
		ans+=(cnt1-cnt2)/3;
		printf("%d\n",ans);
	}
	return 0;
}
