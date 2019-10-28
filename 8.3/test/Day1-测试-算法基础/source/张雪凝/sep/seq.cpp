#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int s=10001,b=-10001;
	int n,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		b=max(b,a);
		s=min(s,a);
	}
	double ans=(b+s)*1.0/2;
	ans=b*1.0-ans;
	printf("%.8f",ans);
}
