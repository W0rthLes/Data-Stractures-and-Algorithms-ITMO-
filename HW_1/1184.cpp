#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double num; // размер массива
	double len; //длина каждого провода
	int k; // требуемое количество
	cin >> num;
	cin >> k;
	double sum = 0; //сумма длин всех отрезков
	double* cabel = new double[num]; // Выделение памяти для массива
	for (int i = 0; i < num; i++)
	{
		// Заполнение массива 
		cin >> len;
		cabel[i] = len;
		sum = sum + cabel[i];
	}
	sum = sum / k; //грубое приближение средней длины кабеля на k отрезков

	double l = 0;
	double r = sum;
	while (r - l > 1e-9)
	{
		double mid = (l + r) / 2;
		//cout << "mid - " << mid << endl;
		int search= 0;
		for (int i = 0; i < num; i++)
		{
			search = search + (int)(cabel[i] / mid); //https://prog-cpp.ru/search-binary/
			//cout << "search - " << search << endl;
		}
			
		if (search >= k)
			l = mid;
		else
			r = mid;
		
	}
	//cout << fixed;
	//cout.precision(2); /вариантов вывода много, но подходит только сишный
	//cout << floor(r) << endl;
	//cout <<  fixed << setprecision(2) << floor(r) << endl;
	printf("%.2lf", (double)floor(r));
	delete[] cabel;
	return 0;
}