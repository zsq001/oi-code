#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for (register int i=x;i<=y;++i)
using namespace std; 
int l,n,a[30],ci; bool x[30]; 
void dfs(int mqd,int mqc){
	if (mqd>n+1||ci>=25000||mqc>l) return; 
	if (mqc==l) {
		int u=0,v=0; 
		rep(i,1,26) 
		 if (x[i]&&(i==1||i==5||i==9||i==15||i==21)) u++;  else if (x[i]) v++; 
	 	if (u>=1&&v>=2){ci++; rep(i,1,26) if (x[i]) putchar(96+i); putchar('\n');}
		return; 
	}
	x[a[mqd]]=1; dfs(mqd+1,mqc+1); x[a[mqd]]=0; 
	dfs(mqd+1,mqc); 
}
int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout); 
	memset(x,0,sizeof(x)); 
	scanf("%d%d\n",&l,&n); 
	rep(i,1,n) a[i]=getchar()-96,getchar(); sort(a+1,a+n+1); 
    dfs(1,0); 
    fclose(stdin);
    fclose(stdout);
    return 0;
}

