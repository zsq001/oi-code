#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define maxn 1000010
#define ll long long
using namespace std;
bool ok(int x,int y){return x>0&&x<4&&y>0&&y<4;}
//int cal(int x,int y){return (x-1)*3+y;}
//1,2,3,8,0,4,7,6,5
char s[110],t[4][4]={{},{0,1,2,3},{0,8,0,4},{0,7,6,5}};
int dx[]={0,1,0,-1},dy[]={1,0,-1,0},mp[4][4],mo[20][2],dis[20],T,sx,sy,tot; 
bool pd(){
	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			if(mp[i][j]!=t[i][j]) return false;
	return true;
}
void dfs(int f,int x,int y,int pre){
	if(f>T){
		if(pd()){
			cout<<T<<endl;
			exit(0);
		}
		return;
	}
	for(int i=0;i<4;++i){
		int X=x+dx[i],Y=y+dy[i],num=mp[X][Y];
		if(num!=pre&&ok(X,Y)){
			mp[x][y]=num;
			mp[X][Y]=0;
			dfs(f+1,X,Y,num);
			mp[x][y]=0;
			mp[X][Y]=num;
		}
	}
}
int main()
{
	scanf("%s",s+1);
	for(int k=1;k<=9;++k){
		int i=(k-1)/3+1;
		int j=(k-1)%3+1;
		int num=mp[i][j]=s[k]-'0';
		if(!num){
			sx=i;
			sy=j;
		}
	}
	if(pd()){
		cout<<0<<endl;
		return 0; 
	}
	while(1){
		T++;
		dfs(1,sx,sy,0);
	}
	return 0;
}
