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
int n;
int minn=2147483647;
int main()
{
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	read(n);
	for(int i=1;i<=n;++i)
	{
		if(n%i==0){
			for(int j=1;j<=n;++j)
			{
				if(n%j==0){
					for(int z=1;z<=n;++z)
					{
						if(i*j*z==n){
							if(2*i*j+2*i*z+2*j*z<minn)minn=2*i*j+2*i*z+2*j*z;
						}
					}
				}
			}
		}	
	}
	printf("%d\n",minn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
