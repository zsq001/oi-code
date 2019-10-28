#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double s,v1,v2,s1,s2,t1,t2,tar1,tar2,mid;
	cin>>s>>v1>>v2;
	s1=0,s2=s;
	do
	{
		mid=(s1+s2)/2.00;
		tar1=mid/v2;
		tar2=(mid-tar1*v1)/(v1+v2);
		t1=tar1+(s-mid)/v1;
		t2=tar1+tar2+(s-(tar1+tar2)*v1)/v2;
		if(t1<t2)
        	s2=mid;
        else
        	s1=mid;
	}while(abs(t1-t2)>1e-8);
	printf("%.6lf",t1);
	return 0;
}
