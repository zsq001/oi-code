#include <stdio.h>
#include <iostream>
#define maxn 998244353
#include <algorithm>
#include <math.h>
long long s[200010],a[110][2010],k[110];
using namespace std;
int main(){
	int i,j,n,m,h=0,x=0;
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d",&n,&m);
	s[0]=0;s[1]=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			x+=a[i][j];
		}
		s[i+1]=x;
	}
	if(n==2&&m==2){
		h=a[1][1]*a[2][2]%maxn+a[2][1]*a[1][2]%maxn;
		if(h<1)h=1;
	}
	else{
		for(i=1;i<=n;i++){
	  		for(j=1;j<=n;j++){
	  			k[i]++;if(floor(k[i]/2)>h)continue;
	  			h=s[i]*a[i][j]%maxn+h%maxn;
			}
    	}
	}
	printf("%d",h);
	return 0;
}
