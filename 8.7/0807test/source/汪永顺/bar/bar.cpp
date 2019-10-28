#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;

int dx[5] = {0, 1, -1, 0, 0}, dy[5] = {0, 0, 0, -1, 1};
int mapp[1005][1005], n, flag, vis[1005][1005];

struct node{
	int x, y;
}stp[2020];

void dfs(int nx, int ny, int step)
{
	vis[nx][ny] = 1;
	if((nx == n && ny == n) || flag == 1)
	{
		flag = 1;
		return ;
	}
	for(int i = 1; i <= 4; i++)
	{
		int xx = nx + dx[i];
		int yy = ny + dy[i];
		if(vis[xx][yy] == 0 && mapp[xx][yy] != -1 && ((xx != stp[step].x || yy != stp[step].y) || xx == n && yy == n) && xx <= n && xx >= 1 && yy <= n && yy >= 1)
		{
			mapp[stp[step].x][stp[step].y] = -1;
			dfs(xx, yy, step + 1);
			mapp[stp[step].x][stp[step].y] = 0;
		}
	}
	vis[nx][ny] = 0;
	return ;
}

int main() {
	freopen("bar.in", "r", stdin);
	freopen("bar.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		flag = 0;
		memset(mapp, 0, sizeof(mapp));
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n - 2; i++)
			scanf("%d%d", &stp[i].x, &stp[i].y);
		dfs(1, 1, 1);
		if(flag == 1)
			printf("Yes\n");
		else if(flag == 0)
			printf("No\n");
	}
}
