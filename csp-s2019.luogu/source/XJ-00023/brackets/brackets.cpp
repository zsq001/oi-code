#include<algorithm>
#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
stack<char> c;
int n, m[1086], js=1;
char s1[1086]; 
char s2[1086];

struct data{
	char c;
	int f;
	int num;
}a[1086];

struct stu{
	char s;
	int number;
	struct stu *left;
	struct stu *right;
};
typedef struct stu st;
st *head, *now, *p;

int cmp(struct data x, struct data y)
{
	if(x.f == y.f)
		return x.num < y.num;
	return x.f < y.f;
}

int find(int sta, int fi, st *k)
{
	if(k->number == fi)
		return 1;
	if(k == NULL)
		return 0;
	if(k->left != NULL && find(sta+1, fi, k->left) == 1)
	{
		s2[sta] = k->left->s;
		js++;
		return 1;
	}
	else if(k->right != NULL && find(sta+1, fi, k->right) == 1)
	{
		s2[sta] = k->right->s;
		js++;
		return 1;
	}
}

int main()
{
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s1);
	for(int i = 1; i <= n; i++)
		a[i].c = s1[i];
	for(int i = 1; i <= n; i++)
	{
		if(i == 1)
		{
			a[i].f = 0;
			a[i].num = i;
			continue;
		}
		scanf("%d", &a[i].f);
		a[i].num = i;
	}
	sort(a+1, a+1+n, cmp);
	for(int i = 1; i <= n; i++)
	{
		now = (st *)malloc(sizeof(st));
		now->left = NULL;
		now->right =  NULL;
		now->s = a[i].c;
		now->number = a[i].num;
		if(i == 1)
		{
			head = now;
			p = now;
			continue;
		}
		p = head;
		for(int j = 1; j <= a[i].f; j++)
		{
			if(p->number == a[i].f)
				break;
			if(p->left != NULL)
				p = p->left;
			else if(p->right != NULL)
				p = p->right;
		}
//			printf("%d &&&\n", i);
		if(p->left == NULL)
			p->left = now;
		else
			p->right = now;
	}
	p = head;
	
	for(int i = 1; i <= n; i++)
	{
		js = 1;
		memset(s1, '0', sizeof(s1));
		while(!c.empty())
			c.pop();
//			int q = 1;
		s2[1] = head->s;
		int q = find(2, i, head);
//		printf("%d:\n%d\n",i, q);
//		for(int j = 1; j <= js; j++)
//			printf("%c ", s2[j]);
//		printf("\n");
//
//		while(s2[q] != 2)
//			if(s2[q] == 1)
//			{
//				s1[q++] = p->s; 
//				p = p->left;
//			}
//			else 
//			{
//				s1[q++] = p->s;
//				p = p->right;
//			}
//		q--;
		int sum = 0, pd = 2;
		for(int j = 1; j <= js; j++)
		{
			for(int k = j+1; k <= js; k++)
			{
				int ans = 0;
				for(int v = j; v <= k; v++)
					c.push(s2[v]);
				for(int v = j; v <= k; v++)
				{
					char x = c.top();
					if(x == ')')
						ans++;
					else if(x == '(')
						ans--;
					if(ans < 0)
					{
						pd = 0;
						break;
					}
				}	
				if(ans == 0)
					pd = 1;
			}
			if(pd == 1)
				sum++;
			pd = 0;
		}
		m[i] = sum;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = ans + (i^m[i]);
	printf("%d", ans);
	
	return 0;
}
/*
5
(()()
1 1 2 2
*/
