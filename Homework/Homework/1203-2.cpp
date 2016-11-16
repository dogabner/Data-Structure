#include <iostream>
using namespace std;
template <class T>
class Array;
template <class T>
ostream &operator<<(ostream &os, const Array<T> &obj);
template <class T>
Array<T> &operator+(Array<T> &arrA, Array<T> &arrB);

template <class T>
class Array
{
    friend ostream &operator<<(ostream &os, const Array<T> &obj);
    friend Array<T> &operator+(Array<T> &arrA, Array<T> &arrB);
  public:
    Array(int s = 0):size(s)
    {
        storage = new T[size];
    }

    Array(const Array &arr);
    ~Array()
    {
        delete[] storage;
    }


  private:
    int size;
    T * storage;
};

template <class T>
void envalue(T &arr, int size);

int main()
{
    char type[7];
    int length = 0;
    int sizeA, sizeB = 0;
    cin >> type;
    cin >> sizeA >> sizeB;
    for (int i = 0; type[i] != '\0'; i++)
        length += 1;
    switch (length)
    {
    case 3:
    {
        Array<int, sizeA> arrA;
        Array<int, sizeB> arrB;
        envalue(&arrA, sizeA);
        break;
    }

    default:
        break;
    }
}

template <class T>
void envalue(T &arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}