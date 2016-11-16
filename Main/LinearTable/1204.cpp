#include <iostream>
#include "List.h"
using namespace std;

class OutOfBound
{};
template <class T>
struct node {
	T data;
	node *prev, *next;
	node(const T& x, node *p = NULL, node *n = NULL) {
		data = x; prev = p; next = n;
	}
	node() :prev(NULL), next(NULL) {}
	~node() {}
};

template <class T>
class linkList
{
	//template <class U>
	//friend linkList<U> operator + (const linkList<U> & list1, const linkList<U> & list2);
	//template <class U>
	//friend istream& operater >> (istream& in, linkList<U>& list);
	//template <class U>
	//friend ostream& operater << (ostream& out, const linkList<U>& list);
private:
	node<T> *head, *tail;
	int currentLength;
	node<T> * move(int i) const;

public:
	linkList();
	linkList(const linkList<T> & list);
	~linkList() { clear(); delete head; delete tail; }
	void clear();
	int length() const { return currentLength; }
	void insert(int i, const T & x);
	void insertBefore(const T & x);
	void append(const T &x);
	void remove(int i);
	int search(const T & x) const;
	T visit(int i) const;
	void traverse()const;
	T endOfList() const { return visit(currentLength - 1); }
	node<T> * operator [](int i) const { return move(i); }
};

template <class T>
node<T> * linkList<T>::move(int i) const
{
	node<T> * p = head->next;
	if (i > currentLength || i < 0) throw OutOfBound();
	while (i--) p = p->next;
	return p;
}

template <class T>
linkList<T>::linkList()
{
	head = new node<T>;
	tail = new node<T>;
	head->next = tail;
	tail->prev = head;
	currentLength = 0;
}

template<class T>
linkList<T>::linkList(const linkList<T>& list)
{
	currentLength = list.currentLength;
	node<T> * tmp = list.head->next;
	head = new node<T>;
	tail = new node<T>;
	head->next = tail;
	tail->prev = head;
	while (tmp->next) {
		node<T> * p;
		p = new node<T>(tmp->data, tail->prev, tail);
		tail->prev->next = p;
		tail->prev = p;
		tmp = tmp->next;
	}
}

template<class T>
void linkList<T>::clear()
{
	node<T> *p = head->next, *q;
	head->next = tail;
	tail->prev = head;
	while (p != tail) {
		q = p->next;
		delete p;
		p = q;
	}
}

template<class T>
void linkList<T>::insert(int i, const T& x)
{
	node<T> * pos, *tmp;
	pos = move(i);
	tmp = new node<T>(x, pos->prev, pos);
	pos->prev->next = tmp;
	pos->prev = tmp;

	++currentLength;
}

template<class T>
void linkList<T>::insertBefore(const T & x)
{
	node<T> *tmp;
	tmp = new node<T>(x, head, head->next);
	head->next->prev = tmp;
	head->next = tmp;
	++currentLength;
}

template<class T>
void linkList<T>::append(const T & x)
{
	node<T> * tmp;
	tmp = new node<T>(x, tail->prev, tail);
	tail->prev->next = tmp;
	tail->prev = tmp;
	++currentLength;
}


template<class T>
void linkList<T>::remove(int i)
{
	node<T> *pos;
	pos = move(i);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	delete pos;
	--currentLength;
}

template<class T>
int linkList<T>::search(const T& x) const
{
	node<T> *p = head->next;
	int i = 0;
	while (true) {
		if (p->next == NULL) return -1;
		else if (p->data == x) {
			return i;
		}
		++i;
	}
}

template<class T>
T linkList<T>::visit(int i)const
{
	node<T> * pos;
	pos = move(i);
	return(pos->data);
}

template<class T>
void linkList<T>::traverse() const
{
	node<T> *pos = head->next;
	while (pos != tail) {
		cout << pos->data;
		pos = pos->next;
	}
}
