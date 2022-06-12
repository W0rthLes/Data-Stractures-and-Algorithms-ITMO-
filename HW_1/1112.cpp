#include <iostream>
#include <vector>

using namespace std;


int main() {
	int num; // размер массива
	int a, b;
	cin >> num; // получение от пользователя размера массива

	int* left = new int[num]; // Выделение памяти для массива
	int* right = new int[num];
	vector <int> res;
	

	for (int i = 0; i < num; i++) {
		// Заполнение массива 
		cin >> a;
		cin >> b;
		if (a > b) { //отбираем варианты где левая граница почему то справа от правой, просто меняем местами
			left[i] = b;
			right[i] = a;
		}
		else {
			left[i] = a;
			right[i] = b;
		}		
		
	}
	int с;
	for (int i = 0; i < num - 1; i++) //сортировка по правой границе
	{
		for(int j = i + 1; j < num; j++)
		{
			if(right[i] > right[j]) 
			{
				с = left[i];
				left[i] = left[j];
				left[j] = с;
				с = right[i];
				right[i] = right[j];
				right[j] = с;
			}
		}
	}
	
	res.push_back(left[0]); //в результат всегда суем первые 2 координаты, они будут всегда если есть решение
	res.push_back(right[0]);
	
	int m = 0;
	for (int i = 1; i < num; i++)
	{
		if (left[i] >= right[m]) 
		{
			res.push_back(left[i]); //очередные координаты добавляем только если левая граница
			res.push_back(right[i]); //больше правой границы уже добавленных отрезков 
			//правая же будет максимальной потому что двигаемся слева направо
			
			m = i;
			
		}
	}
	printf("%d \n", res.size() / 2);//вкидывам количество пар, так как координаты 2 на 1 пару то делим на 2
	for (int i = 0; i < res.size(); i++) {

		if (i % 2 == 0 && i > 0) { //форматирование, чтобы скипнуть 0 и на каждую четную цифру отсекать пару
			printf("\n");
		}
		printf("%d ", res[i]);		
	}
	delete[] left; 
	delete[] right;
	
	return 0;
}

