#include <iostream>
 
using namespace std;
 
int check[2011][2011];
int main()
{
	int a = 1, b = 1, c;
	long long n;
	/*int i = 1;
	for (c = (a + b) % 2010;; i++)
	{
		if (check[a][b])
		{
			cout << i - check[a][b] << endl;
			system("pause");
			return 0;
		}
		else
			check[a][b] = i;
		a = b;
		b = c;
		c = (a + b) % 2010;
	}*/
	cin >> n;
	n %= 2040;
	for (int i = 2; i < n; i++)
	{
		c = (a + b) % 2010;
		a = b;
		b = c;
	}
	cout << c << endl;
	return  0;
}