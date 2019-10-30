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
void luo()
{
	for(int i=1;i<=5;i++)
	{
		 for(int j=1,x=0;j<=7;j++)
		 {
			if(!yuan[i][j])
				x++;
			else 
			{
				yuan[i][j-x]=yuan[i][j];
				yuan[i][j]=0;
			}
		 }
	}
}
bool kill()
{
	int fl=0;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=7;j++)
		{
		}	
}
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
