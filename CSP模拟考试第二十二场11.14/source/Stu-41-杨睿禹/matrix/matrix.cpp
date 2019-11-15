#include<cstdio>
#include<algorithm>
#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
#define oo 1000000007
#define N 500100
#define M 1010
#define p 510
using namespace std;
//int x[N],y[N],z[N];
int n,m,q,x,y,z,h[N],tmeh[N],l[N],tmel[N];
int main(){
//	std::ios::sync_with_stdio(false);
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
//	cin>>n>>m>>q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++){
//		cin>>x>>y>>z;
		scanf("%d%d%d",&x,&y,&z);
		if(x==1){
			h[y]=z;
			tmeh[y]=i;
		}
		if(x==2){
			l[y]=z;
			tmel[y]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tmeh[i]>tmel[j]){
//				cout<<h[i]<<" ";
				printf("%d ",h[i]);
			}
			else if(tmel[j]>tmeh[i]){
//				cout<<l[j]<<" ";
				printf("%d ",l[j]);
			}
//			else cout<<"0"<<" ";
			else printf("0 ");
		}
//		cout<<endl;
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
