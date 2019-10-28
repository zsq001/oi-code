#include<iostream>
#include<queue>
#define mmm 1000
using namespace std;
int yd[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[1000][1000];
int con[1000][1000];
int r,c;
struct node{
	int x,y;
};
int main()
{
	node s;
	cin>>r>>c;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		cin>>a[i][j];
	for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            con[i][j]=mmm;		
	s.x=1;
	s.y=1;
	queue<node> q;
	q.push(s); 
	while(con[r][c]==mmm)
	{
		int x1=q.front().x;
		int y1=q.front().y;
		q.pop() ;
		for(int i=0;i<=3;i++)
		{
			if(a[x1+yd[i][0]][y1+yd[i][1]]=='.'&&con[x1+yd[i][0]][y1+yd[i][1]]==mmm)
			{
				con[x1+yd[i][0]][y1+yd[i][1]]=con[x1][y1]+1;
				s.x=x1+yd[i][0];
				s.y=y1+yd[i][1];
				q.push(s); 
			}
		}
	}
	cout<<con[r][c]+1-mmm;
} 
