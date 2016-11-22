#include <iostream>
using namespace std;

int main()
{
	int * a;
	a = new int[10];
	for (int i = 0; i < 10; ++i) cout << a[i] << ' ';
	cout << endl;
	memset(a, 0, 10*4);
	for (int i = 0; i < 10; ++i) cout << a[i] << ' ';
	delete [] a;
	getchar();
	return 0;
}