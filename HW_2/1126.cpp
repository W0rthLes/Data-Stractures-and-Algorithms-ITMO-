#include<iostream>
#include<vector>
using namespace std;


int main()
{
	vector<int> que;
	int m;
	cin >> m;
	int val;
	int i = 0;

	while (1)
	{
		cin >> val;
		if (val == -1) break;
		i++;
		que.push_back(val);
	}

	int k = 0;
	int max = 0;
	while (k + m <= i)
	{
		max = que[k];
		for (int i = k; i < k+m; ++i) 
		{
			if (que[i] > max)
			{
				max = que[i];
			}
			
		}
		
		cout <<  max << endl;
		k++;
	}
}