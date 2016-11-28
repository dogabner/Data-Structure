#include <iostream>
using namespace std;

void qsort(int* a, int l, int r)
{
	if (l >= r) return;
	int i = l, j = r, k = a[l];
	while (i<j)
	{
		while ((i<j) && (a[j] >= k)) --j;
		a[i] = a[j];
		while ((i<j) && (a[i] <= k)) ++i;
		a[j] = a[i];
	}
	a[i] = k;
	qsort(a, l, i - 1);
	qsort(a, i + 1, r);
}

int main()
{
	int N;
	cin >> N;
	int * place;
	place = new int[N];
	unsigned int sum = 0;
	for (int i = 0; i < N; ++i) cin >> place[i];
	qsort(place, 0, N - 1);
	int t = N / 2;
	for (int i = 0; i < t; ++i) {
		sum += place[N - i - 1] - place[i];
	}
	cout << sum;

	
	return 0;
}

//inline int Abs_bit(int iNum)
//{
//#ifdef USE_ASM
//	int iOut = 0;
//	__asm
//	{
//		MOV EAX, iNum;
//		MOV EDX, EAX;
//		SAR EDX, 31;   //all of edx's bit are eax's sign bit: 000.. or 111
//		XOR EAX, EDX; //this interesting algorithm help to avoid "if else" structure
//		SUB EAX, EDX;
//		MOV iOut, EAX;
//	}
//	return iOut;
//#else
//
//	int out = iNum;
//	int temp = iNum;
//	temp = temp >> 31;
//
//	out = out ^ temp;
//	out = out - temp;
//
//	return out;
//
//#endif
//}