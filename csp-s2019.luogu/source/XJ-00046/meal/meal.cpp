#include<bits/stdc++.h>
using namespace std;
long long m,n,i,j,ml=0,k,k1,k2,l,d1,d2;
int main()
{freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
cin>>n>>m;
int a[n][m],b[n];
for(i=0;i<n;++i)
for(j=0;j<m;j++)
 cin>>a [i][j];
for(i=0;i<n;++i)
for(j=0;j<m;++j)

for(k1=0;k1+i<n;++k1)
for(k2=0;k2<m;++k2)
 {
 	if(i+k1>=n) d1=i+k1-n;
 	else d1=i+k1;
 	d2=i+k2;
 	ml=(ml+a[i][j]*a[d1][d2]);       //2µÀ²Ë 

}

	//998 244 353      
	ml=ml%998244353;
//	printf("%d",ml);
printf("%d",ml);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
