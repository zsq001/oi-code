#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
//typedef int int_;
//#define int long long


int n,m,q,cnt,tot;
int e[300][300],v[300][300],val[300];





int main()
{
	freopen("roadtoll.in","r",stdin);
	freopen("roadtoll.out","w",stdout);
	memset(e,0x1f,sizeof(e));
	memset(v,0x1f,sizeof(v));
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		e[i][i]=0;
		scanf("%d",&val[i]);
		v[i][i]=val[i];
	}
	for(int i=1;i<=m;i++){
		int tp1,tp2,tp3;
		scanf("%d %d %d",&tp1,&tp2,&tp3);
		e[tp1][tp2]=e[tp2][tp1]=min(tp3,e[tp1][tp2]);
		v[tp1][tp2]=v[tp2][tp1]=max(val[tp1],val[tp2]);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int tp1=e[i][j]+v[i][j];
				int tp2=e[i][k]+e[k][j]+max(v[i][k],v[k][j]);
				if(tp1>tp2){
					e[j][i]=e[i][j]=e[i][k]+e[k][j];
					v[j][i]=v[i][j]=max(v[i][k],v[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int tp1,tp2;
		scanf("%d %d",&tp1,&tp2);
		printf("%d\n",e[tp1][tp2]+v[tp1][tp2]);
	}
	return 0;
}
