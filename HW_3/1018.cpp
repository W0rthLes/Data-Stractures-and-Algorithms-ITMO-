#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;
vector <pair<int, int>> bin_tree[110];
int top_of_tree[110];
int ans[110][110];

//ans(i, j) представляет собой поддерево i, сохраняя максимальный вес j узлов.
//Вес каждого ребра рассматривается как вес дочернего узла двух связанных узлов.
//Затем группируем рюкзаки на всех поддеревьях i, то есть каждое поддерево может выбрать 1, 2, ... j - 1 ребра для присвоения.


int dfs(int point1, int father) 
{
	top_of_tree[point1] = 1; //

	
	for (int i = 0; i < bin_tree[point1].size(); i++) //left side
	{
		int point2 = bin_tree[point1][i].first;
		
		if (point2 == father) continue;
		top_of_tree[point1] = top_of_tree[point1] + dfs(point2, point1);
	}

	for (int i = 0; i < bin_tree[point1].size(); i++) //right side
	{
		int point2 = bin_tree[point1][i].first;
		int apples = bin_tree[point1][i].second;

		if (point2 == father) continue;
		
		for (int i = top_of_tree[point1]; i > 0; i--)
		{
			for (int j = 1; j < i; j++)
			{	
				ans[point1][i] = max(ans[point1][i], ans[point1][i - j] + ans[point2][j] + apples);				
			}
		}
	}
	return top_of_tree[point1];
}


int main() 
{
	cin >> n >> q;
	
	for (int i = 0; i <= n; i++) bin_tree[i].clear(); //init
	for (int i = 0; i < n - 1; i++)
	{
		int point1, point2, apples;
		cin >> point1 >> point2 >> apples;
		
		bin_tree[point1].push_back(make_pair(point2, apples));
		bin_tree[point2].push_back(make_pair(point1, apples));
		
		memset(ans, 0, sizeof(ans));
		dfs(1, -1);
	}
	cout << ans[1][q + 1]; //q граней дают q+1 вершин
	return 0;
	
	
	
}
