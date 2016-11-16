#include <iostream>
#include <cstdio>
 
#define REP(I, N) for(int I = 0; I < N; I++)
 
using namespace std;
 
int n, m, x[100005];
int search(int y);
int main()
{
	int y;
	cin >> n >> m;
	REP(i, n)
		scanf("%d", x + i);
	x[n] = 2100000000;
	REP(i, m)
	{
		scanf("%d", &y);
		printf("%d\n", search(y));
	}
}
 
int search(int y)
{
	int l = 0, r = n, mid;
	while (l < r)
	{
		mid = l + (r - l) / 2;
		if (x[mid] > y)
			r = mid;
		else
			l = mid + 1;
	}
	return n - l;
}