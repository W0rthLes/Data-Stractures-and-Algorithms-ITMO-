//#include <iostream>
//#include <vector>
//#include <set>
//#include <stack>
//using namespace std;
//const int MAXN = 101;
//int n; // число вершин
//int g[MAXN][MAXN]; // граф
//bool used[MAXN];
//stack<int> ans;
//
//void dfs(int v) {
//	used[v] = true;
//	for (int i = 0; i < g[v][0]; i++) {
//		int to = g[v][i];
//		if (!used[to])
//			dfs(to);
//	}
//	ans.push(v);
//}
//
//void topological_sort() {
//	for (int i = 0; i < n; ++i)
//		used[i] = false;
//	//ans.clear();
//	for (int i = 0; i < n; ++i)
//		if (!used[i])
//			dfs(i);
//	//reverse(ans.begin(), ans.end());
//}
//int main()
//{
//	cin >> n;
//	int p;
//	memset(g, 0, sizeof(g));
//	//for (int i = 0; i < n; ++i)
//		//g[i][0] = 0;
//	for (int i = 0; i < n; i++)
//	{
//		
//		while (scanf_s("%d", &p) && p)
//		{
//			g[i][++g[i][0]] = p;
//			
//		}
//	}
//	topological_sort();
//
//	cout << ans.size() << "<-------------------" << endl;
//
//	while (!ans.empty())
//	{
//		printf("%d ", ans.top());
//		ans.pop();
//	}
//	printf("/n");
//	return 0;
//}


#include <vector>
#include <iostream>
using namespace std;
vector <int> ans;
int graph[101][101];
int n;
bool used[101];

void dfs(int v)
{
	used[v] = true;

	for (int i = 1; i <= graph[v][0]; i++)
	{
		int to = graph[v][i];
		if (!used[to])
			dfs(to);
	}

	ans.push_back(v);
}

void topological_sort()
{
	
	for (int i = 1; i <= n; i++)
		used[i] = false;
	
	for (int i = 1; i <= n; i++) {
		if (!used[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
}



int main()
{
	int kids;

	cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		graph[i][0] = 0;
	}

	for (int i = 1; i <= n; i++) 
	{
		while ((cin >> kids) && kids)
		{
			graph[i][++graph[i][0]] = kids;
		}
			
	}

	topological_sort();
	

	for (int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}


