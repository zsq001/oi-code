#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long

int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}


struct k{
	int x,y;
	friend bool operator < (k a,k b){
		int g=gcd(a.x,b.x);
		return (a.y*(b.x/g)) < (b.y*(a.x/g));
	}
	friend bool operator >= (k a,k b){
		int g=gcd(a.x,b.x);
//		printf("%d %d %d %d %d\n",a.x,b.x,g,(a.y * (b.x/g)),(b.y * (a.x/g)));
		return (a.y * (b.x/g)) >= (b.y * (a.x/g));
	}
};

struct node{
	int n;
	k h;
};
vector<node> v;
vector<node> qaq;
node last[200050];
int n,m,x,y,tot[200050];

void add(node temp){
	while(v.size()){
		node tp=v.back();
		if(tp.n >= temp.n && tp.h < temp.h) v.pop_back();
		else if(tp.h < temp.h){
			qaq.push_back(v.back());
			v.pop_back();
		}
		else break;
	}
    if(v.size() == 0){
    	v.push_back(temp);
	}
	else{
		node tp=v.back();
     	if(tp.n <= temp.n && tp.h >= temp.h);
    	else v.push_back(temp);
    }
	while(qaq.size()){
		v.push_back(qaq.back());
		qaq.pop_back();
	}
	return;
}




int_ main()
{
	freopen("building.in","r",stdin);
	freoepn("building.out","w",stdout);	
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);        
		node temp;
	    temp.h.x=x;
	    temp.h.y=y;
	    temp.n=x;
	    add(temp);
	    printf("%d\n",v.size());
	}
	return 0;
}
