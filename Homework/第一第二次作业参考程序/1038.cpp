#include <iostream>
#include <cstdio>
 
using namespace std;
 
int x[10005];
int main()
{
	int n, m, k, i = 1;
	cin >> n;
	m = n;
 
	for (int j = 1; j <= m; j++)
		x[j] = 1;
 
	while (--m)
	{
		//scanf("%d", &k);
		cin >> k;
		k = (k - 1) % (m + 1) + 1;
		//cout << k << endl;
		while (k)
		{
			if (k == 1 && x[i])
			{
				x[i] = 0;
				break;
			}
			else
			{
				k -= x[i++];
				if (i == n + 1)
					i = 1;
			}
		}
	}
 
	for (int j = 1; j <= n; j++)
		if (x[j])
			cout << j << endl;
	return 0;
}