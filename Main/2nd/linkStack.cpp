#include <iostream>
using namespace std;

template <class T>
class linkStack
{
private:
	struct node
	{
		T data;
		node * next;
		node(const T &x, node * N = NULL) {
			data = x; next = N;
		}
		node() :next(NULL) {}
		~node() {}
	};
	node * elem;

private:
	linkStack() { elem = NULL; }
	~linkStack();

	bool isEmpty() const { return elem == NULL; }

	void push(const T & x) {
		node * T tmp = new node(x, elem);
		elem = tmp;
	}

	T pop() 
	{
		node * tmp = elem;
		T x = tmp->next;
		elem = elem->next;
		delete tmp;
		return x;
	}

	T top() const
    {
		return (elem->data;)
	}

};

template <class T>
linkStack<T>::~linkStack()
{
	node * tmp;
	while (elem != NULL) {
		tmp = elem;
		elem = elem->next;
		delete tmp;
	}
}