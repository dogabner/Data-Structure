#include <iostream>
#include <algorithm>
 
#define REP(I, N) for(int I = 0; I < N; I++)
#define lowbit(X) (X & -X)
 
using namespace std;
 
struct node
{
	int data, num;
}x[100005], y[100005];
int z[100005], T[100005];
int n;
 
bool cmp(node a, node b)
{
	return a.data < b.data;
}
void inc(int x, int y);
int sum(int x);
 
int main()
{
	int v;
	cin >> n;
	REP(i, n)
	{
		cin >> v;
		x[i].data = v;
		x[i].num = i + 1;
	}
	REP(i, n)
	{
		cin >> v;
		y[i].data = v;
		y[i].num = i + 1;
	}
 
	sort(x, x + n, cmp);
	sort(y, y + n, cmp);
 
	REP(i, n)
		z[x[i].num] = y[i].num;
 
	long long ans = 0;
	REP(i, n)
	{
		ans += i - sum(z[i + 1]);
		inc(z[i + 1], 1);
	}
	cout << ans % 99999997 << endl;
 
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