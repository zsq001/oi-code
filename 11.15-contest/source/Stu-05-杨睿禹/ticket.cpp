#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<cmath>
#define oo 1000000007
#define N 500100
#define M 5010
#define P 510
using namespace std ;
struct node{
	char ch;
	int num;
}a[N];
bool cmp(node x,node y){
	return x.ch<y.ch;
}
int l,n,flag[N],cnt1,cnt2,pr[N],vis[N],cnt;
void dfs(int x,int lat){
	if(x>l and cnt1>=1 and cnt2>=2){
		if(cnt>25000) exit(0);
		else cnt++;
		for(int i=1;i<=l;i++){
			cout<<a[pr[i]].ch;
		}
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		if(a[i].num<lat) continue;
		if(flag[a[i].num]==1){
			cnt1++;
			vis[i]=1;
			pr[x]=i;
			dfs(x+1,a[pr[x]].num);
			pr[x]=0;
			cnt1--;
			vis[i]=0;
		}
		if(flag[a[i].num]!=1){
			cnt2++;
			vis[i]=1;
			pr[x]=i;
			dfs(x+1,a[pr[x]].num);
			pr[x]=0;
			cnt2--;
			vis[i]=0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	cin>>l>>n;
	flag['a'-'a'+1]=flag['e'-'a'+1]=flag['i'-'a'+1]=flag['o'-'a'+1]=flag['u'-'a'+1]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].ch;
		a[i].num=a[i].ch-'a'+1;
	}
	sort(a+1,a+n+1,cmp);
	dfs(1,0);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
