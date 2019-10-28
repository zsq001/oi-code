#include<cstdio>
using namespace std;
#define maxn 100010
#include<cmath>
long long n,a[maxn],m,dp[maxn];
int op,l,r,i;
int main()
{
	freopen("sculpture.in" ,"r",stdin);
	freopen("sculpture.out ","w",stdout);
	scanf("%lld",&n);
	 for( i=1;i<=n;i++){
	 	scanf("%lld",&a[i]);
	 	dp[i]=a[i];
	 }
	 scanf("%lld",&m);
	 int emp=0;
	 for(int j=1;j<=m;j++){
	 	scanf("%d %d %d",&op,&l,&r);
	 	for( i=1;i<=n;i++){
	 		if(op==0){
	 			if(i!=l)
			 	break;
	 			if(i==l){
	 				do{
	 				dp[i]=floor(sqrt(a[i]));
					 i++;
					 }while(i==r);
				 }	
			 }
			 if(op=1){
			 	if(i!=l)
			 	break;
			 	if(i==l){
	 				do{
	 					emp=dp[i]+emp;
						 i++;
					 }while(i==r);
				 }	
				 printf("%d\n",emp);
				 emp=0;
			 }
		 }
	 }
	return 0;
}
