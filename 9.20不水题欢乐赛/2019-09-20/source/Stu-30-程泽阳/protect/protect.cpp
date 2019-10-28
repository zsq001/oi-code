#include<cstdio>
#include<math.h>
double ans,num;
struct node{
	int x,y;
}e[110];

double pw(int a,int b,int aa,int bb)
{
	double z;
	z=((aa-a)*(aa-a))+((bb-b)*(bb-b));
//	z=sqrt(z);
	return z;
}

int main()
{
	int n,i,j;
	int xx,yy;
	freopen("protect.in","r",stdin);
	freopen("protect.out","w",stdout);
	scanf("%d",&n);
	int m=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&xx,&yy);
		e[++m].x=xx;
		e[++m].y=yy;
	}
	j=1;
	for(i=1;i<=n;i++){
		if(j==0){
			j=1;
			continue;
		}
		else{
			j=0;
			if(i>1){
				num=pw(e[i-1].x,e[i-1].y,e[i].x,e[i].y);
				ans+=num*num;	
			}
			if(i+1<n)
			{
				num=pw(e[i+1].x,e[i+1].y,e[i].x,e[i].y);
				ans+=num*num;
			}
		}
	}
	printf("%.2lf",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
