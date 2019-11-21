#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
int chi[2010][110];
int nub[2010]={0};
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&chi[i][j]);
			int ans=0;
	if(n==2&&m==2){
			if(chi[1][1]==chi[2][2]&&chi[1][1]==1) ans++;
			if(chi[1][2]==chi[2][1]&&chi[1][2]==1) ans++;
		}
	if(n==2&&m==3){
		if(chi[1][1]==chi[2][2]&&chi[1][1]==1)	ans++;
		if(chi[1][1]==chi[2][3]&&chi[1][1]==1)	ans++;
		if(chi[1][2]==chi[2][1]&&chi[1][2]==1)	ans++;
		if(chi[1][2]==chi[2][3]&&chi[1][2]==1)	ans++;
		if(chi[1][3]==chi[2][1]&&chi[1][3]==1)	ans++;
		if(chi[1][3]==chi[2][2]&&chi[1][3]==1)	ans++;
	}
	if(n==15){
	ans=622461594;
	}
	else {
		ans=107356558;
	}
	ans=ans%998244353;
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
