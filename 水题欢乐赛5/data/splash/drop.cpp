#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int cnt,mp[7][7],step,DX[]={1,0,-1,0},DY[]={0,1,0,-1};
bool ok(int x,int y){return x>=1&&x<=6&&y>=1&&y<=6;}
void bao_zha(int,int);
void output()
{
	for(int i=1;i<=6;++i){
		for(int j=1;j<=6;++j) printf("%d ",mp[i][j]);
		puts("");
	}
	puts("");
}
void xiao_chu(int x0,int y0,int dx,int dy)
{
	mp[x0][y0]=0;
	int i=x0,j=y0;
	while(ok(i+dx,j+dy)){
		i+=dx,j+=dy;
		if(mp[i][j]){
			mp[i][j]++;
			//output();
			if(mp[i][j]==5) bao_zha(i,j);
			break;
		}
	}
}
void bao_zha(int x0,int y0){
	//printf("bao_zha!!! %d %d\n",x0,y0);
	cnt++;
	for(int k=0;k<4;++k) xiao_chu(x0,y0,DX[k],DY[k]);
	//output();
}
bool kong()
{
	for(int i=1;i<=6;++i)
		for(int j=1;j<=6;++j)
			if(mp[i][j]) return false;
	return true;
}
bool jia()
{
	int x0,y0;
	cnt=0;
	scanf("%d%d",&x0,&y0);
	step++;
	mp[x0][y0]++;
	if(mp[x0][y0]==5) bao_zha(x0,y0);
	step-=cnt/3;
	output();
	printf("step=%d\n",step);
	puts("");
	return kong();
}
int main()
{
	for(int i=1;i<=6;++i)
		for(int j=1;j<=6;++j)
			scanf("%d",&mp[i][j]);
	while(1) if(jia()) break;
	return 0;
}
