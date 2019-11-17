#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,c;
int a[31],b[31],cnt;
char s[31],t[31];
bool o[31],vis[31];

void dfs(int d,int lst,int ta,int tb){
	if(ta+a[lst+1]==0)return ;
	if(tb+b[lst+1]<2)return ;
	if(cnt==25000)return ;
	if(d==n){
		if(ta==0||tb<2)return ;
		printf("%s\n",t+1);
		++cnt; return ;
	}
	for(int i=lst+1;i<=c;i++)if(!vis[i]){
		vis[i]=1; t[d+1]=s[i];
		dfs(d+1,i,ta+o[i],tb+(o[i]==0)); vis[i]=0;
	}
}

int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	scanf("%d%d",&n,&c);
	for(int i=1;i<=c;i++){
		scanf("%s",t+1);
		s[i]=t[1];
		if('A'<=s[i]&&s[i]<='Z')s[i]+=32;
	}
	memset(t,0,sizeof(t));
	sort(s+1,s+c+1);
	for(int i=c;i;i--){
		o[i]=(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u');
		a[i]=o[i]+a[i+1];
		b[i]=(o[i]==0)+b[i+1];
	}
	dfs(0,0,0,0);
	return 0;
}
