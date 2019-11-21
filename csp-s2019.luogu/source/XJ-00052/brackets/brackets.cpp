#include<bits/stdc++.h>
using namespace std;
int n,k,father,yihuohe;
char fuhaochuan;
int yihuohe1()
{
	for(int i=1;i<=n;i++)
	{
		yihuohe=(i*k)&&!+(i*k); 
	}
}
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	cin>>n>>father;
	cin>>fuhaochuan;
	cout<<yihuohe1()<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
