#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
template<class T>void read(T &x)
{
	int f=0;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x;
	return;
}
int a[1001][1001];
int n,m;
int q;
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n);
	read(m);
	read(q);
	int x,y,z;
	for(int i=1;i<=q;++i)
	{
		read(x);
		read(y);
		read(z);
		if(x==1){
			for(int i=1;i<=m;++i)
			{
				a[y][i]=z;
			}
		}
		else if(x==2){
			for(int i=1;i<=n;++i)
			{
				a[i][y]=z;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
	  	 printf("%d ",a[i][j]);
	  	printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	 
}
