#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
const double eps=1e-3;
double cal(double x1,double y1,double x2,double y2){return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));}
double ccal(double x1,double y1,double x2,double y2,double xs){return cal(x1,y1,x2,y2)/xs;}
double div2(double l,double r){return (l+r)/2.0;}
double solve(double x,double y)
{
	double lx=cx,ly=cy,rx=dx,ry=dy;
	double mx,my,mmx,mmy,ret1,ret2;
	while(fabs(rx-lx)>eps||fabs(ry-ly)>eps){
		mx=div2(lx,rx),my=div2(ly,ry);
		mmx=div2(mx,rx),mmy=div2(my,ry);
		ret1=ccal(ax,ay,x,y,p)+ccal(x,y,mx,my,r)+ccal(mx,my,dx,dy,q);
		ret2=ccal(ax,ay,x,y,p)+ccal(x,y,mmx,mmy,r)+ccal(mmx,mmy,dx,dy,q);
		if(ret1>ret2) lx=mx,ly=my;
		else rx=mmx,ry=mmy;
	}
	return ccal(ax,ay,x,y,p)+ccal(x,y,lx,ly,r)+ccal(lx,ly,dx,dy,q);
}
int main()
{
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
	double mx,my,mmx,mmy,Lx=ax,Ly=ay,Rx=bx,Ry=by;
	while(fabs(Rx-Lx)>eps||fabs(Ry-Ly)>eps){
		double mx=div2(Lx,Rx),my=div2(Ly,Ry);
		double mmx=div2(mx,Rx),mmy=div2(my,Ry);
		if(solve(mx,my)>solve(mmx,mmy)) Lx=mx,Ly=my;
		else Rx=mmx,Ry=mmy;
	}
	printf("%.2lf\n",solve(Lx,Ly));
	return 0;
}
