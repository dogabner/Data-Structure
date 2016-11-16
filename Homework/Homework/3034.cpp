#include <iostream>
#include <math.h>

using namespace std;
bool isPrimf(bool [], int);

int main() {
	int N;
	cin >> N;
	int MAX = floor(N *1.8 );

	bool * isPrime;
	isPrime = new bool[MAX];
	for (int i = 0; i < MAX; ++i)
		isPrime[i] = 0;
	isPrime[0] = 1;
	for (int i = 1; i < MAX; ++i) {
		isPrime[i] = isPrimf(isPrime, i + 2);
	}

	if (N < 2 || isPrime[N-2] == 1)
		cout << 0;
	else {
		int i = 1;
		int j = 1;
		while (true) {
			if (isPrime[N - 2 + i] == 0)
				i += 1;
			if (isPrime[N - 2 - j] == 0)
				j += 1;
			else if (isPrime[N - 2 - j] == 1 && isPrime[N - 2 + i] == 1)
				break;
		}
		cout << i + j << endl;
	}
	//for (int i = 900450; i < 900511; ++i)
	//	cout << i+2 << ':'<< isPrime[i] << endl;
	delete[] isPrime;
	return 0;
}

bool isPrimf(bool isPrime[], int currentNum) {
	int tryNum = floor(sqrt(currentNum));
	for (int i = 0; i < tryNum; ++i) {
		if (isPrime[i] == 1) {
			if (currentNum % (i + 2) == 0)
				return 0;
		}
	}
	return 1;
}