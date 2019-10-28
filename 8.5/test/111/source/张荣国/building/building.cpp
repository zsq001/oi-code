#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define maxn 100005
using namespace std;
template <class T> void read(T &x){
	bool t=0;x=0;char s=getchar();
	while(s<'0'||s>'9') { if(s=='-') t=1;s=getchar();}
	while(s>='0'&&s<='9'){ x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x=t?-x:x;
}
priority_queue <int> q;
struct node{
	int y;
	double k;
}bu[maxn];
double calc(int x,int y){
	return (double)y/(double)x;
}
double max_k[maxn],b[maxn],mx;
int cnt,n,m,x,tmp;
bool flag;
int main(){
	freopen("building.in","r",stdin);
	freopen("building.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++){
		read(x);
		if(bu[x].y) {
			tmp=bu[x].y;
			flag=1;	
		}
		read(bu[x].y);
		if(tmp<=bu[x].y) flag=0;
		bu[x].k=calc(x,bu[x].y);
		mx=0;
		for(int i=1;i<=n;i++){
			if(bu[i].k<=mx) continue;
			else cnt++;
			mx=max(mx,bu[i].k);
		}
		printf("%d\n",cnt);
		cnt=0;
	}
	return 0;
}
