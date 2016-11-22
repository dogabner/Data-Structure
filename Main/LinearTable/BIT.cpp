#include <iostream>
using namespace std;

int MAX_N = 10;
int A[10] = {13,24,5,3,2,5,6,4,3,10};
int BIT[10];

int lowbit(int x);
void add(int idx, int x);
int query(int x);
void build()
{
	for (int i = 1; i <= MAX_N; i++)
	{
		add(i, A[i-1]);
	}
}

int lowbit(int x)
{
	return x&-x;
}

void add(int idx, int x)
{
	for (int i = idx; i <= MAX_N; i += lowbit(i))
		BIT[i-1] += x;
}

int query(int x)
{
	int res = 0;
	for (int i = x; i>0; i -= lowbit(i+1))
	{
		res += BIT[i];
	}
	return res;
}

//int main()
//{
//	build();
//	for (int i = 0; i < sizeof(BIT)/4; ++i) cout << BIT[i] << ' ';
//	cout << query(5);
//	getchar();
//	return 0;
//}