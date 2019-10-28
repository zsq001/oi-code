#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,a[2050],ans; 

int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int l=1,r=n,c=1;
		while(!(r<l)){
			if(a[l+1]-a[l] >= a[r-1]-a[r]){
				ans+=c*a[r];
				r--;
			}
			else{
				ans+=(a[l]*c);
				l++;
			}
			c=-c;
		}
		printf("%d\n",ans);
	}
	return 0;
}
