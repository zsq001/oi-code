#include<cstdio>
#include<algorithm>
using namespace std;
#define inf 1000000007

int n;
double k,c,w;
int ty[100005];
double s[100005];
double a[100005];


double sum[100005],ans;



int main()
{
	freopen("coal.in","r",stdin);
	freopen("coal.out","w",stdout);
	scanf("%d %lf %lf %lf",&n,&k,&c,&w);
    double x=1.0;
    k=(1-k*1e-2);
    c=(1+c*1e-2);
	for(int i=1;i<=n;i++){
    	scanf("%d %lf",&ty[i],&a[i]);
    	if(ty[i]==1){
    		s[i]=x*a[i];
			x*=k;
		}
		else{
			s[i]=x*a[i];
			x*=c;
		}
	}
	/*
    for(int i=n;i>=1;i--){
    	if(ty[i]==1)
    	sum[i]=sum[i+1]+s[i];
		else
		sum[i]=sum[i+1]-s[i];
	}
	*/
	for(int i=n;i>=1;i--){
		if(ty[i]==1){
			if((sum[i+1]*(1-k)/k-s[i]) > 0){
				ans/=k;
				sum[i+1]/=k;
				sum[i+1]-=s[i];
			}
			else{
				ans+=w*s[i];
			}
			sum[i]=sum[i+1]+s[i];
		}
		else{
			if((s[i]-sum[i+1]*(c-1)/c) > 0){
				ans/=c;
				sum[i+1]/=c;
				sum[i+1]+=s[i];
			}
			else{
				ans-=w*s[i];
			}
			sum[i]=sum[i+1]-s[i];
		}
		
	}
	printf("%.2lf",ans);
	return 0;
}

/*
5 50 50 10
1 10
1 20
2 10
2 20
1 30
*/
