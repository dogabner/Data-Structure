#include <iostream>
using namespace std;

template<class T>
class seqStack
{
private:
	T* elem;
	int top_p;
	int maxSize;

	void doubleSpace();

public:
	seqStack(int initSize = 10) {
		elem = new T[initSize];
		maxSize = initSize; top_p = -1;

	}

	~seqStack() {
		delete[] elem;
	}

	bool isEmpty() {
		return top_p == -1;
	}

	void push(const T &x) {
		if (top_p == maxSize - 1) {
			doubleSpace();
		}
		elem[++top_p] = x;
	}

	T pop() {
		return elem[top_p--];
	}

	T top() {
		return elem[top_p];
	}
};

template <class T>
void seqStack<T>::doubleSpace()
{
	T * tmp = elem;
	elem = new T[2 * maxSize];
	for (int i = 0; i < maxSize; ++i) {
		elem[i] = tmp[i];
		maxSize *= 2;
		delete[] tmp;
	}
}