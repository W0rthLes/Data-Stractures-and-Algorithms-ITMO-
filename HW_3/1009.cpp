#include <iostream>
using namespace std;

//пусть F - функция для получения количества валидных n-значных чисел, тогда
//мы можем добавить k-1 цифр (отметаем 0) перед каждым из n-1 нормальных чисел которые нам подходят.
//но есть еще 2 вариант: добавить 0 перед n-2 значным допустмым числом, а потом еще k-1 цифры (опять все кроме 0)
//тогда F (n) = (k-1) * F (n-1) + (k-1) * F (n-2)
int main() {
	int n, k;
	int arr[20];
	cin >> n;
	cin >> k;

	arr[0] = 1;
	arr[1] = k - 1;

	for (int i = 2; i <= n; i++) 
	{
		arr[i] = (k - 1) * (arr[i - 1] + arr[i - 2]);
	}

	cout << arr[n];
	
	return 0;
}