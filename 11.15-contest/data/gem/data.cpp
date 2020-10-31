#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<time.h>
#define L long long
using namespace std;
int n,m;
int main()
{
	srand(time(0));
	freopen("gem10.in","w",stdout);
	int i,j,k,l;
	n=m=200000;
	printf("%d %d\n",n,m);
	for(i=1;i<=n;i++)
	  printf("%d ",((rand()<<15)+rand())%1000000000+1);
	printf("\n");
	while(m--)
	  {
	   if(rand()&1)
	     {
		  i=((rand()<<15)+rand())%n+1;
		  j=((rand()<<15)+rand())%n+1;
		  if(i>j)
		    swap(i,j);
	      printf("1 %d %d\n",i,j);
		 }
	   else
	     {
		  if(abs(m-n/2)>5)
		  do
		  {
		  i=((rand()<<15)+rand())%n+1;
		  j=i+((rand()<<15)+rand())%1000;
		  }
		  while(j>n);
		  else	
		  {
		  i=((rand()<<15)+rand())%n+1;
		  j=((rand()<<15)+rand())%n+1;
		  if(i>j)
		    swap(i,j);
		  }
		  printf("2 %d %d %d %d\n",i,j,((rand()<<15)+rand())%1000000000+1,((rand()<<15)+rand())%20001-10000);
		 }
	  }
	return 0;
}

