#include <iostream>
using namespace std;


inline int abs(int num)
{
	return ((num > 0) ? num : -num);
}

int sum(int x, int N, int * place)
{
	int result = 0;

	for (int i = 0; i < N; ++i) {
		result += abs(place[i] - x);
	}

	return result;
}



int main()
{
	int N;
	cin >> N;
	int * place;
	place = new int[N];
	for (int i = 0; i < N; ++i) cin >> place[i];


	
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