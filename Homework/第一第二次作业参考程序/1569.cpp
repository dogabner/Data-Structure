#include <iostream>
#include <cstdio>
 
#define lowbit(X) (X & -X)
using namespace std;
 
int n, T[10005];
 
void inc(int x, int y);
int sum(int x);
void que(int x, int y);
int main()
{
	int x, y;
	char s[10];
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		inc(i, x);
	}
 
	while (cin >> s)
	{
		if (s[0] == 'e')
			break;
		cin >> x >> y;
		switch (s[0]){
		case 'i' : 
			inc(x, y);
			break;
		case 'd':
			inc(x, -y);
			break;
		case 'q':
			que(x, y);
		}
	}
	return 0;
}
 
void inc(int x, int y)
{
	for (; x <= n; x += lowbit(x))
		T[x] += y;
}
 
int sum(int x)
{
	int ans = 0;
	for (; x; x -= lowbit(x))
		ans += T[x];
	return ans;
}
 
void que(int x, int y)
{
	cout << sum(y) - sum(x - 1) << endl;
}