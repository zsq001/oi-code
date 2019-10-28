#include<cstdio>
#include<algorithm>
using namespace std;
int A[101000],B[101000],f[1010][1010],n,m,p,q,len;
void solve_1(){
	for(int i=1;i<=len;i++)
		f[i][0]=f[0][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(A[i]-p<=B[j]&&B[j]<=A[i]+q)f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=max(f[i-1][j],f[i][j-1]);
		}
	printf("%d",f[n][m]);
}
bool check(int x){
	return false;
}
int Search(int l,int r){
	if(l<=r+1)return check(r)?l:r;
	int m=(l+r)>>1;
	if(check(m))return Search(l,m);
	else return Search(m,r);
}
void solve_2(){
	Search(1,len+1);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&B[i]);
	len=max(n,m);
    solve_1();
//	else solve_2();
	return 0;
}
