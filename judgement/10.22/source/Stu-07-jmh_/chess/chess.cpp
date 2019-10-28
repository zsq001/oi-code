#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,fa[6250050],num[6250050];
char s[2501][2501];

int findd(int x){
	if(x!=fa[x]) return fa[x]=findd(fa[x]);
	else return fa[x];
}

void add(int x,int y){
	int anx=findd(x),any=findd(y);
	if(anx==any) return ;
	num[anx]+=num[any];
	num[any]=0;
	fa[any]=anx;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<= n*m;i++){
		num[i]=1;
		fa[i]=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=0;j<m;j++){
			if(j-1>=0 && s[i][j]==s[i][j-1]){
				add((i-1)*m+j+1,(i-1)*m+j);
			}
			if(j+1<m && s[i][j]==s[i][j+1]){
				add((i-1)*m+j+1,(i-1)*m+j+2);
			}
			if(i-1>0 && s[i][j]==s[i-1][j]){
				add((i-1)*m+j+1,(i-2)*m+j+1);
			}
		}
	}
	for(int i=1;i<= n*m;i++){
		if(num[i]>=4){
			printf("Yes");
			return 0;
		}
	}
	printf("No");
	return 0;
}
