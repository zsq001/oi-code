#include<iostream>
#include<queue>
#define mmm 200010
using namespace std;
int next[mmm],rd[mmm],v,cnt;
queue<int>q;
int main()
{
	int n;
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>next[i];
		rd[next[i]]++;
	}
	for(int i=1;i<=n;i++)
	if(!rd[i])
	q.push(i);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		v=next[x];
		rd[v]--;
		if(!rd[v])
		q.push(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(rd[i])
		{
			cnt=1;
			v=next[i];
			while(v!=i)
			{
				rd[v]=0;
				v=next[v];
				cnt++;
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
