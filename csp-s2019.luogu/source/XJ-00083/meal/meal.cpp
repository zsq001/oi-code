#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=105;
const int M=2005;
const ll P=998244353;

int n,m;
int a[N][M];

int sum(int x,int y){return (1ll*x+1ll*y)%P;}
int mul(int x,int y){return 1ll*x*y%P;}

namespace pt2{
	int f[45][45][45];
	void solve(){
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)f[i][j][k]=-1;
		
		f[0][0][0]=1; bool o;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=(n>>1);j++){
				for(int k=0;k<=(n>>1);k++){
					o=0;
					f[i][j][k]=0;
					
					if(f[i-1][j-1][k]!=-1)
						if(j>0&&a[i][1]>0)o=1,f[i][j][k]=sum(f[i][j][k],mul(f[i-1][j-1][k],a[i][1]));
					
					if(f[i-1][j][k-1]!=-1)
						if(k>0&&a[i][2]>0)o=1,f[i][j][k]=sum(f[i][j][k],mul(f[i-1][j][k-1],a[i][2]));
					
					if(f[i-1][j][k]!=-1)
						o=1,f[i][j][k]=sum(f[i][j][k],f[i-1][j][k]);
						
					if(o==0)f[i][j][k]=-1;
				}
			}
		}
		int ans=0;
		for(int i=1;(i<<1)<=n;i++)
			if(f[n][i][i]!=-1)ans=sum(ans,f[n][i][i]);
		printf("%d\n",ans);
		return ;
	}
}

namespace pt3{
	int f[45][45][45][45];
	void solve(){
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)for(int l=0;l<=n;l++)
			f[i][j][k][l]=-1;
		
		f[0][0][0][0]=1;
		int tn=n>>1; bool o;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=tn;j++)
				for(int k=0;k<=tn;k++)
					for(int l=0;l<=tn;l++){
						o=0;
						f[i][j][k][l]=0;
						
						if(f[i-1][j-1][k][l]!=-1)
							if(j>0&&a[i][1]>0)o=1,f[i][j][k][l]=sum(f[i][j][k][l],mul(f[i-1][j-1][k][l],a[i][1]));
						if(f[i-1][j][k-1][l]!=-1)
							if(k>0&&a[i][2]>0)o=1,f[i][j][k][l]=sum(f[i][j][k][l],mul(f[i-1][j][k-1][l],a[i][2]));
						if(f[i-1][j][k][l-1]!=-1)
							if(l>0&&a[i][3]>0)o=1,f[i][j][k][l]=sum(f[i][j][k][l],mul(f[i-1][j][k][l-1],a[i][3]));
						if(f[i-1][j][k][l]!=-1)
							o=1,f[i][j][k][l]=sum(f[i][j][k][l],f[i-1][j][k][l]);
						
						if(o==0)f[i][j][k][l]=-1;
					}
		int ans=0,ts;
		for(int i=1;(i<<1)<=n;i++){
			if(f[n][i][i][0]!=-1)ans=sum(ans,f[n][i][i][0]);
			if(f[n][i][0][i]!=-1)ans=sum(ans,f[n][i][0][i]);
			if(f[n][0][i][i]!=-1)ans=sum(ans,f[n][0][i][i]);
		}
		for(int a=1;a<=tn;a++){
			for(int b=1;b<=tn;b++){
				for(int c=1;c<=tn;c++){
					ts=(a+b+c)>>1;
					if(a>ts||b>ts||c>ts)continue;
					if(f[n][a][b][c]!=-1)
						ans=sum(ans,f[n][a][b][c]);
				}
			}
		}
		printf("%d\n",ans);
		return ;
	}
}

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	if(m==2)pt2::solve();
	else if(m==3)pt3::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
