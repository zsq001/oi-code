#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef int int_;
#define int long long 
const int base=1e8;
struct Int{
	vector<int> val;
	Int(){
		val.clear();
		val.resize(1,0);
	}
	Int(char *str){
		int len=strlen(str);
		int ret=0,b=1;
		for(int i=len-1;i>=0;--i){
			ret+=(str[i]-'0')*b;
			b*=10;
			if((len-i)%8==0){
				val.push_back(ret);
				ret=0,b=1;
			}
		}
		val.push_back(ret);
		return ;
	}
	void clear(){
		while(!val.back() &&val.size()>1) val.pop_back();
	}
	int cmp(Int b){
		Int a=*this,c;
		int len1=a.val.size();
		int len2=b.val.size();
		if(len1<len2) return -1;
		if(len1>len2) return 1;
		for(int i=len1-1;i>=0;--i){
			if(a.val[i]<b.val[i])return -1;
			if(a.val[i]>b.val[i]) return 1;
		}
		return 0;
	}
	bool operator<(Int b){
		Int a=*this;
		return a.cmp(b)<0;
	}
	bool operator>(Int b){
		Int a=*this;
		return a.cmp(b)>0;
	}
	bool operator==(Int b){
		Int a=*this;
		return a.cmp(b)==0;
	}
	Int operator+(Int b){
		Int a=*this,c;
		int len1=a.val.size();
		int len2=b.val.size();
		int len3=max(len1,len2)+1;
		c.val.resize(len3,0);
		for(int i=0;i<len3;++i){
			if(i<len1) c.val[i]+=a.val[i];
			if(i<len2) c.val[i]+=b.val[i];
		}
		for(int i=0;i<len3-1;++i){
			c.val[i+1]+=c.val[i]/base;
			c.val[i]%=base;
		}
		c.clear();
		return c;
	}
	Int operator-(Int b){
		Int a=*this,c;
		bool flg=0;
		if(a<b){
			swap(a,b);
			flg=1;
		}
		int len1=a.val.size();
		int len2=b.val.size();
		int len3=len1;
		c.val.resize(len3,0);
		for(int i=0;i<len3;++i){
			c.val[i]=a.val[i]-(i<len2?b.val[i]:0);
		}
		for(int i=0;i<len3-1;++i){
			if(c.val[i]<0){
				c.val[i]+=base;
				c.val[i+1]--;
			}
		}
		c.clear();
		if(flg) c.val.back()=-c.val.back();
		return c;
	}
	Int operator*(Int b){
		Int a=*this,c;
		int len1=a.val.size();
		int len2=b.val.size();
		int len3=len1+len2;
		c.val.resize(len3,0);
		for(int i=0;i<len1;++i){
			for(int j=0;j<len2;++j){
				c.val[i+j]+=a.val[i]*b.val[j];
			}
		}
		for(int i=0;i<len3-1;++i){
			c.val[i+1]+=c.val[i]/base;
			c.val[i]%=base;
		}
		c.clear();
		return c;
	}
	Int operator/(Int qwq){
		int b=qwq.val[0];
		Int a=*this,c;
		int len=a.val.size();
		c.val.resize(len,0);
		for(int i=len-1;i>=1;--i){
			c.val[i]=a.val[i]/b;
			a.val[i-1]+=a.val[i]%b*base;
		}
		c.val[0]=a.val[0]/b;
		c.clear();
		return c;
	}
	void output(){
		int len=val.size();
		printf("%lld",val[len-1]);
		for(int i=len-2;i>=0;--i){
			printf("%08lld",val[i]);
		}
	}
};
char str1[100010],str2[100010];
int_ main(){
	scanf("%s%s",str1,str2);
	Int a(str1),b(str2),c;
	c=a*b;
	c.output();
	puts("");
	return 0;
}

