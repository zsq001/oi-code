#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int N=3;

int n,k;
int a[N],b[N],c[N];
int e[N][N],f[N][40005][3];
int m[8][8],t[8][8];

void cmin(int &x,int y){if(x>y)x=y;}
int bs(int x){return 1<<(x-1);}
void mcpy(){for(int i=1;i<=5;i++)for(int j=1;j<=5;j++)t[i][j]=m[i][j];}
int cal(){
	int now,res=25;
	bool flag;
	for(int s=0;s<=31;s++){
		mcpy(); now=0; flag=1;
		for(int i=0;i<5;i++)t[1][i+1]^=(s<<i&1);
		for(int i=1;i<5;i++){
			for(int j=1;j<=5;j++){
				if(t[i][j]){
					t[i][j]=0;
					t[i+1][j-1]^=1; t[i+1][j]^=1; t[i+1][j+1]^=1;
					t[i+2][j]^=1;
					++now;
				}
			}
		}
		for(int i=1;i<=5;i++)flag&=(t[5][i]==0);
		if(flag)res=min(res,now);
	}
	return res*k;
}

int main(){
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);//base to i th place
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);//i th place to school
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&e[i][j]);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++)
			for(int k=1;k<=5;k++)scanf("%d",&m[j][k]);
		a[i]=cal();
//		printf("%d\n",a[i]);//time to unlock i th
	}
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)f[i][1<<(i-1)][1]=b[i]+a[i];
	for(int s=1;s<(1<<n);s++){
		for(int x=1;x<=n;x++){
			if((s&bs(x))==0)continue;
			for(int y=1;y<=n;y++){
				if(s&bs(y))continue;
				if(f[y][s|bs(y)][0]<0){
					if(f[x][s][0]>=0)f[y][s|bs(y)][0]=f[x][s][0]+e[x][y]+a[y];
					if(f[x][s][1]>=0)f[y][s|bs(y)][0]=f[x][s][1]+e[x][y]+a[y];
					if(f[x][s][2]>=0)f[y][s|bs(y)][0]=f[x][s][2]+e[x][y]+a[y];
				}
				else {
					if(f[x][s][0]>=0)cmin(f[y][s|bs(y)][0],f[x][s][0]+e[x][y]+a[y]);
					if(f[x][s][1]>=0)cmin(f[y][s|bs(y)][0],f[x][s][1]+e[x][y]+a[y]);
					if(f[x][s][2]>=0)cmin(f[y][s|bs(y)][0],f[x][s][2]+e[x][y]+a[y]);
				}
				
				if(f[y][s|bs(y)][1]<0){
					if(f[x][s][0]>=0)f[y][s|bs(y)][1]=f[x][s][0]+b[x]+b[y]+a[y];
					if(f[x][s][2]>=0)f[y][s|bs(y)][1]=f[x][s][2]+b[x]+b[y]+a[y];
				}
				else {
					if(f[x][s][0]>=0)cmin(f[y][s|bs(y)][1],f[x][s][0]+b[x]+b[y]+a[y]);
					if(f[x][s][2]>=0)cmin(f[y][s|bs(y)][1],f[x][s][2]+b[x]+b[y]+a[y]);
				}
				
				if(f[y][s|bs(y)][2]<0){
					if(f[x][s][0]>=0)f[y][s|bs(y)][2]=f[x][s][0]+c[x]+c[y]+a[y];
					if(f[x][s][1]>=0)f[y][s|bs(y)][2]=f[x][s][1]+c[x]+c[y]+a[y];
				}
				else {
					if(f[x][s][0]>=0)cmin(f[y][s|bs(y)][2],f[x][s][0]+c[x]+c[y]+a[y]);
					if(f[x][s][1]>=0)cmin(f[y][s|bs(y)][2],f[x][s][1]+c[x]+c[y]+a[y]);
				}
			}
		}
	}
	int ans=2147483647;
	for(int i=1;i<=n;i++){
		if(f[i][(1<<n)-1][0]>=0)cmin(ans,f[i][(1<<n)-1][0]+c[i]);
		if(f[i][(1<<n)-1][1]>=0)cmin(ans,f[i][(1<<n)-1][1]+c[i]);
	}
	printf("%d\n",ans);
	return 0;
}
