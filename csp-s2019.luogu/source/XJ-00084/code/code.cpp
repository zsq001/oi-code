#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#define LL long long

using namespace std; 

LL int n;
LL int m;
struct Grece
{
	LL int num[23]={0};
};

struct Grece a[1350000];
LL int simple[2]={0,1};
LL int flag;
LL int geshu=2;
LL int j=0;

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	
	cin >> n >> m; // 读入位数与要求的个数
	
	for(LL int i=1;i<=n-1;i++)
	{
		geshu=geshu*2;
	} //个数是位数的2^n个 
	

	for(int j=0;j<2;j++)
	{
		a[j].num[0]=simple[j];
	} // 填第一位 
	
	LL int i=2;
	LL int nx=1;
	
	while(nx<n) 
	{
		LL int x=0;
		//提前填好第一位，此时n=1
		
		LL int j=(i*2)-1; // 前面的拷到后面，这个变量跑要填的,也就是后面的 
		LL int k=0;       // 这个变量跑前面的 	
		
		while(1) 
		{			
			if(j<k) // 如果当前位已全部复制，j回尾部，k回头部，位数x++; 
			{			
				x++;
				k=0;				
				j=(i*2)-1;		
			}
			
			if(x>n) // 如果当前全部复制完成，break; 
			{
				break;
			}

			a[j].num[x]=a[k].num[x];; // 复制 	
			
			k++; // 前面的往后移 
			j--; // 后面的往前移 	
		}
		
		for(int j=0;j<i;j++) //前面一半加前导0 
		{
			a[j].num[nx]=0;
		}
		
		for(int j=(i*2)-1;j>=i;j--) //后面一半加前导1 
		{
			a[j].num[nx]=1;
		} 
		
		i=i*2; // 个数乘2，准备填下一位
		nx++;// 当前位数++
	}
	
//	for(LL int i=0;i<geshu;i++) // 测试用输出 
//	{
//		for(LL int j=0;j<n;j++)
//		{
//			cout << a[i].num[j];
//		}
//		cout << endl;
//	}
	
	for(LL int j=n-1;j>=0;j--) // ans输出 逆序 
	{
		cout << a[m].num[j];
	}
	
	return 0;
}


