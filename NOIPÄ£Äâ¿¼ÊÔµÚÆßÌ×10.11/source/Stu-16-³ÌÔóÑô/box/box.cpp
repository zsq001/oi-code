#include<cstdio>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int> > q;
int ans=1,num;
int x,y,z;
int main()
{
	int v,i,j,n;
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	scanf("%d",&n);
	v=n;
	for(i=2;i<=n;i)
	{
		if(v==1){
			break;
		}
		if(v%i==0){
			q.push(i);
			num++;
			v=v/i;
		}
		else{
			i++;
		}
	}
	if(num==1){
		q.push(1);
		q.push(1);
		num=3;
	}
	if(num==2){
		q.push(1);
		num=3;
	}
	if(num==3){
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		z=q.top();
		q.pop();
		ans=2*(x*y + x*z + y*z);
		printf("%d",ans);
		return 0;
	}
	for(i=1;num>3;i++)
	{
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		q.push(x*y);
		num--;
	}
	if(num==3){
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		z=q.top();
		q.pop();
		ans=2*(x*y + x*z + y*z);
		printf("%d",ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	return 0;
}
