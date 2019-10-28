#include<cstdio>
#include<algorithm>
using namespace std;
#define esp 1e-7

double a[100];
double x[100][100],y[100][100];
int n;

double abss(double iii){
	if(iii>=0){
		return iii;
	}
	else return -iii;
}

double check(int now){
	for(int i=1;i<=n;i++){
		x[i][0]=a[i]+now;
		y[i][0]=abss(x[i][0]);
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n;j++){
			if(j+i <= n){
				int mid=(j+j+i)/2;
		    	x[j][j+i]=x[j][mid-j]+x[mid+1][j+i-mid-1];
		    	y[j][j+i]=max(max(y[j][mid-j],y[mid+1][j+i-mid-1]),abss(x[j][j+i]));
			}
		}
	}
	return y[1][n-1];
}



int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf",&a[i]);
	}
	double l=-5,r=5;
	while(r-l >= esp){
		double mid=(l+r)/2.0;
		double mmid=(mid+r)/2.0;
		if(check(mid) >= check(mmid)) l=mid;
		else r=mmid;
	}
    printf("%.8lf",(r+l)/2.0);
	return 0;	
}
