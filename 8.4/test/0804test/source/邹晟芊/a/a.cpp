#include<iostream>
#include<algorithm>
#define mmm 200001
using namespace std;
struct node{
	int num,val,vis;
}a[mmm];
bool ju(node a,node b)
{
	return a.val>b.val;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int n,m,w=0,aai,bbi;
	int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val;
		a[i].num=i;
		a[i].vis=0;
	}
	if(n<2*m)
	{
		cout<<"Error!";
		return 0;
	}
	int i=0;
	sort(a+1,a+1+n,ju);
	while(w!=m)
	{
		i++; 
		int x=1;
		int k=0;
		while(x&&i!=1)
		{   
			k++;
			if(a[k].num==a[i].num-1)
			{
				aai=k;
			}
			if(a[k].num==a[i].num+1)
			{
				bbi=k;
			}
			if(a[k].num==a[i].num-1&&a[k].vis==1)
			{
				x=0;
				break;
			}
			if(a[k].num==a[i].num+1&&a[k].vis==1)
			{
				x=0;
				break;
			}
			if(k==n)
			break;
		}
		if(x==0)
		continue;
		else
		{
			ans+=a[i].val;
			a[i].vis=1;
			w++;
		}
	}
	cout<<ans;
	return 0;
}
