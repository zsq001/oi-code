#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int tree[10050];

int n,h,b,e,mint[10050];
int c[100050],ans[100050];

int lowbit(int o){
	return (-o)&o;
}

int query(int o){
	int ret=0;
	while(o>0){
		ret+=tree[o];
		o-=lowbit(o);
	}
	return ret;
}

void upd(int o,int x){
	while(o<=1e4){
		tree[o]+=x;
		o+=lowbit(o);
	}
	return ;
}

void upd_aoe(int o){
	for(int i=1;i<=o;i++){
		tree[i]=0;
	}
	return ;
}

void updmin(int o,int x){
	while(o<=1e4){
		mint[o]+=x;
		o+=lowbit(o);
	}
}
bool querymin(int o){
	int ret=0;
	while(o>0){
		ret+=mint[o];
		o-=lowbit(o);
	}
	if(ret!=0) return true;
	else return false;
}

int main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
    while(~scanf("%d %d %d %d",&n,&h,&b,&e)){
    	for(int i=1;i<=n;i++){
    		scanf("%d",&c[i]);
		}
		memset(tree,0,sizeof(tree));
		memset(mint,0,sizeof(mint));
		for(int i=n;i>=1 && i>=(n-h+1);i--){
			updmin(c[i],1);
		}
		for(int i=n;i>=1;i--){
			upd(10001-c[i],1);
			if(!querymin(c[i]-1)){
				ans[i]=query(10001-c[i]);
				upd_aoe(10001-c[i]);
			}	
			updmin(c[i],-1);
			if(i-h > 0) updmin(c[i-h],1);
		}
		for(int i=b;i<=e;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	return 0;
}
