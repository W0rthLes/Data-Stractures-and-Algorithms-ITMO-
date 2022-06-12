﻿#include <iostream>
using namespace std;

const int mem = 100100;
int pre_ans[mem];

struct node
{
	int l, r;
	int num;

} pairs[mem];


int cnt = 0;
int k = 1;

int main()
{
	int ans[mem];
	int n;
	cin >> n; // количество пар

	int l_input, r_input; //инициализируем фактическую левую и правую границы

	int min_left_border = mem, max_right_border = -1; //механизм поиска минимальной левой и максимальной правой границ обычный. для минимума - число побольше, для максимума - поменьше, чтобы были адекватные сравнения.

	for (int i = 1; i <= n; i++) //от 1 до числа пар
	{
		scanf_s("%d%d", &l_input, &r_input);
		//cin >> l_input;
		//cin >> r_input;
		//задаем левую правую границу
		

		if (l_input < min_left_border) 
		{
			min_left_border = l_input; //эти условия ищут нам самую маленькую левую границу и самую большую правую
			//нужно чтобы проверять будет ли точко внутри хоть чего то или нет
		}

		if (r_input > max_right_border) 
		{
			max_right_border = r_input; 
		}

		pairs[i].l = l_input;
		pairs[i].r = r_input; //заполняем структуру левоправыми границами
		pairs[i].num = i; //и номер пары
	}

	int point, q[mem];
	int m; //количество точек
	cin >> m;
	
		
	for (int i = 1; i <= m; i++) //от 1 до количества точек
	{
		scanf_s("%d", &point);
		//cin >> point;
		q[i] = point; // зполняем массив q значениями точек
	}
	
	for (int i = 1; i <= m; i++) // заново пробегаемся по всем точкам
	{
		if (q[i] < min_left_border || q[i] > max_right_border) //если точка левее самой левой границы или правее самой правой границы она не имеет решения
		{
			ans[i] = -1; //добавляем к ответу -1
			continue;//выходим из круговой поруки
		}
		//дальше идет поиск ответа для всех точек для которых ответ есть
		
		while (q[i] >= pairs[k].l) //пока поданная точка >= левой границе
		{
			pre_ans[++cnt] = k; //находим номер левой границы которая правее всего
			k++; //по сути ищем отрезок который нас удовлетворяет но с минимальной длинной
			if (k > n) //если номер подходящей левой границы оказывается последним вылетаем из поиска
				break;
		}

		while (q[i] > pairs[pre_ans[cnt]].r) //сейчас в cnt хранится номер левой границы которая находится максимально справа и устраивает нашу точку
			//до тех пор пока нашей точке не подходит и левая и правая граница (они поставлены в соответствии это не просто случайный отрезок)
		{ //мы отползаем назад и ищем чето подходящее, и первое что подойдет - лучший вариант.
			cnt--;
			if (cnt < 1)
				break;
		}
		
		ans[i] = pairs[pre_ans[cnt]].num; //вывод номера пары в ответ
	}

	for (int i = 1; i <= m; i++)
	{
		printf("%d\n", ans[i]);
		//cout << ans[i] << endl;
	}
		
    return 0;
}
