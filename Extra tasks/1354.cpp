#include <iostream>
#include <cstring>
using namespace std;

bool if_palindrom(string s1)
{
	int len = s1.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (s1[i] != s1[len - i - 1])
		{
			return false;
		}
	}
	return true;
}


string s1;
string s2;
string tmp;
int main()
{
	cin >> s1;
	int len = s1.length();
	if (len == 1)
	{
		cout << s1 + s1;
	}
		
	else 
	{
		for (int i = 0; i < len - 1; i++)
		{
			s2 = s2 + s1[i];
			tmp = s2;
			reverse(tmp.begin(), tmp.end());

			if (if_palindrom(s1 + tmp))
			{
				cout << s1 + tmp << endl;
				break;
			}

			tmp.clear();
		}
	}
	
}

