#include<cstdio>
#include<algorithm>
using namespace std;
#define MOD 1000000007


struct node{
	int l,r;
	int mid;
	int bl,fl,lth;
	int num[2];
}q[2050];
int n,m,ans,tot,pt=1,s[2050];
int fac[2050],inv[2050];

int mod(int o,int p){
	return ((o%p)+p)%p;
}

void exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
	}
    else{
    	exgcd(b,a%b,y,x);
    	y-=1ll*(a/b)*x;
	}
}



void prework(){
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=(1ll*fac[i-1]*i)%MOD;
	}
    int x,y;
	exgcd(fac[n],MOD,x,y);
	inv[n]=mod(x,MOD);inv[0]=1;
	for(int i=n-1;i>=1;i--){
		inv[i]=(1ll*inv[i+1]*(i+1))%MOD;
	}
}


int dfs(int o){
	if(o==m){
		return (1ll*((1ll*fac[q[o].lth]*inv[q[o].num[0]])%MOD)*inv[q[o].num[1]])%MOD;
	}
	int ret=0;
	for(int i=min(q[o].bl,q[o].num[1]);i>=0 && q[o].num[0]+i>=q[o].bl;i--){
        q[o+1].num[1]+=i;
		q[o+1].num[0]+=q[o].bl-i;
		q[o].num[1]-=i;
		q[o].num[0]-=q[o].bl-i;
		ret=(ret+1ll*((1ll*((1ll*fac[q[o].lth-q[o].bl]*inv[q[o].num[1]])%MOD)*inv[q[o].num[0]])%MOD)*dfs(o+1)%MOD)%MOD;
		q[o+1].num[1]-=i;
		q[o+1].num[0]-=q[o].bl-i;
		q[o].num[1]+=i;
		q[o].num[0]+=q[o].bl-i;
	}
	return ret;
}


int main()
{
	freopen("university.in","r",stdin);
	freopen("university.out","w",stdout);
	scanf("%d %d",&n,&m);
	prework();
	for(int i=1;i<=n;i++){
		scanf("%1d",&s[i]);
	}
	for(int i=1;i<=m;i++){
		tot++;
		scanf("%d %d",&q[tot].l,&q[tot].r);
		if(q[tot].r <= q[tot-1].r){
			tot--;
			continue;
		}
	    q[tot-1].mid=q[tot].l;
		q[tot-1].bl=q[tot-1].r-q[tot-1].mid+1;
		if(q[tot-1].bl<0) q[tot-1].bl=0;
		q[tot].fl=q[tot-1].bl;
		q[tot].lth=q[tot].r-q[tot].l+1;
	}
	m=tot;tot=0;
	for(int i=1;i<=m;i++){
		while(pt<q[i].l) pt++;
		while(pt<=q[i].r){
			q[i].num[s[pt]]++;
			pt++;
		}
	}
	
	ans=dfs(1);
	
	printf("%d",ans);
	return 0;
}
