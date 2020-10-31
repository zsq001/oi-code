#include<iostream>
#include<cstdio>
using namespace std;
#define mmm 10001
int n,tot=0,fl[mmm][mmm],ans[mmm];
void dfs(int w)
{
	if(w>n)
	{
		tot++;
		if(tot>3)
			return ;
		for(int i=1;i<=n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
		if((!fl[1][i])&&(!fl[2][i+w])&&(!fl[3][w-i+n]))
		{
			ans[w]=i;
			fl[1][i]=1;
			fl[2][w+i]=1;
			fl[3][w-i+n]=1;
			dfs(w+1);
			fl[1][i]=0;
			fl[2][w+i]=0;
			fl[3][w-i+n]=0;
		}
}
int main()
{
	cin>>n;
	dfs(1);
	cout<<tot;
	return 0;
}
