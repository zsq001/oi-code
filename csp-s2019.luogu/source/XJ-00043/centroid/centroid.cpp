#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n;
int fa[100010],sun[100010];
int main(){
	freopen("centroid.in","r",stdin);
	freopen("centroid.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;++i)
		scanf("%d %d",&fa[i],&sun[i]);
	long long ans=0;
	for(int i=1;i<n;++i){
		if(n%2==0){
			if(i%2!=0) ans+=fa[i/2+1]+fa[(n/2)+(i/2)];
			if(i%2==0) ans+=fa[(i-1)/2+1]+sun[(i-1)/2+1]+fa[(n/2)+((i-1)/2)]+sun[(n/2)+((i-1)/2)];
		}
		if(n%2!=0){
			if(i%2!=0) ans+=fa[i/2+1]+fa[((n+1)/2)+(i/2)]+sun[((n+1)/2)+(i/2)];
			if(i%2==0) ans+=fa[(i-1)/2+1]+sun[(i-1)/2+1]+sun[((n+1)/2)+((i-1)/2)];
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
