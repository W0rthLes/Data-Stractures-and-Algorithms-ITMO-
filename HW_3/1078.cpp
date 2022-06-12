#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[500] = { 0 };
int half_ans[500] = { 0 };

struct Segments //структура отрезков, левая правая граница + id
{
	int l, r;
	int id;
} otrezki[500];

bool cmp(Segments otr1, Segments otr2) //сортирует по увеличению длины отрезка
{
	if (otr1.l == otr2.l) return otr2.r < otr2.r;
	return otr1.l > otr2.l;
}


int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> otrezki[i].l >> otrezki[i].r;
		otrezki[i].id = i;
	} 
	sort(otrezki + 1, otrezki + n + 1, cmp);
	
	dp[1] = 1; 
	half_ans[1] = 1;
	
	int max = 1, index = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1; 
		half_ans[i] = i;
		
		for (int j = i - 1; j >= 1; j--)
		{
			
			if (((otrezki[i].l < otrezki[j].l) && (otrezki[i].r > otrezki[j].r)) && dp[i] < dp[j] + 1) //проверяем входит ли следующих отрезок в предыдущий (i всегда больше j, которое в свою очередь меняется от i-1 до 1)
			{ 
				//вместо функции перехода dp[i] = max(dp[i], dp[j])+1 пользуемся ее альтернативой через знаки > <
				dp[i] = dp[j] + 1; 
				half_ans[i] = j; //запоминает номер отрезка в порядке увеличения длины (нужно для ответа)
			}
		}
		
		if (dp[i] > max)
		{
			max = dp[i];
			index = i;
		}
	}
	
	
	
	vector <int> ans;
	

	for (int i = 0; i < max; i++)
	{
		ans.push_back(otrezki[index].id);
		index = half_ans[index];
	}
	cout << ans.size() << endl;
	for (int i = max-1; i >=0; i--)
	{
		cout << ans[i] << " ";
	}
	

	return 0;
}