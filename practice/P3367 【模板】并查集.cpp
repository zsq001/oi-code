#include<iostream>
using namespace std;
int fat[100000];
int find(int x)
{
	if(fat[x]==x)
	return x;
	else
	return fat[x]=find(fat[x]); 
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int j=1;j<=n;j++)
		fat[j]=j;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>z>>x>>y;
		if(z==1)
		fat[find(x)]=find(y);
		else if(z==2)
		{
			if(find(x)==find(y))
			cout<<"Y"<<endl;
			else
			cout<<"N"<<endl;
		}
	}
	return 0;
}
