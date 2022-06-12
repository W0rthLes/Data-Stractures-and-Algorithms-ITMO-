#include <iostream>
#include<algorithm>
using namespace std;

int answer[100000];//массив куда будем помещать ответ
pair<int, int> pairs[100000]; //пары (левая координата; правая координата)

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second != b.second) return a.second < b.second; //хитрая сортировка учитывающая случай если координаты одинаковые
	return a.first > b.first;
}

int main()
{
	int m; //первое число m
	int amount = 0; //считалка количества пар
	 
	
	cin >> m;
	
	int l, r;
	while (1)
	{
		cin >> l;
		cin >> r;
		
		if (l == 0 && r == 0) break;

		if (r <= 0 || l >= m) continue; //проверяем подходит ли отрезок, отбирая те случаи когда отрезки левее 0
		pairs[amount++] = pair<int, int>(l, r);//создаем пару номер(какая то) с координатами (l, r)
	}

	sort(pairs, pairs + amount, cmp);

	int temp = 0;
	int cnt = 0;
	for (int i = 0; i < amount; i++)//пробег по всем парам
	{
		for (int j = i; j < amount; j++) //конструкция нужна чтобы установить на i номер пары у которой первая координата 0, затем проверка для новой левой границы 
		{
			if (pairs[j].first <= temp)i = j;
	
		}

		if (pairs[i].first > temp) break; //если такой пары не нашлось, то соответственно вылетаем, а затем она нужна чтобы при смещении левой границы сравнивать

		answer[cnt++] = i; //сюда записываем номер подошедших пар

		temp = pairs[i].second; // смещаем границу

		if (temp >= m) break; //нашли решение
	}
	if (temp < m) cout << "No solution"; //не нашли решение по имеющимся отрезкам
		
	
	else 
	{
		cout << cnt << endl;
		 
		for (int i = 0; i < cnt; i++)
		{
			cout << pairs[answer[i]].first << " " << pairs[answer[i]].second << endl;
		}
	}
	return 0;
}
