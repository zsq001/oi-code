#include<iostream>
#include<cstdio>
using namespace std;
int a[1001][1001];
int main()
{
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	memset(a,0,sizeof(a));
	int m,n,k=0,i,j,total=0,f=0;
	cin>>n>>m;
	for(i=0;i<n;i++)
	for(j=1;j<=m;j++)
	{
		cin>>a[i][j];
	}
	for(i=0;i<n;i++)
    for(j=1;j<=m;j++)
    {
    	k=a[0][1]*a[i][j];
    	total+=k;
    }
    total-=1;
    cout<<total<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
