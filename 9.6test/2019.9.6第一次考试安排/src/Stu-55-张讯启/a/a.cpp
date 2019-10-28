#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int m,n,a;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		int ans=0;
		int y1=0,y2=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a);
			if(a%3==0) ans++;
			if(a%3==1) y1++;
			if(a%3==2) y2++;
		}
		if(y1>=y2){
			ans+=y2;
			y1-=y2;
			ans+=y1/3;
		}
		if(y1<y2){
			ans+=y1;
			y2-=y1;
			ans+=y2/3;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
