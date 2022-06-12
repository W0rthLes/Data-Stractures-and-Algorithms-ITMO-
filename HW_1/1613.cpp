#include <iostream>

using namespace std;
int main()
{
	int num, val; // количество пассажиров
	cin >> num;
	int* a = new int[num];
	for (int i = 0; i < num; i++)
	{
		//cin >> val;
		scanf_s("%d", &a[i]); //используем сишный стиль ввода потмоу что потоковый как оказалось сильно медленнее
	}

	int q;
	cin >> q; //количество проверок
	
	int** matrix;
	matrix = new int* [q]; //q строк
	
	for (int i = 0; i < q; i++)
		matrix[i] = new int[3]; // 3 столбца всегда

	for (int i = 0; i < q; i++) // ввод 
		for (int j = 0; j < 3; j++)
		{
			scanf_s("%d", &matrix[i][j]);
		}

	int k, i;
	for (k = 0; k < q; k++) { //от 0 до количество проверок 

		int count = 0; //флаг для ввода 1 или 0

		for (i = matrix[k][0]; i <= matrix[k][1]; i++) //фиксируемся в i на левой границе города и увеличиваем ее до тех пор пока она не станет равна правой границе городов
		{
			
			if (matrix[k][2] == a[i - 1]) { // 
				count++;
				break;
			}
		}

		if (count != 0)

		{
			printf("1");
		}

		else

		{
			printf("0");
		} 
	}
	
	delete[] a;
	for (i = 0; i < 3; i++)
	{
		delete[] matrix[i];

	}
	
	return 0;
}

