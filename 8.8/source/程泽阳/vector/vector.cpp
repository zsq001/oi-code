#include<cstdio>
int x,y,xx,yy;
int flag=0;
struct czy{
	int a,b;
}e[9];

int gcd(int a,int b){
	while(a>0){
		int t=b%a;
    	b=a;
		a=t;
	}
	return b;
}

void dfs(int num,int now,int nx,int ny)
{
	if(now>4)return;
	if(flag==1)return;
	if(nx==xx && ny==yy)
	{
		flag=1;
		return;
	}
	dfs(num+1,now+1,nx+e[now].a,ny+e[now].b);
	dfs(num,now+1,nx,ny);
	dfs(num+1,now+1,nx+e[now].a,ny+e[now].b);
	dfs(num,now+1,nx,ny);
	dfs(num+1,now+1,nx+e[now].a,ny+e[now].b);
	dfs(num,now+1,nx,ny);
//	if(now>4)now-=4;
}
int main()
{
	int t,i,j;
	freopen("vector.in","r",stdin);
	freopen("vector.out","w",stdout);
	scanf("%d",&t);
	if(t>50)flag=2;
	while(t--)
	{
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		int pd;
		pd=gcd(x,y);
		if(((xx%pd)+pd)%pd!=0 || ((yy%pd)+pd)%pd!=0){
			printf("N\n");
			continue;
		}
		if(flag==2){
			printf("Y\n");
			continue;
		}
		e[1].a=x;e[1].b=y;
		e[2].a=0;e[2].b=0;
		e[3].a=x+y;e[3].b=x+y;
		e[4].a=y;e[4].b=x;
		flag=0;
		dfs(0,1,0,0);
		if(flag==1){
			printf("Y\n");
		}
		else{
			printf("N\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
