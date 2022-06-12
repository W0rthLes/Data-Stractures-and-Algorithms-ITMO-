#include<stdio.h>
#include <iostream>
using namespace std;
const int maxn = 1000000;
int i, k, n;

int start[maxn], to_which[maxn], pre[maxn], worth[maxn], leng[maxn], depth[maxn], fore[maxn][40];

inline void add(int x, int y, int z) 
{
	pre[++n] = start[x]; 
	start[x] = n; 
	to_which[n] = y; 
	worth[n] = z;
}

void dfs(int x, int last) 
{
	depth[x] = depth[last] + 1;
	fore[x][0] = last;

	for (int i = 1; i <= 30; i++)
		fore[x][i] = fore[fore[x][i - 1]][i - 1];

	for (int i = start[x]; i; i = pre[i]) 
	{
		int y = to_which[i];
		if (y == last)
			continue;
		leng[y] = leng[x] + worth[i];
		dfs(y, x);
	}
}
int lca(int a, int b) 
{
	if (depth[a] < depth[b]) 
	{
		a += b; 
		b = a - b; 
		a -= b;
	}

	for (int i = 30; i >= 0; i--)
		if (depth[fore[a][i]] >= depth[b])
			a = fore[a][i];

	if (a == b)
		return a;

	for (int i = 30; i >= 0; i--)
		if (fore[a][i] != fore[b][i])
			a = fore[a][i], b = fore[b][i];

	return fore[a][0];
}
int main() 
{
	int n;
	cin >> n;
	
	for (i = 1; i < n; i++) 
	{
		int x, y, z;
		cin >> x;
		cin >> y;
		cin >> z;
		
		add(x, y, z), add(y, x, z);
	}
	dfs(k, 0);

	int m;
	cin >> m;
	
	for (i = 1; i <= m; i++) 
	{
		int a, b, c;
		cin >> a;
		cin >> b;
		
		c = lca(a, b);
		cout << leng[a] + leng[b] - leng[c] * 2 << endl;
		
	}
	return 0;
}