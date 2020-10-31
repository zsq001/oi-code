#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define inf 1<<29 
#define ll long long
#define mod 99983
using namespace std;
int cnt,n,snow[100010][14],head[mod];
struct Hash{
	int val;
	int ne;
	int b;
}hash[12000010];
void insert(int x,int b)
{
	int y=x%mod;
	hash[++cnt].val=x;
	hash[cnt].ne=head[y];
	hash[cnt].b=b;
	head[y]=cnt;
}
bool query(int x,int b)
{
	int y=x%mod;
	for(int i=head[y];i;i=hash[i].ne) if(hash[i].val==x&&b!=hash[i].b){
		for(int j=1;j<=6;++j)
			if((snow[b][1]==snow[hash[i].b][j]&&snow[b][2]==snow[hash[i].b][j+1]&&snow[b][3]==snow[hash[i].b][j+2]&&snow[b][4]==snow[hash[i].b][j+3]&&snow[b][5]==snow[hash[i].b][j+4]&&snow[b][6]==snow[hash[i].b][j+5])
			||(snow[b][1]==snow[hash[i].b][13-j]&&snow[b][2]==snow[hash[i].b][12-j]&&snow[b][3]==snow[hash[i].b][11-j]&&snow[b][4]==snow[hash[i].b][10-j]&&snow[b][5]==snow[hash[i].b][9-j]&&snow[b][6]==snow[hash[i].b][8-j]))
			return true;		
	}
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int t=0;
		for(int j=1;j<=6;++j){
			scanf("%d",&snow[i][j]);
			t+=snow[i][j];
			snow[i][j+6]=snow[i][j];
		}
		insert(t,i);
		if(query(t,i)){
			puts("Twin snowflakes found.");
			return 0;
		}
	}
	puts("No two snowflakes are alike.");
	return 0;
}
