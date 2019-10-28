#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
int main(){
	int n,op,j;
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int q,cnt=0;
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&op,&j);
		if(op==2){
			int change;
			scanf("%d",&change);
			a[j]=change;
		} else{
			for(int i=j;i<n;i+=a[i])cnt++;
			printf("%d\n",cnt);
		}
		cnt=0;
	}
}
