#include<cstdio>
using namespace std;
int A[11110],B[11110];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,m,p,q;
	scanf("%d %d %d %d",&n,&m,&p,&q); 
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]); 
	for(int i=1;i<=m;i++)
		scanf("%d",&B[i]);
	int i=1,j=1,cnt=0;
	while(true){
		if(j>m||i>n)break; 
		if(A[i]-p<=B[j]&&B[j]<=A[i]-q){
			++i,++j;
			++cnt;
		}
		else if(A[i]-p<=B[j]){
			if(i<=n)++i;	
		}
		else {
			if(j<=m)++j;	
		}	
	} 
	printf("%d",cnt);
	return 0;
} 
