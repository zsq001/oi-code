#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;

struct node{
	int next,to;
}e[10050];
stack<int> ss;
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int n,m,cnt,tot;
int dfn[2501],vis[2501],low[2501],head[2501];
char s[2501][2501];

void add(int from,int to){
	e[++cnt].next=head[from];
	e[cnt].to=to;
	head[from]=cnt;
}


void tarjan(int o){
	ss.push(o);
	vis[o]=1;
	low[o]=dfn[o]=++cnt;
	for(int i=head[o];i!=0;i=e[i].next){
		int x=e[i].to;
		if(dfn[x]==0){
			tarjan(x);
			low[o]=min()
		}
	}
}

int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<4;k++){
				if((i+d[k][0]) <= n && (i+d[k][0]) >= 1){
					if((j+d[k][1]) < m && (j+d[k][1]) >= 0){
						if(s[i][j] == s[i+d[k][0]][j+d[k][1]]){
							add((i-1)*m+j+1,(i+d[k][0]-1)*m+j+d[k][1]+1);
							add((i+d[k][0]-1)*m+j+d[k][1]+1,(i-1)*m+j+1);
						}
					}
				}
			}
		}
	}
	cnt=0;
	for(int i=1;i<=n*m;i++){
		if(dfn[i]==0) tarjan(i);
	}
} 
