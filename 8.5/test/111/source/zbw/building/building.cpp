#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
struct node{
	int x,y;
}a[100010];
int n,m,num,v[100010];
double maxk;
int main(){
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int cnt=0;
		maxk=0,num=0;
		scanf("%d%d",&a[i].x,&a[i].y);
		v[a[i].x]++;
		if(v[a[i].x]>1){
			for(int j=1;j<=i;j++){
				if(a[j].x==a[i].x){
					a[j].x=a[i].x;
					a[j].y=a[i].y;
					i--,m--,cnt--;
					break;
				}
			}
		}
		for(int j=1;j<=i;j++){
			double tmp=a[j].y/a[j].x;
			if(tmp>maxk) num=j;
			maxk=max(maxk,tmp);
		}
		for(int j=1;j<=i;j++){
			if(num==j) continue;
			if(maxk*a[j].x*1ll>=a[j].y*1ll) cnt++;
		}
		printf("%d\n",i-cnt);
	}
	return 0;
}
