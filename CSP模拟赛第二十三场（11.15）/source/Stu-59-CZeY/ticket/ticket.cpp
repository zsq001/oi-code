#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,tot;
int ans;
bool flag;
int map[16];
struct node{
	char x;
	int val;
}e[30];

bool CMP(node a,node b){
	return a.x<b.x;
}


void P(){
	int i;
	ans++;
	for(i=1;i<=n;i++){
		printf("%c",e[map[i]].x);
	}
	printf("\n");
}

void dfs(int now,int v,int num){
	if(ans>=25000){
		flag=true;
		return ;
	}
	if(now>m || flag==true){
		return ;
	}
	if(num >= n){
		if(v==0){
			P();
		}
		return ;
	}
	for(int i=now+1;i<=m;i++){
		map[++tot]=i;
		dfs(i,v*e[i].val,num+1);
		tot--;
	}
	return ;
}

int main()
{
	int i,j;
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	for(i=1;i<m;i++){
		scanf("%c ",&e[i].x);
		if(e[i].x=='a' || e[i].x=='e' || e[i].x=='i' || e[i].x=='o' || e[i].x=='u'){
			e[i].val=0;
		}
		else {
			e[i].val=1;
		}
	}
	scanf("%c",&e[i].x);
	if(e[i].x=='a' || e[i].x=='e' || e[i].x=='i' || e[i].x=='o' || e[i].x=='u'){
		e[i].val=0;
	}
	else {
		e[i].val=1;
	}
	sort(e+1,e+1+m,CMP);
	for(i=1;i<=m;i++){
		if(flag==true){
			return 0;
		}
		map[++tot]=i;
		dfs(i,e[i].val,1);
		tot--;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
