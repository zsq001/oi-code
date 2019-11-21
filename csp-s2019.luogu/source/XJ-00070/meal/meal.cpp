#include<cstdio>
#include<algorithm>
#include<cstring>
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
			ch=getchar();
		}
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

int n,m,tot=0,num=0,temp[2010][2010],mealn[2010][2010];
int usen[2010],usem[2010],a[110][2010];


struct orz{
	int lpc[110];
}l;
int ok(){
	foru(i,1,m){
		if(usem[i]>(num/2))return 0;
	}return 1;
	
}

void solve(int h,int weal)
{
	if(usen[h]==0)
	{
		
	    usen[h]=1;
	    
	    
	    foru(i,1,m)
	    {
	    	//lpc[h]=i;
	    	/*
	    	1 1 2 2     1
	    	1 1 2 3     1
	    	1 2 2 1     0
	    	1 2 2 3     0
	    	1 3 2 1     1
	    	1 3 2 2     1
			*/
			    num++;
			    usem[i]++;
			    if(ok()&&h<=n)
			    {
			    	tot+=weal*a[h][i];
			    	//printf("%d\n",)
			    }
			    else if(h<n)
			    {
			        solve(h+1,weal*a[h][i]);
			    }
			    num--;
			    usem[i]--;
			    mealn[h][i]=1;
		
	    }
	    
	    
	usen[h]=0;
    }
}

void solve2(int h)
{
	foru(i,h,n)
	foru(j,1,m)
	{
		if(usen[i]==0)
		{
			num++;
			usem[j]++;
		    if(usem[j]<=(num/2))
			{
		    	usen[i]=1;
				mealn[i][j]*=a[i][j];
		    	if(i==n)
		    	{
		    	    tot+=mealn[i][j];
		    	    mealn[i][j]/=a[i][j];
		    	}
		    }
		}
	}
	
}

void solve3(int h,int weal){
	if(usen[h]==0)
	{
	    usen[h]=1;
	    foru(i,1,m){
	    	if(a[h][i]==0)continue;
	    	num++;
	    	usem[i]++;
	    	if(ok())
	    	{
	    		tot+=weal*a[h][i];
	    		if(h<n)solve3(h+1,weal*a[h][i]);
	    	}
			else if(h<n)
	    	{
	    		solve3(h+1,weal*a[h][i]);
	    	}
	    	num--;
	    	usem[i]--;
	    }
	    usen[h]=0;
	}
}

void solve4()
{
	foru(i,1,n)
	foru(j,1,n)
	{
		tot+=a[i][j];
	}
}

int main(){
	freopen("meal.in","r",stdin);
	freopen("meal.out","w",stdout);
	memset(usen,0,sizeof(usen));
	memset(usem,0,sizeof(usem));
	n=read(),m=read();
	foru(i,1,n)
	foru(j,1,m)
	{
		a[i][j]=read();
	}
	/*
	foru(i,1,n)
	foru(j,1,m)
	mealn[i][j]=1;

	foru(i,1,n-1){
		if(a[i][1])
		solve(i,a[i][1]);
		printf("%d\n",tot);
	}

	foru(i,1,n-1){
		if(a[i][1])
		solve2(i);
		printf("%d\n",tot);
	}
	*/
	/*
	foru(i,1,n-1){
		if(a[i][1])
		solve3(i,a[i][1]);
		printf("%lld\n",tot);
	}
	*/
	foru(i,1,m)
	foru(j,1,m)
	tot+=a[1][j]*a[2][j];
	printf("%d",tot);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

		
