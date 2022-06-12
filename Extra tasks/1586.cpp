
#include <iostream>
using namespace std;

int tmp;

const int base = pow(10, 9) + 9;

bool check_table[1000];

long int i, dig1, dig2, dig3;
long int dp[10001][10][10];

bool check(long int x)
{
	tmp = 2;
	bool check = true;
	while (tmp * tmp <= x)
	{
		if (x % tmp == 0)
		{
			check = false;
		}
		tmp = tmp + 1;
	}
	return check;
}

int main()
{
	long int n;
	cin >> n;

	for (i = 100; i <= 999; i++)
	{
		check_table[i] = check(i);
	}

	for (dig1 = 0; dig1 <= 9; dig1++)
	{
		for (dig2 = 0; dig2 <= 9; dig2++)
		{
			for (dig3 = 0; dig3 <= 9; dig3++)
			{
				if (check_table[dig1 * 100 + dig2 * 10 + dig3])
				{
					dp[3][dig3][dig2] = dp[3][dig3][dig2] + 1;
				}
			}
		}
	}

	for (i = 4; i <= n; i++)
	{
		for (dig1 = 0; dig1 <= 9; dig1++)
		{
			for (dig2 = 0; dig2 <= 9; dig2++)
			{
				for (dig3 = 0; dig3 <= 9; dig3++)
				{
					if (check_table[dig1 * 100 + dig2 * 10 + dig3])
					{
						dp[i][dig3][dig2] = (dp[i][dig3][dig2] + dp[i - 1][dig2][dig1]) % base;
					}
				}
			}
		}
	}

	long int ans = 0;
	for (dig1 = 0; dig1 <= 9; dig1++)
	{
		for (dig2 = 0; dig2 <= 9; dig2++)
		{
			ans = (ans + dp[n][dig1][dig2]) % base;
		}

	}

	cout << ans;
}

