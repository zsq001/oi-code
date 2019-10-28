#include<stdio.h>
#include<string.h>
#include<algorithm>
#define maxn 1000010
using namespace std;
int sweet[maxn];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n,m,p,q,cnt=0;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	while(m){
		int l=(m*p+q)%n+1;
		int r=(m*q+p)%n+1;
		if(l>r) swap(l,r);
		for(int i=l;i<=r;i++){
			if(sweet[i]==0){
				sweet[i]=m;
				cnt++;
			}
		}
		if(cnt==n) break;
		m--;
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",sweet[i]);
	}
	return 0;
}
