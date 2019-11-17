#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
int n,m,a[100],maxx,minn=0x7fffffff;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int now=minn;
	while(1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]<now) cnt+=(now-a[i]);
			if(a[i]>=now)
				break;
		}
		if(cnt<=m&&cnt<=now+1) now++;
		else {
			printf("%d",now-1);
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout);
}
