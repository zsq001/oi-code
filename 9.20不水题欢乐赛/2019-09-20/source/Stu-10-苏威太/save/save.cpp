#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int n,k;int ans;
int a[6][6],b[6][6],c[6][6],nn[16][16],n1[16];	
void QWQ(int q,int y,int u)
{
	//if(y>ans)return;
	if(u==n){
		if(ans>y+nn[q][0]||ans==0)ans=y+nn[q][0];
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(n1[i]==0){
			n1[i]=1;
			QWQ(i,y+nn[q][i],u+1);
			n1[i]=0;
		}
	}
}
void ppp(int z)
{
	for(int i=0;i<5;++i)
	{
		c[0][i]=z%2;
		z/=2;
	}
}
int get(int i,int j)
{
	b[i][j]^=1;
	if(i-1>=0)b[i-1][j]^=1;
	if(i+1<5)b[i+1][j]^=1;
	if(j-1>=0)b[i][j-1]^=1;
	if(j+1<5)b[i][j+1]^=1;
}
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	read(n);
	read(k);
	for(int i=1;i<=n;++i)
	 read(nn[0][i]);
	for(int i=1;i<=n;++i)
	 read(nn[i][0]);
	for(int i=1;i<=n;++i)
	 for(int j=1;j<=n;++j)
	  read(nn[i][j]);
    if(n!=1)
 	QWQ(0,0,0);
    while(n!=0)
    {
    	--n;
    	memset(a,0,sizeof(a));
    	memset(b,0,sizeof(a));
    	memset(c,0,sizeof(a));
    	int l=0;
    	for(int i=0;i<5;++i)
    	 for(int j=0;j<5;++j)
    	 {
    	 	read(a[i][j]);
 		 	if(a[i][j]==0)l=1;
		 }
    	if(l==0){
    		ans+=15*k;
    		continue;
		}
    	for(int z=0;z<32;++z)
    	{
    		for(int i=0;i<5;++i)
    		 for(int j=0;j<5;++j)
    		 {
    		 	b[i][j]=a[i][j];
    		 	c[i][j]=0;
			 }
			 ppp(z);
			 for(int j=0;j<5;++j)
			 {
			 	if(c[0][j]==1)get(0,j);
			 }
			 for(int i=1;i<5;++i)
			 {
			 	for(int j=0;j<5;++j)
			 	{
			 		if(b[i-1][j]==1){
			 			get(i,j);
			 			c[i][j]=1;
					 }
				 }
			 }
			 int h;
			 for(h=0;h<5;++h)
			 {
			 	if(b[4][h]==1)break;
			 }
			 if(h>=5)break;
		}
		int o=0;
		for(int i=0;i<5;++i)
		{
			for(int j=0;j<5;++j)
			{
				if(b[i][j]==1){
					o=1;
					break;
				}
			}
		}
		if(o==1){
			printf("NO\n");
			return 0;
		}
		for(int i=0;i<5;++i)
		{
			for(int j=0;j<5;++j)
			{
				if(c[i][j])ans+=k;
			}
		}
		
	}
	printf("YES\n");
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
