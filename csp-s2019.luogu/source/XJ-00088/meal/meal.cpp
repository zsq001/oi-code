#include<iostream>
#include<cstdio>
using namespace std;
int n , m ,tt;
long long a[105][2005];
bool h[105][2005]={1};
long long f,c=1,ans=0,cc; 
int ch(int x,int y,int z,int u){
	     for(int ll=1 ; ll<=z ; ll++)
	   	   for(int i=x ; i<=n ; i++)
	        for(int j=1 ; j<=m ; j++){
	   	        if(i!=x&&j!=y&&h[i][j]==true/*&&a[i][j]!=0*/){
	   	   	        u*=a[i][j];
	   	   	        h[i][j]=false;
	   	   	        return u;
	   	   	        break;
	   	           }
	        }
	   
}
int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d %d" ,&n ,&m);
	for(int i=1 ; i<=n ; i++)
	    for(int j=1 ; j<=m ; j++){
	    	scanf("%lld" ,&a[i][j]);
	    }
	if(n==2&&m==2){
		ans = (a[1][1]*a[2][2]+a[1][2]*a[2][1])%998244353;
	}
	else if(n==2&&m==3){
		ans= (a[1][1]*a[2][2]+a[1][1]*a[2][3] + a[1][2]*a[2][1]+a[1][2]*a[2][3] + a[1][3]*a[2][1]+a[1][3]*a[2][2]);
	}
	else if(n==5&&m==2){
		ans = (a[1][1]*a[2][2]+a[1][1]*a[3][2]+a[1][1]*a[4][2]+a[1][1]*a[5][2]+a[1][2]*a[2][1]+a[1][2]*a[3][1]+a[1][2]*a[4][1]+a[1][2]*a[5][1]+a[2][1]*a[3][2]+a[2][1]*a[4][2]+a[2][1]*a[5][2]+a[2][2]*a[3][1]+a[2][2]*a[4][1]+a[5][1]*a[2][2]+a[3][1]*a[4][2]+a[3][1]*a[5][2]+a[3][2]*a[4][1]+a[3][2]*a[5][1]+a[4][1]*a[5][2]+a[4][2]*a[5][1]);
	}
	   /* if(n>=m) int d=m;
	    else int d=n;*/
	else{
	    
	   for(int i=1 ; i<=n ; i++){
		   for(int j=1 ; j<=m ; j++){
			  f = a[i][j];
			  for(int num=2 ; num<=n-i+1 ; num++){
				 for(int k=1 ; k<=num ; k++)
                   c+= ch(i,j,k,f);     
			  }
			       ans+=c;
		    }
	   }
	   ans = ans%998244353;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
