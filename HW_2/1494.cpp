#include<iostream>

#include<stack>
using namespace std;

int balls[100005];

int main()
{
	stack <int> check;
	int n;
	cin >> n; //количество шаров
	int ptr = 0;
	for (int i = 0; i < n; i++) //загружаем номера шаров в том порядке в котором ревизор забирал их из лузы
	{
		cin >> balls[i];
	}

	for (int i = 1; i <= n; i++)
	{
		check.push(i); 
		while (!check.empty() && check.top() == balls[ptr]) //с какого бы момента мы не начали смотреть, если последовательность верная, мы вернемся по ней и очистим весь стек.
		{
			check.pop();
			ptr++;
		}
	}
	if (check.empty())
	{
		cout << "Not a proof";
	}
	else cout << "Cheater";
}