#include<bits/stdc++.h>
using namespace std;
int c[60],b[60],ans=0,n,i;
long long int hie,m;
int pok(int a,int f)
{
    if(f<=n)
    {
	if(m>=a*(f-1)&&a!=0) 
	{
	if(hie>=a*(f-1))
		{ans++;
		hie=hie-a*(f-1)+a;
		m-=a*(f-1);
		}
	
    else if(m>=a*(f-1)&&a!=0&&hie<a*(f-1)&&a*(f-1)-hie!=1)
	{
		while((hie-(f-1))<0)
		{
		i=1;i++;
		hie-=i*(f-1);
		}
		ans+=i;
	}
	else if(a*(f-1)-hie==1)
	{	ans++;	}
	//if(m>=a*(f-1)&&a!=0&&hie>=a*(f-1))
    pok(b[f+1]-b[f],f+1);
	
	}
}
}
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	//freopen("poker.in","r",stdin);
//	freopen("poker.out","w",stdout);
	int min=2147483647;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
	scanf("%d",&c[i]);
	if(min>c[i])
	min=c[i];
	}
	ans+=min;
	hie=ans;
	for(int i=1;i<=n;i++)
	b[i]=c[i]+1;
	sort(b+1,b+n+1,cmp);
   
  	pok(b[2]-b[1],2);
   	printf("%d",ans);
 //  	fclose(stdin);
//   	fclose(stdout);
}
