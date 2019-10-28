#include<cstdio>
#include<algorithm>
#define For(i,_n) for(int i=1;i<=_n;++i)
using namespace std;
int ans;
int A[100010],B[100010];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m,p,q;
	scanf("%d %d %d %d",&n,&m,&p,&q);
	if(n>=m){
		For(i,n)scanf("%d",A+i);
		For(i,m)scanf("%d",B+i);
		for(int i=1,j=1;i<=m&&j<=n;i++){
			while(B[i]>A[j]+q&&j<=n)++j;
			if(B[i]>=A[j]-p&&j<=n)++ans,++j;
		}		
	}
	else {
		swap(p,q);
		For(i,n)scanf("%d",B+i);
		For(i,m)scanf("%d",A+i);
		for(int i=1,j=1;i<=n&&j<=m;i++){
			while(B[i]>A[j]+q&&j<=m)++j;
			if(B[i]>=A[j]-p&&j<=m)++ans,++j;
		}

	}
	printf("%d",ans);
	return 0;
}
