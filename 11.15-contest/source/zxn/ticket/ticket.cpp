#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
#define maxn 
int in(){
	int ret=0;char ch=getchar();
	while(ch<'0'||ch>'9') {ch=getchar(); }
	while(ch<='9'&&ch>='0'){
		ret=(ret<<3)+(ret<<1)+(ch&15);
		ch=getchar();
	}
	return ret;
}

int L,c[30],a[30],n,cnt,tot;
const int ef=25000;
bool f[30],is[30];

void Print(){
	for(int i=1;i<=L;i++) printf("%c",a[i]+'a');
	puts("");
	++tot;
	if(tot==25000) exit(0);
}

void dfs(int pos,int now,bool yuan){
	if( now==L+1 && yuan ) Print();
	if( pos== n+1 || now==L+1 ) return ;
	if( n-pos < L-now ) return ;
	a[now]=c[pos];
	dfs( pos+1 ,now+1 ,yuan | is[a[now]] );
	dfs( pos+1 ,now ,yuan );
}

int main(){
	freopen("ticket.in","r",stdin);
	freopen("ticket.out","w",stdout);
	L=in();
	n=in();
	char ccc[2];
	for(int i=1;i<=n;i++){
		scanf("%s",ccc);
		f[ccc[0]-'a']=1;
	}
	for(int i=0;i<26;i++){
		if(f[i]) c[++cnt]=i;
	}
	is[0]=is[4]=is[8]=is[14]=is[20]=1;
	dfs(1,1,0);
//	abcdefghijklmnopqrstuvwxyz
//	1   5   9     15    21
	return 0;
}
//4 6
//a t c i s w
