#include <iostream>
//#include "List.h"
using namespace std;
template <class T>
class list
{
public:
	virtual void clear() = 0;
	virtual int length() const = 0;
	virtual void insert(int i, const T &x) = 0;
	virtual void remove(int i) = 0;
	virtual int search(const T &x)const = 0;
	virtual T visit(int i)const = 0;
	virtual void traverse()const = 0;
	//    virtual void reverse() = 0;
	virtual ~list() {};
};

class OutOfBound{};
class IllegalSize{};

template <class T>
class seqList:public list <T>
{
public:
	template <class U>
	friend seqList<U> operator+ (const seqList<U> &seq1, const seqList<U> &seq2);
	template <class U>
	friend istream& operator>> (istream& in, seqList<U>& list);
	template <class U>
	friend ostream& operator<< (ostream& out, const seqList<U>& list);

    seqList(int initSize = 10);
	seqList(const seqList<T> &);
    ~seqList() { delete[] data; }
    void clear() { currentLength = 0; }
    int length() const { return currentLength; }
	int size() const { return maxSize; }
    void insert(int i, const T &x);
    void remove(int i);
    int search(const T &x) const;
    T visit(int i)const;
    void traverse()const;
    void reverse();
	T& operator [](int i) const;
	seqList<T> & operator =(const seqList<T> &seq );

private:
    T * data;
    int currentLength;
    int maxSize;
    void doubleSpace();
};

template <class T>
seqList<T>::seqList(int initSize)
{
    if (initSize < 0) throw IllegalSize();
    data = new T[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class T>
seqList<T>::seqList(const seqList<T> &list)
{	
	//cout << "copy constructor" << endl;
	data = new T[list.maxSize];
	maxSize = list.maxSize;
	currentLength = list.currentLength;
	for (int i = 0; i < list.currentLength; ++i) data[i] = list[i];
}

template <class T>
seqList<T> & seqList<T>::operator =(const seqList<T> &seq)
{
    cout << "call +" << endl;
	if (this == &seq) return *this;
	delete[] data;
	data = new T[seq.maxSize];
    //currentLength = seq.currentLength;
    currentLength = 1;
	maxSize = seq.maxSize;
	for (int i = 0; i < seq.currentLength; ++i) data[i] = 123;

	return *this;
}

template <class T>
void seqList<T>::doubleSpace() 
{
    T * tmp = data;
    maxSize *= 2;
    data = new T[maxSize];
    for (int i = 0; i < currentLength; ++i) data[i] = tmp[i];
    delete[] tmp;
}

template <class T>
void seqList<T>::insert(int i, const T &x)
{
    if (i<0 || i> currentLength) throw OutOfBound();
    if (currentLength == maxSize) doubleSpace();
    for (int j = currentLength; j>i; --j) data[j] = data[j-1];
    data[i] = x;
    ++currentLength;
}

template <class T>
void seqList<T>::remove(int i)
{
    if (i<0 || i> currentLength) throw OutOfBound();
    for(int j = i; j> currentLength-1; ++j) data[j] = data[j+1];
    --currentLength;
}

template <class T>
int seqList<T>::search(const T& x) const
{
    for (int i = 0; i < currentLength&&data[i]!=x; ++i) {
        if (i == currentLength) return -1; else return i;
    }
}

template <class T>
T seqList<T>::visit(int i)const
{
    if (i<0 || i> currentLength) throw OutOfBound();
    return data[i];
}

template <class T>
void seqList<T>::traverse() const
{
    for (int i = 0; i < currentLength; ++i) cout << data[i] << ' ';
    cout << endl;
}

template <class T>
void seqList<T>::reverse()
{
    for (int i = 0; i < currentLength/2-1; ++i) {
        T tmp = data[i];
        data[i] = data[currentLength - i-1];
        data[currentLength - i-1] = tmp;
    }

}

template<class T>
T& seqList<T>::operator[](int i) const
{
	if (i > maxSize || i < 0) throw OutOfBound();
	return data[i];
}

template <class T>
seqList<T> operator+ (const seqList<T> &seq1, const seqList<T> &seq2)
{
	int newLength = seq1.currentLength + seq2.currentLength;

	seqList<T> newSeq(seq1.maxSize + seq2.maxSize);

	newSeq.currentLength = newLength;
	for (int i = 0; i < seq1.currentLength; ++i) {
		newSeq[i] = seq1[i];
	}
	for (int j = seq1.currentLength; j < newLength; ++j) {
        newSeq[j] = seq2[j-seq1.currentLength];
	}

	return newSeq;
}

template<class T>
istream& operator >> (istream& in, seqList<T>& seq)
{
	for (int i = 0; i < seq.maxSize; ++i)
	{
		in >> seq[i]; seq.currentLength += 1;
	}
	return in;
}

template<class T>
ostream& operator << (ostream& out, const seqList<T>& seq)
{
	for (int i = 0; i < seq.maxSize; ++i) out << seq[i] << ' ';
	return out;
}

// for 1203
/**
int main()
{
	char typ[10];
	int len1, len2;
	cin >> typ;
	cin >> len1 >> len2;

	switch (typ[0])
	{
	case 'i':
	{
		seqList<int> seq1(len1), seq2(len2);
		cin >> seq1 >> seq2;
		cout << seq1 + seq2;
		break; 
	}
	case 'c': {
		seqList<char> seq1(len1), seq2(len2);
		cin >> seq1 >> seq2;
		cout << seq1 + seq2;
		break;
	}
	case 'd': {
		seqList<double> seq1(len1), seq2(len2);
		cin >> seq1 >> seq2;
		cout << seq1 + seq2;
		break;
	}
	default:
		break;
	}
	return 0;
}
*/