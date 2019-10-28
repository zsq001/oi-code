#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define maxn 100010
using namespace std;
int n,k,a[1010][1010],num1[maxn],num0[maxn],max1,max0;
int main(){
	freopen("lamp.in","r",stdin);
	freopen("lamp.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			scanf("%1d",&a[i][j]);
			if(a[i][j]==1) num1[i]++;
			else num0[i]++;
		}
		max1=max(max1,num1[i]);
		max0=max(max0,num0[i]);
	}
	if(n==1&&k==1){
		puts("1");
		return 0;
	}
	else if(k==1){
		puts("0");
		return 0;
	}
	else{
		printf("%d",(max1-(k-max0))/2);
		return 0;
	}
	return 0;
}
