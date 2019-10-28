#include <cstdio>
int N,M,X,Y,ans;
int A[100010],B[100010];
void input(){
	scanf("%d%d%d%d",&N,&M,&X,&Y);
	for(int i=1;i<=N;++i) scanf("%d",&A[i]);
	for(int i=1;i<=M;++i) scanf("%d",&B[i]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	input();
	for(int i=1;i<=M;++i)
		for(int j=1;j<=N;++j)
			if(B[i]>=A[j]-X&&B[i]<=A[j]+Y) {++ans; A[j]=-1e9; break;}
	printf("%d",ans);
	return 0;
}
