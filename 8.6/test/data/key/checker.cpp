#include <bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
FILE* fin;//标准输入
FILE* fout;//用户输出
FILE* fstd;//标准输出
FILE* fscore;//得分文件
FILE* freport;//报告文件

int a[N];

void quit(int x)
{
	fprintf(fscore,"%d",x);
	fclose(fin);
	fclose(fout);
	fclose(fstd);
	fclose(fscore);
	fclose(freport);
	exit(0);
}

char num[N];

int main(int argc,char**argv)
{
	fin=fopen(argv[1],"r");//标准输入
	fout=fopen(argv[2],"r");//用户输出
	fstd=fopen(argv[3],"r");//标准输出
	fscore=fopen(argv[5],"w");//得分文件
	freport=fopen(argv[6],"w");//报告文件
	
	fscanf(fin,"%s",num+1);
	int n = strlen(num+1) / 3, m;
	for(int i = 1; i <= 3*n; ++ i) num[i] -= '0';
	fscanf(fout,"%d", &m);
	if(m > n) {
		fprintf(freport,"m > n");
		quit(0);
	}
	for(int i=1;i<=m;i++)
	{
		if(fscanf(fout,"%d",&a[i])==EOF)
		{
			fprintf(freport,"output is less than m");
			quit(0);
		}
		if(a[i] >= 3*n) {
			fprintf(freport,"a_i >= 3n");
			quit(0);
		}
		num[a[i]] =  1 - num[a[i]];
		num[a[i]+1] = 1 - num[a[i]+1];
	}

	int ans = 1;
	for(int i = 2; i <= 3*n; ++ i) if(num[i] != num[i-1]) ans ++;
	if(ans >= 2*n) { 
		fprintf(freport,"accepted");
		quit(2);
	}
	else  {
		fprintf(freport,"wrong answer");
		quit(0);
	}
	return 0;
}
