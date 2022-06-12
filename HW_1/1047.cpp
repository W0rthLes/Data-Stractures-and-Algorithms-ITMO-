//вывод формулы, которая использовалась в задаче
//возьмем a[i] из условия но только не i, а i-1, тогда a[i-1] = ((a[i-2] + a[i]) / 2) - c[i-1], раскроем скобки
//	 a[i-1] = (a[i-2]/2) + (a[i]/2) - c[i-1], перегруппируем
//	(-a[i]/2) = a[i-2]/2 - a[i-1] - c[i-1] /разделим всё на -2
//	 a[i] = 2a[i-1] - a[i-2] + 2c[i-1] - получилась новая формула a[i] полученная из формулы условия.
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main() {

	int i, n;
	double a[5000], c[5000];

	double d;

	cin >> n; //число N 
	

	cin >> d;
	a[0] = d; //вврдим a[0]

	cin >> d;
	a[n + 1] = d; //вводим a[n+1]

	for (i = 1; i <= n; i++) 
	{ 
		cin >> d; //вводим массив состоящий из c
		c[i] = d;
	}
	double l = -2000;
	double r = 2000;
	while (1) {

		a[1] = double((l + r) / 2.0); //aka mid

		for (i = 2; i <= n; i++)
		{
			a[i] = 2 * a[i - 1] - a[i - 2] + 2 * c[i - 1]; //вычисляем каждый элемент от a[2] до a[n], необходима вся последовательность для бинпоиска
		}
			
		d = 2*a[n] +2*c[n] - a[n-1];//это a[n+1] которое дано в условии, но полученное из выведенной формулы сверху
		//это ползволяет использовать нам данное по условию значение d и вычисленное нами d как критерий оценки точности

		if (fabs(a[n + 1] - d) < 0.00001)
		{
			cout << fixed;
			cout.precision(2);
			cout << a[1] << endl;
			//printf("%.2lf", a[1]); //if our sequence is correct we can take elemnts from it
			return 0;
		}

		else if (d - a[n + 1] > 0.00001)r = a[1]; //стандартный бин поиск, меняем левую или правую границу

		else l = a[1];
	}
	cout << fixed;
	cout.precision(2);
	cout << l << endl;

	//printf("%.2lf", l);
	
}