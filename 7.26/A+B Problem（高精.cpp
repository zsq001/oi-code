#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
char str1[1000010],str2[1000010];
typedef int int_;
int base=1e8;
#define int long long 
using namespace std;
struct Int{
    vector<int> val;
    Int()
    {
        val.clear();
        val.resize(1,0);
    }
    Int(char *str)
    {
        int len=strlen(str);
        int ret=0,b=1;
        for(int i=len-1;i>=0;i--)
        {
            ret+=(str[i]-'0')*b;
            b*=10;
            if((len-i)%8==0)
            {
                val.push_back(ret);
                ret=0,b=1;
            }
        }
        val.push_back(ret);
        return ;
    }
    void clear()
    {
        while(!val.back()&&val.size()>1)
        val.pop_back();
    }
    Int operator+(Int b)
    {
        Int a=*this,c;
        int len1=a.val.size();
        int len2=b.val.size();
        int len3=max(len1,len2)+1;
        c.val.resize(len3,0);
        for(int i=0;i<len3;i++)
        {
            if(i<len1)
            c.val[i]+=a.val[i];
            if(i<len2) 
            c.val[i]+=b.val[i];
        }
        for(int i=0;i<len3-1;i++)
        {
            c.val[i+1]+=c.val[i]/base;
            c.val[i]%=base;
        }
        c.clear();
        return c;
    }
    void output()
    {
        int len=val.size();
        cout<<val[len-1];
        for(int i=len-2;i>=0;i--)
        {
            printf("%08lld",val[i]);
        }
    }
};
int_ main()
{
    cin>>str1>>str2;
    Int a(str1),b(str2),c;
    c=a+b;
    c.output();
    //cout<<endl;
    return 0;
}
