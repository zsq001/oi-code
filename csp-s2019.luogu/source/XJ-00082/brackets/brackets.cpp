#include<bits/stdc++.h>
using namespace std;
char c[500001],d[500001],p[500001];
int a[500001],b[500001],x,s[500001],q[500001][201],y[500001],z[500001];
int sum=0,sum1=0,sum2=0,sum3=0,sum4=1,sum5=1,m=1,flag=0,t[500001];
int br(int,int,int);
int w(int);
int main()
{
	freopen("brackets.in","r",stdin);
	freopen("brackets.out","w",stdout);
	int n;
	cin>>n;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=2;i<=n;i++)
	cin>>b[i];
	b[1]=0;
	for(int i=1;i<=n;i++)
	{
	    w(i);
	    for(int j=1;j<=sum;j++)
	    {
	    	p[j]=d[sum-j+1];
	    }
        for(int j=1;j<=sum;j++)
        {
        	br(i,j,j-1);  
			for(int h=1;h<=sum3;h++)
			{
			    if(y[h]==0&&y[h-1]!=0&&y[h-1]!=1) 
				{
				    flag=y[h-1];
				    t[sum5]=h;
				    sum5++;
				    for(int g=1;g<=sum3;g++)
				    {
				    	if(z[g]==flag-1&&g==t[sum5-2]) sum4++;					
				    }
				    a[i]=a[i]+pow(2,sum4)-sum4-1;
			    }
				flag=0;
				sum4=1;
			}
        }
		s[i]=i*a[i];
//        cout<<s[i]<<" ";
        sum=0;  
    }
    for(int i=1;i<=n;i++)
    {
        while(s[i]!=0)
        {
    		sum1++;
            if(s[i]%2==1) q[i][sum1]=1;
            else q[i][sum1]=0;
            s[i]/=2;
        }
        sum1=0;
//        for(int j=1;j<=4;j++)
//        cout<<q[i][j];
//        cout<<endl;
    }
    for(int i=1;i<=n-1;i++)
    {
    	for(int j=1;j<=200;j++)
        {
        	if(q[i][j]==q[i+1][j]) q[i+1][j]=0;
            else q[i+1][j]=1;
        }
    }  
    for(int i=1;i<=200;i++)
    {
    	sum2+=q[n][i]*m;
    	m=m*2;
    }
    cout<<sum2;
    fclose(stdin);fclose(stdout);
	return 0;
}
int w(int n)
{
	if(n==0) return 0;
    sum++;
    d[sum]=c[n];
	w(b[n]);
}
int br(int x,int n,int m)
{
	if(m==0) 
	{
		sum3++;
		y[sum3]=0;
		z[sum3]=0;
		return 0;
	}
	if(p[n]==')'&&p[m]=='(') 
	{
	a[x]++;
	sum3++;
	y[sum3]=m;
	z[sum3]=n;
    }
	else 
	{
	    sum3++;
		y[sum3]=0;
		z[sum3]=0;
		return 0;
	}
	return br(x,n+1,m-1);
}
