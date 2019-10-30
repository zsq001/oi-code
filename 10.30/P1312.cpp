#include<iostream>
#include<cstdio>
#define mmm 20
using namespace std;
int yuan[mmm][mmm],cop[mmm][mmm][mmm];
void cp(int qwq)
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
			cop[qwq][i][j]=yuan[i][j];
}
void update()
int main()
{
	int n,x;
	cin>>n;
	for(int i=0,j=-1;i<=5;i++)
	{
		j=-1;
		while(cin>>x)
		{
			if(x==0)
				break;
			j++;
			yuan[i][j]=x;
		}
	}
}
